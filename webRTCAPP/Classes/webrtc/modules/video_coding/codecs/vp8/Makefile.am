AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_video_coding_vp8.a

DEFS = -I../../../../../ -I../../../../../third_party/libyuv/include -I../../../../../third_party/libvpx/source/libvpx

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_video_coding_vp8_a_SOURCES = default_temporal_layers.cc\
realtime_temporal_layers.cc\
reference_picture_selection.cc\
screenshare_layers.cc\
simulcast_encoder_adapter.cc\
vp8_impl.cc
 