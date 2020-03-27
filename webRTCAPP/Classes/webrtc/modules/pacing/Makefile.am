AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_pacing.a

DEFS = -I../../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_pacing_a_SOURCES = alr_detector.cc\
bitrate_prober.cc\
paced_sender.cc\
packet_router.cc  