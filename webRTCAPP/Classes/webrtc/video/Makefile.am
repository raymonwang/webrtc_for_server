AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_video.a

DEFS = -I../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX -DWEBRTC_BUILD_LIBEVENT
AM_CXXFLAGS = -std=gnu++11

libwebrtc_video_a_SOURCES = call_stats.cc\
encoder_rtcp_feedback.cc\
overuse_frame_detector.cc\
payload_router.cc\
quality_threshold.cc\
receive_statistics_proxy.cc\
report_block_stats.cc\
rtp_stream_receiver.cc\
rtp_streams_synchronizer.cc\
send_delay_stats.cc\
send_statistics_proxy.cc\
stats_counter.cc\
stream_synchronization.cc\
transport_adapter.cc\
video_receive_stream.cc\
video_send_stream.cc\
video_stream_decoder.cc\
vie_encoder.cc\
vie_remb.cc 