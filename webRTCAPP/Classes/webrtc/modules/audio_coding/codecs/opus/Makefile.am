AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_audio_coding_opus.a

DEFS = -I../../../../../ -I../../../../../third_party/opus/src/include

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_audio_coding_opus_a_SOURCES = audio_decoder_opus.cc\
audio_encoder_opus.cc\
opus_interface.c
