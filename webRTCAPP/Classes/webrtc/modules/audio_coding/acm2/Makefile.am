AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_audio_coding_acm2.a

DEFS = -I../../../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX 
AM_CPPFLAGS += -DWEBRTC_CODEC_OPUS -DWEBRTC_CODEC_ISAC -DWEBRTC_CODEC_ILBC -DWEBRTC_CODEC_G722 -DRTCHAT_OPUS_FREQ=16000
AM_CXXFLAGS = -std=gnu++11

libwebrtc_audio_coding_acm2_a_SOURCES = acm_codec_database.cc\
acm_receiver.cc\
acm_resampler.cc\
audio_coding_module.cc\
call_statistics.cc\
codec_manager.cc\
rent_a_codec.cc
