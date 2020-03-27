AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_logging.a

DEFS = -I../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_logging_a_SOURCES = rtc_event_log/rtc_event_log.cc\
rtc_event_log/rtc_event_log_helper_thread.cc