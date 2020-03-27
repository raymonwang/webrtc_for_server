AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_remote_bitrate_estimator.a

DEFS = -I../../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_remote_bitrate_estimator_a_SOURCES = aimd_rate_control.cc\
bwe_defines.cc\
inter_arrival.cc\
overuse_detector.cc\
overuse_estimator.cc\
remote_bitrate_estimator_abs_send_time.cc\
remote_bitrate_estimator_single_stream.cc\
remote_estimator_proxy.cc\
send_time_history.cc