PROJECT(webrtc_for_server)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)



########
file(GLOB_RECURSE audio_mixer "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/audio_mixer/*.cc")
list(FILTER audio_mixer EXCLUDE REGEX ".*test")
list(FILTER audio_mixer EXCLUDE REGEX ".*win")

file(GLOB_RECURSE bitrate_controller "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/bitrate_controller/*.cc")
list(FILTER bitrate_controller EXCLUDE REGEX ".*test")

file(GLOB_RECURSE congestion_controller "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/congestion_controller/*.cc")
list(FILTER congestion_controller EXCLUDE REGEX ".*test")

file(GLOB_RECURSE paced_sender "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/pacing/*.cc")
list(FILTER paced_sender EXCLUDE REGEX ".*test")

########

########

file(GLOB_RECURSE rtc_audio "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/audio/*.cc")
list(FILTER rtc_audio EXCLUDE REGEX ".*test")

file(GLOB_RECURSE rtc_video "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/video/*.cc")
list(FILTER rtc_video EXCLUDE REGEX ".*test")
list(FILTER rtc_video EXCLUDE REGEX ".*loopback")
list(FILTER rtc_video EXCLUDE REGEX "replay.cc")
list(FILTER rtc_video EXCLUDE REGEX ".*analyzer")


file(GLOB_RECURSE rtc_call "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/call/*.cc")
list(FILTER rtc_call EXCLUDE REGEX ".*test")

file(GLOB_RECURSE rtc_event_log "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/logging/*.cc")
list(FILTER rtc_event_log EXCLUDE REGEX ".*test")
list(FILTER rtc_event_log EXCLUDE REGEX ".*mock")
list(FILTER rtc_event_log EXCLUDE REGEX ".*dump")
list(FILTER rtc_event_log EXCLUDE REGEX ".*log2")
list(FILTER rtc_event_log EXCLUDE REGEX ".*parser")

file(GLOB_RECURSE rtc_media "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/media/*.cc")
list(FILTER rtc_media EXCLUDE REGEX ".*test")
list(FILTER rtc_media EXCLUDE REGEX ".*fake")
list(FILTER rtc_media EXCLUDE REGEX ".*sctptransport.cc")

file(GLOB_RECURSE rtc_stats "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/stats/*.cc")
list(FILTER rtc_stats EXCLUDE REGEX ".*test")

if(APPLE)
  add_definitions(-DWEBRTC_POSIX -DWEBRTC_MAC)
elseif(UNIX)
  add_definitions(-DWEBRTC_POSIX -DWEBRTC_LINUX)
endif()
add_definitions(-DWEBRTC_BUILD_LIBEVENT -DWEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE -DWEBRTC_APM_DEBUG_DUMP=0 -DWEBRTC_NS_FIXED -DWEBRTC_INTELLIGIBILITY_ENHANCER=0 -DJSON_USE_EXCEPTION=0)
add_definitions(-DWEBRTC_CODEC_OPUS -DWEBRTC_CODEC_ILBC -DWEBRTC_CODEC_RED -DWEBRTC_CODEC_ISACFX)
add_definitions(-DOPUS_BUILD -DOPUS_EXPORT= -DOPUS_FIXED_POINT -DHAVE_LRINT -DHAVE_LRINTF -DVAR_ARRAYS -DFIXED_POINT -D__OPTIMIZE__)

add_library(audio_mixer STATIC ${audio_mixer})
add_library(bitrate_controller STATIC ${bitrate_controller})
add_library(congestion_controller STATIC ${congestion_controller})
add_library(paced_sender STATIC ${paced_sender})

add_library(rtc_audio STATIC ${rtc_audio})
add_library(rtc_video STATIC ${rtc_video})
add_library(rtc_call STATIC ${rtc_call})
add_library(rtc_event_log STATIC ${rtc_event_log})
add_library(rtc_media STATIC ${rtc_media})

add_library(rtc_stats STATIC ${rtc_stats})

###################################
file(GLOB_RECURSE rtc_pc "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/pc/srtpfilter.cc")

add_library(rtc_pc STATIC ${rtc_pc})

target_compile_options(rtc_pc PRIVATE -std=gnu++11)

target_include_directories(rtc_pc PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/abseil-cpp
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/libsrtp/include
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/libsrtp/config
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/libsrtp/crypto/include
)

