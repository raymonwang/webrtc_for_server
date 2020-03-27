AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_video_coding_vp9.a

DEFS = -I../../../../../ -I../../../../../third_party/libvpx/source/libvpx

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_video_coding_vp9_a_SOURCES = screenshare_layers.cc\
vp9_frame_buffer_pool.cc\
vp9_impl.cc
 