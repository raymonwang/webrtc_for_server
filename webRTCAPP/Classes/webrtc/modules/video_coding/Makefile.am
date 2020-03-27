AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_video_coding.a

DEFS = -I../../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX -DWEBRTC_USE_H264 -DWEBRTC_BUILD_LIBEVENT
AM_CXXFLAGS = -std=gnu++11

libwebrtc_video_coding_a_SOURCES = utility/default_video_bitrate_allocator.cc\
utility/frame_dropper.cc\
utility/ivf_file_writer.cc\
utility/moving_average.cc\
utility/qp_parser.cc\
utility/quality_scaler.cc\
utility/simulcast_rate_allocator.cc\
utility/vp8_header_parser.cc\
codec_database.cc\
codec_timer.cc\
decoding_state.cc\
encoded_frame.cc\
frame_buffer.cc\
frame_buffer2.cc\
frame_object.cc\
generic_decoder.cc\
generic_encoder.cc\
h264_sprop_parameter_sets.cc\
h264_sps_pps_tracker.cc\
histogram.cc\
inter_frame_delay.cc\
jitter_buffer.cc\
jitter_estimator.cc\
media_opt_util.cc\
media_optimization.cc\
nack_module.cc\
packet.cc\
packet_buffer.cc\
protection_bitrate_calculator.cc\
receiver.cc\
rtp_frame_reference_finder.cc\
rtt_filter.cc\
session_info.cc\
timestamp_map.cc\
timing.cc\
video_codec_initializer.cc\
video_coding_impl.cc\
video_receiver.cc\
video_sender.cc   
 
 