target_compile_definitions(rtc_pc PRIVATE 
	-DHAVE_SRTP 
	-DHAVE_NETINET_IN_H
)
###################################
file(GLOB_RECURSE rtc_p2p "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/p2p/*.cc")
list(FILTER rtc_p2p EXCLUDE REGEX ".*test")
list(FILTER rtc_p2p EXCLUDE REGEX ".*fake")
list(FILTER rtc_p2p EXCLUDE REGEX ".*quic")

add_library(rtc_p2p STATIC ${rtc_p2p})

target_include_directories(rtc_p2p BEFORE PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes)

target_compile_options(rtc_p2p PRIVATE -std=gnu++11)

target_compile_definitions(rtc_p2p PRIVATE -DWEBRTC_POSIX -DDEBUG)

###################################
file(GLOB_RECURSE srtp "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/libsrtp/*.c")
list(FILTER srtp EXCLUDE REGEX ".*test")

add_library(srtp STATIC ${srtp})

target_include_directories(srtp PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/libsrtp/config
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/libsrtp/include
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/libsrtp/crypto/include
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/boringssl/src/include
)
target_compile_definitions(srtp PRIVATE  
	-DPACKAGE_STRING=\"2.1.0-pre\"
	-DPACKAGE_VERSION=\"2.1.0-pre\" 
	-DOPENSSL
	-DHAVE_CONFIG_H
	-DHAVE_STDLIB_H
    -DHAVE_STRING_H
    -DHAVE_STDINT_H
    -DHAVE_INTTYPES_H
    -DHAVE_INT16_T
    -DHAVE_INT32_T
    -DHAVE_INT8_T
    -DHAVE_UINT16_T
    -DHAVE_UINT32_T
    -DHAVE_UINT64_T
    -DHAVE_UINT8_T
	-DHAVE_ARPA_INET_H
    -DHAVE_NETINET_IN_H
    -DHAVE_SYS_TYPES_H
    -DHAVE_UNISTD_H
)
###################################
file(GLOB_RECURSE voice_engine "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/voice_engine/*.cc")
list(FILTER voice_engine EXCLUDE REGEX ".*test")
list(FILTER voice_engine EXCLUDE REGEX ".*win")
list(FILTER voice_engine EXCLUDE REGEX "voice_engine_fixture.cc")

add_library(voice_engine STATIC ${voice_engine})

target_compile_options(voice_engine PRIVATE -std=gnu++11)
###################################
file(GLOB_RECURSE common_audio "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/common_audio/*.cc" "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/common_audio/*.c")
list(FILTER common_audio EXCLUDE REGEX ".*test")
list(FILTER common_audio EXCLUDE REGEX ".*neon")
list(FILTER common_audio EXCLUDE REGEX ".*mips")
list(FILTER common_audio EXCLUDE REGEX "real_fourier_openmax.cc")

add_library(common_audio STATIC ${common_audio})

target_compile_features(common_audio PRIVATE cxx_std_11)
###################################
add_library(webrtc_common STATIC 
	"${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/common_types.cc"
	"${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/config.cc"
)

target_compile_features(webrtc_common PRIVATE cxx_std_11)
###################################
file(GLOB_RECURSE media_file "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/media_file/*.cc")
list(FILTER media_file EXCLUDE REGEX ".*test")

add_library(media_file STATIC ${media_file})

target_compile_features(media_file PRIVATE cxx_std_11)
###################################
file(GLOB_RECURSE audio_coding "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/audio_coding/*.cc" "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/audio_coding/*.c")
list(FILTER audio_coding EXCLUDE REGEX ".*test")
list(FILTER audio_coding EXCLUDE REGEX ".*win")
list(FILTER audio_coding EXCLUDE REGEX ".*tools")
list(FILTER audio_coding EXCLUDE REGEX ".*mock")
list(FILTER audio_coding EXCLUDE REGEX ".*mips")
list(FILTER audio_coding EXCLUDE REGEX ".*neon")

add_library(audio_coding STATIC 
	${audio_coding} 
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/audio_coding/codecs/ilbc/window32_w32.c
)

target_include_directories(audio_coding BEFORE PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/opus/src/include
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/audio_coding/codecs/isac/main/include
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/common_audio/signal_processing/include
)

