AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_audio_conference_mixer.a

DEFS = -I../../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_audio_conference_mixer_a_SOURCES = source/audio_conference_mixer_impl.cc\
source/audio_frame_manipulator.cc\
source/time_scheduler.cc 