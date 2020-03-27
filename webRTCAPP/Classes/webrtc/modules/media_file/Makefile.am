AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_media_file.a

DEFS = -I../../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CPPFLAGS += -DWEBRTC_CODEC_ISAC -DWEBRTC_CODEC_ILBC -DWEBRTC_CODEC_G722
AM_CXXFLAGS = -std=gnu++11

libwebrtc_media_file_a_SOURCES = media_file_impl.cc\
media_file_utility.cc 