target_compile_features(audio_coding PRIVATE cxx_std_11)
###################################
file(GLOB_RECURSE opus "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/opus/*.c")
list(FILTER opus EXCLUDE REGEX ".*test")
list(FILTER opus EXCLUDE REGEX ".*arm")
list(FILTER opus EXCLUDE REGEX ".*neon")
list(FILTER opus EXCLUDE REGEX ".*float")
list(FILTER opus EXCLUDE REGEX ".*x86")

add_library(opus STATIC ${opus})

target_include_directories(opus PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/opus/src/include
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/opus/src/celt
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/opus/src/silk
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/opus/src/silk/fixed
)

###################################
file(GLOB_RECURSE audio_processing 
	"${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/audio_processing/*.cc" 
	"${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/audio_processing/*.c"
)
list(FILTER audio_processing EXCLUDE REGEX ".*test")
list(FILTER audio_processing EXCLUDE REGEX ".*win")
list(FILTER audio_processing EXCLUDE REGEX ".*mips")
list(FILTER audio_processing EXCLUDE REGEX ".*neon")
list(FILTER audio_processing EXCLUDE REGEX ".*mock")
list(FILTER audio_processing EXCLUDE REGEX ".*aec_dump")

add_library(audio_processing STATIC ${audio_processing})

target_compile_features(audio_processing PRIVATE cxx_std_11)
###################################
file(GLOB_RECURSE system_wrappers "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/system_wrappers/*.cc")
list(FILTER system_wrappers EXCLUDE REGEX ".*test")
list(FILTER system_wrappers EXCLUDE REGEX ".*_win")
list(FILTER system_wrappers EXCLUDE REGEX ".*logcat")
list(FILTER system_wrappers EXCLUDE REGEX ".*darwin")
if(APPLE)
  list(APPEND system_wrappers "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/system_wrappers/source/atomic32_darwin.cc")
elseif(UNIX)
  list(APPEND system_wrappers "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/system_wrappers/source/atomic32_non_darwin_unix.cc")
endif()

add_library(system_wrappers STATIC ${system_wrappers})

target_compile_features(system_wrappers PRIVATE cxx_std_11)
###################################
file(GLOB_RECURSE audio_conference_mixer "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/audio_conference_mixer/*.cc")
list(FILTER audio_conference_mixer EXCLUDE REGEX ".*test")

add_library(audio_conference_mixer STATIC ${audio_conference_mixer})

target_compile_features(audio_conference_mixer PRIVATE cxx_std_11)
###################################
file(GLOB_RECURSE rtp_rtcp "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/rtp_rtcp/*.cc")
list(FILTER rtp_rtcp EXCLUDE REGEX ".*test")
list(FILTER rtp_rtcp EXCLUDE REGEX ".*mock")

add_library(rtp_rtcp STATIC ${rtp_rtcp})

target_compile_features(rtp_rtcp PRIVATE cxx_std_11)
###################################
file(GLOB_RECURSE rtc_utility "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/utility/*.cc")
list(FILTER rtc_utility EXCLUDE REGEX ".*test")
list(FILTER rtc_utility EXCLUDE REGEX ".*android")

add_library(rtc_utility STATIC ${rtc_utility})

target_compile_features(rtc_utility PRIVATE cxx_std_11)
###################################
file(GLOB_RECURSE common_video "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/common_video/*.cc")
list(FILTER common_video EXCLUDE REGEX ".*test")
list(FILTER common_video EXCLUDE REGEX ".*win")
list(FILTER common_video EXCLUDE REGEX ".*neon")
if(UNIX)
  list(FILTER common_video EXCLUDE REGEX "corevideo_frame_buffer.cc")
endif()

add_library(common_video STATIC ${common_video})

