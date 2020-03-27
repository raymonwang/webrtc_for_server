AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_system_wrappers.a

DEFS = -I../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX -DWEBRTC_BUILD_LIBEVENT
AM_CXXFLAGS = -std=gnu++11

libwebrtc_system_wrappers_a_SOURCES = source/aligned_malloc.cc\
source/atomic32_non_darwin_unix.cc\
source/clock.cc\
source/cpu_features.cc\
source/cpu_info.cc\
source/event.cc\
source/event_timer_posix.cc\
source/field_trial_default.cc\
source/file_impl.cc\
source/logging.cc\
source/metrics_default.cc\
source/rtp_to_ntp_estimator.cc\
source/rw_lock.cc\
source/rw_lock_posix.cc\
source/sleep.cc\
source/timestamp_extrapolator.cc\
source/trace_impl.cc\
source/trace_posix.cc 