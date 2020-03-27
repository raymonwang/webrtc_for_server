AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_media.a

DEFS = -I../../ -I../../third_party/libyuv/include

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX -DHAVE_WEBRTC_VOICE -DWEBRTC_INTELLIGIBILITY_ENHANCER=1
AM_CXXFLAGS = -std=gnu++11

libwebrtc_media_a_SOURCES = base/adaptedvideotracksource.cc\
base/codec.cc\
base/mediaconstants.cc\
base/mediaengine.cc\
base/rtpdataengine.cc\
base/rtputils.cc\
base/streamparams.cc\
base/turnutils.cc\
base/videoadapter.cc\
base/videobroadcaster.cc\
base/videocapturer.cc\
base/videocommon.cc\
base/videosourcebase.cc\
engine/internaldecoderfactory.cc\
engine/internalencoderfactory.cc\
engine/payload_type_mapper.cc\
engine/simulcast.cc\
engine/videodecodersoftwarefallbackwrapper.cc\
engine/videoencodersoftwarefallbackwrapper.cc\
engine/webrtcmediaengine.cc\
engine/webrtcvideocapturer.cc\
engine/webrtcvideocapturerfactory.cc\
engine/webrtcvideoencoderfactory.cc\
engine/webrtcvideoengine2.cc\
engine/webrtcvoiceengine.cc