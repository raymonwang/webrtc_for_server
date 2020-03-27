AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_audio_coding.a

DEFS = -I../../../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CPPFLAGS += -DWEBRTC_CODEC_OPUS -DWEBRTC_CODEC_ISAC -DWEBRTC_CODEC_ILBC -DWEBRTC_CODEC_G722
AM_CXXFLAGS = -std=gnu++11

libwebrtc_audio_coding_a_SOURCES = audio_decoder.cc\
audio_encoder.cc\
audio_format.cc\
audio_format_conversion.cc\
builtin_audio_decoder_factory.cc\
legacy_encoded_audio_frame.cc
