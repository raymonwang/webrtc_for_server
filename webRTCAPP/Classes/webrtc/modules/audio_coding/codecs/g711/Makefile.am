AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_audio_coding_g711.a

DEFS = -I../../../../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_audio_coding_g711_a_SOURCES = audio_decoder_pcm.cc\
audio_encoder_pcm.cc\
g711.c\
g711_interface.c