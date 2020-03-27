AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_audio_coding_g722.a

DEFS = -I../../../../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_audio_coding_g722_a_SOURCES = audio_decoder_g722.cc\
audio_encoder_g722.cc\
g722_decode.c\
g722_encode.c\
g722_interface.c