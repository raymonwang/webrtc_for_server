//
//  audio_device_rtchat_linux.cpp
//  audio_device
//
//  Created by reechat studio on 16/7/19.
//  Copyright © 2016年 reechat studio. All rights reserved.
//

#include "audio_device_rtchat_linux.h"
#include "webrtc/base/platform_thread.h"
#include "webrtc/base/timeutils.h"
#include <webrtc/base/logging.h>
#include "webrtc/system_wrappers/include/event_wrapper.h"
#include "webrtc/system_wrappers/include/sleep.h"
#include "webrtc/system_wrappers/include/trace.h"

namespace webrtc {
    int kRecordingFixedSampleRate = 48000;
    int kRecordingNumChannels = 2;
    int kPlayoutFixedSampleRate = 48000;
    int kPlayoutNumChannels = 2;
    int kPlayoutBufferSize = kPlayoutFixedSampleRate / 100
    * kPlayoutNumChannels * 2;
    int kRecordingBufferSize = kRecordingFixedSampleRate / 100
    * kRecordingNumChannels * 2;
    
    AudioDeviceLinuxRtchat::AudioDeviceLinuxRtchat(const int32_t id):
    _ptrAudioBuffer(NULL),
    _recordingFramesLeft(0),
    _playoutFramesLeft(0),
    _recordingBufferSizeIn10MS(0),
    _recordingFramesIn10MS(0),
    _playoutFramesIn10MS(0),
    _ptrThreadProcess(NULL),
    _playing(false),
    _recording(false),
    _lastCallPlayoutMillis(0),
    _lastCallRecordMillis(0),
    _initialized(false),
    _recIsInitialized(false),
    _recBuffer(NULL)
    {
        
    }
    
    AudioDeviceLinuxRtchat::~AudioDeviceLinuxRtchat()
    {
        if (_ptrThreadProcess) {
            _ptrThreadProcess->Stop();
            delete _ptrThreadProcess;
        }
        if (_recBuffer)
        {
            delete [] _recBuffer;
            _recBuffer = NULL;
        }
    }
    
    int32_t AudioDeviceLinuxRtchat::ActiveAudioLayer(
                                              AudioDeviceModule::AudioLayer& audioLayer) const {
        return -1;
    }
    
    AudioDeviceGeneric::InitStatus AudioDeviceLinuxRtchat::Init()
    {
        rtc::CritScope lock(&_critSect);
        
        if (_initialized)
        {
            return InitStatus::OK;
        }

        _ptrThreadProcess = new rtc::PlatformThread(ProcessThreadFunc, this, "webrtc_audio_module_process_thread");
        if (_ptrThreadProcess == NULL)
        {
            _playing = false;
            _recording = false;
            return InitStatus::OTHER_ERROR;
        }
        
        _initialized = true;
        
        return InitStatus::OK;
    }
    
    int32_t AudioDeviceLinuxRtchat::Terminate() { return 0; }
    
    bool AudioDeviceLinuxRtchat::Initialized() const { return true; }
    
    int16_t AudioDeviceLinuxRtchat::PlayoutDevices() {
        return 1;
    }
    
    int16_t AudioDeviceLinuxRtchat::RecordingDevices() {
        return 1;
    }
    
