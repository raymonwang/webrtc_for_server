AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_audio.a

DEFS = -I../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX -DWEBRTC_BUILD_LIBEVENT
AM_CXXFLAGS = -std=gnu++11

libwebrtc_audio_a_SOURCES = utility/audio_frame_operations.cc\
audio_receive_stream.cc\
audio_send_stream.cc\
audio_state.cc\
audio_transport_proxy.cc