AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_video_capture.a

DEFS = -I../../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_video_capture_a_SOURCES = linux/device_info_linux.cc\
linux/video_capture_linux.cc\
device_info_impl.cc\
video_capture_factory.cc\
video_capture_impl.cc 
 
 