target_include_directories(common_video PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/libyuv/include")

target_compile_features(common_video PRIVATE cxx_std_11)
###################################
file(GLOB_RECURSE yuv "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/libyuv/*.cc")
list(FILTER yuv EXCLUDE REGEX ".*test")

add_library(yuv STATIC ${yuv})

target_include_directories(yuv PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/libyuv/include")
###################################
file(GLOB_RECURSE audio_device "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/audio_device/*.cc" "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/audio_device/*.c")
list(FILTER audio_device EXCLUDE REGEX ".*test")
list(FILTER audio_device EXCLUDE REGEX ".*win")
list(FILTER audio_device EXCLUDE REGEX ".*android")
list(FILTER audio_device EXCLUDE REGEX ".*alsa")
list(FILTER audio_device EXCLUDE REGEX ".*pulse")
list(FILTER audio_device EXCLUDE REGEX ".*latebinding")
list(FILTER audio_device EXCLUDE REGEX "audio_device_factory.cc")
if(APPLE)
elseif(UNIX)
  list(FILTER audio_device EXCLUDE REGEX ".*mac")
endif()

add_library(audio_device STATIC ${audio_device})

target_compile_definitions(audio_device PRIVATE -DWEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE -DRTCHAT_SERVER)

target_include_directories(audio_device PRIVATE 
	"${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/audio_device/linux"
	"${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/audio_device/mac"
)

target_compile_features(audio_device PRIVATE cxx_std_11)
###################################
file(GLOB_RECURSE rtc_api "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/api/*.cc")
list(FILTER rtc_api EXCLUDE REGEX ".*test")
list(FILTER rtc_api EXCLUDE REGEX ".*win")

add_library(rtc_api STATIC ${rtc_api})

target_include_directories(rtc_api PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/libyuv/include")

target_compile_definitions(rtc_api PRIVATE 
	-DWEBRTC_USE_BUILTIN_ISAC_FIX
	-DWEBRTC_USE_BUILTIN_OPUS 
	-DWEBRTC_OPUS_VARIABLE_COMPLEXITY=1 
)

target_compile_features(rtc_api PRIVATE cxx_std_11)
###################################
file(GLOB_RECURSE video_coding "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/video_coding/*.cc")
list(FILTER video_coding EXCLUDE REGEX ".*test")
list(FILTER video_coding EXCLUDE REGEX ".*tools")
list(FILTER video_coding EXCLUDE REGEX "vp8_sequence_coder.cc")

add_library(video_coding STATIC ${video_coding})

target_compile_definitions(video_coding PRIVATE 
	-DRTC_DISABLE_VP9
	-DWEBRTC_USE_H264
)

target_include_directories(video_coding BEFORE PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/libvpx/source/libvpx
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/ffmpeg
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/ffmpeg/chromium/config/Chrome/mac/x64
	${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/third_party/libyuv/include
)

target_compile_features(video_coding PRIVATE cxx_std_11)
###################################
file(GLOB_RECURSE remote_bitrate_estimator "${CMAKE_CURRENT_SOURCE_DIR}/webRTCAPP/Classes/webrtc/modules/remote_bitrate_estimator/*.cc")
list(FILTER remote_bitrate_estimator EXCLUDE REGEX ".*test")
list(FILTER remote_bitrate_estimator EXCLUDE REGEX ".*tools")
list(FILTER remote_bitrate_estimator EXCLUDE REGEX "bwe_simulations.cc")

add_library(remote_bitrate_estimator STATIC ${remote_bitrate_estimator})

target_compile_features(remote_bitrate_estimator PRIVATE cxx_std_11)
###################################

target_compile_options(
	bitrate_controller PRIVATE -std=gnu++11
)

target_compile_options(
	rtc_media PRIVATE -std=gnu++11
)

target_compile_options(
	rtc_event_log PRIVATE -std=gnu++11
)

target_compile_options(
	paced_sender PRIVATE -std=gnu++11
)

target_compile_options(
	rtc_call PRIVATE -std=gnu++11
)

target_compile_options(
	rtc_video PRIVATE -std=gnu++11
)

target_compile_options(
	rtc_audio PRIVATE -std=gnu++11
)

target_compile_options(
	audio_mixer PRIVATE -std=gnu++11
)

target_compile_options(
	rtc_stats PRIVATE -std=gnu++11
)

target_compile_options(
	congestion_controller PRIVATE -std=gnu++11
)

target_compile_definitions(rtc_media PRIVATE 
	-DHAVE_WEBRTC_VIDEO 
	-DHAVE_WEBRTC_VOICE 
	-DWEBRTC_USE_H264 
	-DWEBRTC_OPUS_SUPPORT_120MS_PTIME=1
)


