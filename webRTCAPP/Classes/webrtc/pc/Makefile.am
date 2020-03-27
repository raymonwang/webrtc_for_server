AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = librtc_pc.a

AM_CPPFLAGS = -I../../ -I../../third_party/libsrtp/crypto/include -I../../third_party/libsrtp/include -I../../third_party/libsrtp/config
AM_CPPFLAGS += -DWEBRTC_POSIX -DWEBRTC_LINUX -DHAVE_SRTP -DHAVE_UINT64_T
AM_CXXFLAGS = -std=gnu++11

librtc_pc_a_SOURCES = srtpfilter.cc 
