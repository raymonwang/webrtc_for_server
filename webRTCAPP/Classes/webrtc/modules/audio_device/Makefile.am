AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_audio_device.a

DEFS = -I../../../ -I./linux

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX -DRTCHAT_SERVER -DWEBRTC_BUILD_LIBEVENT -DWEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE
AM_CXXFLAGS = -std=gnu++11

libwebrtc_audio_device_a_SOURCES = dummy/audio_device_dummy.cc\
dummy/file_audio_device.cc\
dummy/file_audio_device_factory.cc\
linux/alsasymboltable_linux.cc\
linux/audio_device_alsa_linux.cc\
linux/audio_mixer_manager_alsa_linux.cc\
linux/audio_mixer_manager_pulse_linux.cc\
linux/latebindingsymboltable_linux.cc\
linux/pulseaudiosymboltable_linux.cc\
linux/audio_device_rtchat_linux.cc\
audio_device_buffer.cc\
audio_device_generic.cc\
audio_device_impl.cc\
fine_audio_buffer.cc   
