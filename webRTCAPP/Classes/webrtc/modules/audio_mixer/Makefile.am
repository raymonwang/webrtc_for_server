AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_audio_mixer.a

DEFS = -I../../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_audio_mixer_a_SOURCES = audio_frame_manipulator.cc\
audio_mixer_impl.cc\
default_output_rate_calculator.cc    