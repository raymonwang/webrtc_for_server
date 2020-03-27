AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_video_processing.a

DEFS = -I../../../ -I../../../third_party/libyuv/include

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_video_processing_a_SOURCES = util/denoiser_filter.cc\
util/denoiser_filter_c.cc\
util/denoiser_filter_sse2.cc\
util/noise_estimation.cc\
util/skin_detection.cc\
video_denoiser.cc
 