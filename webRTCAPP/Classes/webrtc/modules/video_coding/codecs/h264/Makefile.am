AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_video_coding_h264.a

DEFS = -I../../../../../ -I../../../../../third_party/ffmpeg

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX -DWEBRTC_USE_H264 -DWEBRTC_INITIALIZE_FFMPEG
AM_CXXFLAGS = -std=gnu++11

libwebrtc_video_coding_h264_a_SOURCES = h264.cc\
h264_decoder_impl.cc\
x264_encoder_impl.cc
 
 