    int32_t AudioDeviceLinuxRtchat::PlayoutDeviceName(uint16_t index,
                                               char name[kAdmMaxDeviceNameSize],
                                               char guid[kAdmMaxGuidSize]) {
        const char* kName = "dummy_device";
        const char* kGuid = "dummy_device_unique_id";
        if (index < 1) {
            memset(name, 0, kAdmMaxDeviceNameSize);
            memset(guid, 0, kAdmMaxGuidSize);
            memcpy(name, kName, strlen(kName));
            memcpy(guid, kGuid, strlen(guid));
            return 0;
        }
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::RecordingDeviceName(uint16_t index,
                                                 char name[kAdmMaxDeviceNameSize],
                                                 char guid[kAdmMaxGuidSize]) {
        const char* kName = "dummy_device";
        const char* kGuid = "dummy_device_unique_id";
        if (index < 1) {
            memset(name, 0, kAdmMaxDeviceNameSize);
            memset(guid, 0, kAdmMaxGuidSize);
            memcpy(name, kName, strlen(kName));
            memcpy(guid, kGuid, strlen(guid));
            return 0;
        }
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::SetPlayoutDevice(uint16_t index) {
        if (index == 0) {
            _playout_index = index;
            return 0;
        }
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::SetPlayoutDevice(
                                              AudioDeviceModule::WindowsDeviceType device) {
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::SetRecordingDevice(uint16_t index) {
        if (index == 0) {
            _record_index = index;
            return _record_index;
        }
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::SetRecordingDevice(
                                                AudioDeviceModule::WindowsDeviceType device) {
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::PlayoutIsAvailable(bool& available) {
        if (_playout_index == 0) {
            available = true;
            return _playout_index;
        }
        available = false;
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::InitPlayout()
    {
        return 0;
    }
    
    bool AudioDeviceLinuxRtchat::PlayoutIsInitialized() const {
        return true;
    }
    
    int32_t AudioDeviceLinuxRtchat::RecordingIsAvailable(bool& available) {
        if (_record_index == 0) {
            available = true;
            return _record_index;
        }
        available = false;
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::InitRecording() {
        RTC_DCHECK(thread_checker_.CalledOnValidThread());
        
        rtc::CritScope lock(&_critSect);
        
        if (_recording) {
            return -1;
        }
        
        _recordingFramesIn10MS = kRecordingFixedSampleRate/100;
        
        if (!_recBuffer) {
            _recBuffer = new int8_t[kRecordingBufferSize];
        }
        
        if (_ptrAudioBuffer) {
            _ptrAudioBuffer->SetRecordingSampleRate(kRecordingFixedSampleRate);
            _ptrAudioBuffer->SetRecordingChannels(kRecordingNumChannels);
        }
        
        _recIsInitialized = true;
        return 0;
    }
    
    bool AudioDeviceLinuxRtchat::RecordingIsInitialized() const {
        return _recIsInitialized;
    }
    
    int32_t AudioDeviceLinuxRtchat::StartPlayout() {
        rtc::CritScope lock(&_critSect);
        if (_playing)
        {
            return 0;
        }
        
        _playing = true;
        _playoutFramesLeft = 0;
        _playoutFramesIn10MS = kPlayoutFixedSampleRate/100;
        
        return 0;
    }
    
    int32_t AudioDeviceLinuxRtchat::StopPlayout() {
        rtc::CritScope lock(&_critSect);
        
        _playing = false;
        _playoutFramesLeft = 0;
        return 0;
    }
    
    bool AudioDeviceLinuxRtchat::Playing() const {
        rtc::CritScope lock(&_critSect);
        return (_playing);
    }
    
    int32_t AudioDeviceLinuxRtchat::StartRecording() {
        RTC_DCHECK(thread_checker_.CalledOnValidThread());
        
        rtc::CritScope lock(&_critSect);
        _ptrThreadProcess->Start();
        if (!_ptrThreadProcess->SetPriority(rtc::kRealtimePriority)) {
            LOG(LS_WARNING) << "set LinuxRtchat process thread to kRealtimePriority failed";
        }
        _recording = true;
        
        // Make sure we only create the buffer once.
        _recordingBufferSizeIn10MS = _recordingFramesIn10MS * kRecordingNumChannels * 2;
        
        return 0;
    }
    
    
    int32_t AudioDeviceLinuxRtchat::StopRecording() {
        RTC_DCHECK(thread_checker_.CalledOnValidThread());
        rtc::CritScope lock(&_critSect);
        
        if (_ptrThreadProcess && _ptrThreadProcess->IsRunning()) {
            _ptrThreadProcess->Stop();
        }
        
        _recording = false;
        _recordingFramesLeft = 0;
        
        if (_recBuffer)
        {
            delete [] _recBuffer;
            _recBuffer = NULL;
        }
        
        _recIsInitialized = false;

        return 0;
    }
    
    bool AudioDeviceLinuxRtchat::Recording() const {
        return _recording;
    }
    
    int32_t AudioDeviceLinuxRtchat::SetAGC(bool enable) { return -1; }
    
    bool AudioDeviceLinuxRtchat::AGC() const { return false; }
    
    int32_t AudioDeviceLinuxRtchat::SetWaveOutVolume(uint16_t volumeLeft,
                                              uint16_t volumeRight) {
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::WaveOutVolume(uint16_t& volumeLeft,
                                           uint16_t& volumeRight) const {
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::InitSpeaker() { return -1; }
    
    bool AudioDeviceLinuxRtchat::SpeakerIsInitialized() const { return false; }
    
    int32_t AudioDeviceLinuxRtchat::InitMicrophone() { return 0; }
    
    bool AudioDeviceLinuxRtchat::MicrophoneIsInitialized() const { return true; }
    
    int32_t AudioDeviceLinuxRtchat::SpeakerVolumeIsAvailable(bool& available) {
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::SetSpeakerVolume(uint32_t volume) { return -1; }
    
    int32_t AudioDeviceLinuxRtchat::SpeakerVolume(uint32_t& volume) const { return -1; }
    
    int32_t AudioDeviceLinuxRtchat::MaxSpeakerVolume(uint32_t& maxVolume) const {
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::MinSpeakerVolume(uint32_t& minVolume) const {
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::SpeakerVolumeStepSize(uint16_t& stepSize) const {
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::MicrophoneVolumeIsAvailable(bool& available) {
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::SetMicrophoneVolume(uint32_t volume) { return -1; }
    
    int32_t AudioDeviceLinuxRtchat::MicrophoneVolume(uint32_t& volume) const {
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::MaxMicrophoneVolume(uint32_t& maxVolume) const {
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::MinMicrophoneVolume(uint32_t& minVolume) const {
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::MicrophoneVolumeStepSize(uint16_t& stepSize) const {
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::SpeakerMuteIsAvailable(bool& available) { return -1; }
    
    int32_t AudioDeviceLinuxRtchat::SetSpeakerMute(bool enable) { return -1; }
    
    int32_t AudioDeviceLinuxRtchat::SpeakerMute(bool& enabled) const { return -1; }
    
    int32_t AudioDeviceLinuxRtchat::MicrophoneMuteIsAvailable(bool& available) {
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::SetMicrophoneMute(bool enable) { return -1; }
    
    int32_t AudioDeviceLinuxRtchat::MicrophoneMute(bool& enabled) const { return -1; }
    
    int32_t AudioDeviceLinuxRtchat::MicrophoneBoostIsAvailable(bool& available) {
        return -1;
    }
    
    int32_t AudioDeviceLinuxRtchat::SetMicrophoneBoost(bool enable) { return -1; }
    
    int32_t AudioDeviceLinuxRtchat::MicrophoneBoost(bool& enabled) const { return -1; }
    
    int32_t AudioDeviceLinuxRtchat::StereoPlayoutIsAvailable(bool& available) {
        available = true;
        return 0;
    }
    int32_t AudioDeviceLinuxRtchat::SetStereoPlayout(bool enable) {
        return 0;
    }
    
    int32_t AudioDeviceLinuxRtchat::StereoPlayout(bool& enabled) const {
        enabled = true;
        return 0;
    }
    
    int32_t AudioDeviceLinuxRtchat::StereoRecordingIsAvailable(bool& available) {
        available = true;
        return 0;
    }
    
    int32_t AudioDeviceLinuxRtchat::SetStereoRecording(bool enable) {
        return 0;
    }
    
    int32_t AudioDeviceLinuxRtchat::StereoRecording(bool& enabled) const {
        enabled = true;
        return 0;
    }
    
    int32_t AudioDeviceLinuxRtchat::SetPlayoutBuffer(
                                              const AudioDeviceModule::BufferType type,
                                              uint16_t sizeMS) {
        return 0;
    }
    
    int32_t AudioDeviceLinuxRtchat::PlayoutBuffer(AudioDeviceModule::BufferType& type,
                                           uint16_t& sizeMS) const {
        type = _playBufType;
        return 0;
    }
    
    int32_t AudioDeviceLinuxRtchat::PlayoutDelay(uint16_t& delayMS) const {
        return 0;
    }
    
    int32_t AudioDeviceLinuxRtchat::RecordingDelay(uint16_t& delayMS) const { return -1; }
    
    int32_t AudioDeviceLinuxRtchat::CPULoad(uint16_t& load) const { return -1; }
    
    bool AudioDeviceLinuxRtchat::PlayoutWarning() const { return false; }
    
    bool AudioDeviceLinuxRtchat::PlayoutError() const { return false; }
    
    bool AudioDeviceLinuxRtchat::RecordingWarning() const { return false; }
    
    bool AudioDeviceLinuxRtchat::RecordingError() const { return false; }
    
    void AudioDeviceLinuxRtchat::ClearPlayoutWarning() {}
    
    void AudioDeviceLinuxRtchat::ClearPlayoutError() {}
    
    void AudioDeviceLinuxRtchat::ClearRecordingWarning() {}
    
    void AudioDeviceLinuxRtchat::ClearRecordingError() {}
    
    void AudioDeviceLinuxRtchat::AttachAudioBuffer(AudioDeviceBuffer* audioBuffer)
    {
        rtc::CritScope lock(&_critSect);
        
        _ptrAudioBuffer = audioBuffer;
        
        // Inform the AudioBuffer about default settings for this implementation.
        // Set all values to zero here since the actual settings will be done by
        // InitPlayout and InitRecording later.
        _ptrAudioBuffer->SetRecordingSampleRate(0);
        _ptrAudioBuffer->SetPlayoutSampleRate(0);
        _ptrAudioBuffer->SetRecordingChannels(0);
        _ptrAudioBuffer->SetPlayoutChannels(0);
    }
    
    bool AudioDeviceLinuxRtchat::ProcessThreadFunc(void* pThis)
    {
        return static_cast<AudioDeviceLinuxRtchat*>(pThis)->PlayRecThreadFunc();
    }
    
    bool AudioDeviceLinuxRtchat::PlayRecThreadFunc()
    {
        int64_t currentTime = rtc::TimeMillis();
        
//        _ptrAudioBuffer->SetRecordedBuffer(_recBuffer, _recordingFramesIn10MS);
        _ptrAudioBuffer->DeliverRecordedData();
        
        int64_t deltaTimeMillis = rtc::TimeMillis() - currentTime;
        int64_t idletime = 40 - deltaTimeMillis;
        if (idletime > 0) {
            SleepMs(idletime);
        }
        
        return true;
    }
}

