AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_congestion_controller.a

DEFS = -I../../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_congestion_controller_a_SOURCES = congestion_controller.cc\
delay_based_bwe.cc\
median_slope_estimator.cc\
probe_bitrate_estimator.cc\
probe_controller.cc\
probing_interval_estimator.cc\
transport_feedback_adapter.cc\
trendline_estimator.cc