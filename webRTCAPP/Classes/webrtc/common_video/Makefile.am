AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_common_video.a

DEFS = -I../../ -I../../third_party/libyuv/include

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_common_video_a_SOURCES = h264/h264_bitstream_parser.cc\
h264/h264_common.cc\
h264/pps_parser.cc\
h264/profile_level_id.cc\
h264/sps_parser.cc\
h264/sps_vui_rewriter.cc\
libyuv/webrtc_libyuv.cc\
bitrate_adjuster.cc\
i420_buffer_pool.cc\
incoming_video_stream.cc\
video_frame.cc\
video_frame_buffer.cc\
video_render_frames.cc   