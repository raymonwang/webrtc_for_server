AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_audio_coding_neteq.a

DEFS = -I../../../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX 
AM_CPPFLAGS += -DWEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE 
AM_CPPFLAGS += -DWEBRTC_CODEC_OPUS -DWEBRTC_CODEC_ISAC -DWEBRTC_CODEC_ILBC -DWEBRTC_CODEC_G722 -DRTCHAT_OPUS_FREQ=16000
AM_CXXFLAGS = -std=gnu++11

libwebrtc_audio_coding_neteq_a_SOURCES = accelerate.cc\
audio_decoder_impl.cc\
audio_multi_vector.cc\
audio_vector.cc\
background_noise.cc\
buffer_level_filter.cc\
comfort_noise.cc\
cross_correlation.cc\
decision_logic.cc\
decision_logic_fax.cc\
decision_logic_normal.cc\
decoder_database.cc\
delay_manager.cc\
delay_peak_detector.cc\
dsp_helper.cc\
dtmf_buffer.cc\
dtmf_tone_generator.cc\
expand.cc\
merge.cc\
nack_tracker.cc\
neteq.cc\
neteq_impl.cc\
normal.cc\
packet.cc\
packet_buffer.cc\
post_decode_vad.cc\
preemptive_expand.cc\
random_vector.cc\
red_payload_splitter.cc\
rtcp.cc\
statistics_calculator.cc\
sync_buffer.cc\
tick_timer.cc\
time_stretch.cc\
timestamp_scaler.cc     
