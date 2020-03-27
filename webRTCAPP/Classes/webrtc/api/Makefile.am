AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_api.a

DEFS = -I../../ -I../../third_party/libyuv/include

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_api_a_SOURCES = video/i420_buffer.cc\
video/video_frame.cc\
fakemetricsobserver.cc\
mediaconstraintsinterface.cc\
mediastreaminterface.cc\
mediatypes.cc\
statstypes.cc\
trackmediainfomap.cc
