AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_call.a

DEFS = -I../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX -DWEBRTC_BUILD_LIBEVENT
AM_CXXFLAGS = -std=gnu++11

libwebrtc_call_a_SOURCES = audio_send_stream.cc \
bitrate_allocator.cc \
call.cc \
flexfec_receive_stream_impl.cc 