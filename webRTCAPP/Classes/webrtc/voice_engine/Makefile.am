AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_voice_engine.a

DEFS = -I../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CPPFLAGS += -DWEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE
AM_CPPFLAGS += -DWEBRTC_BUILD_LIBEVENT
AM_CXXFLAGS = -std=gnu++11

libwebrtc_voice_engine_a_SOURCES = channel.cc\
channel_manager.cc\
channel_proxy.cc\
coder.cc\
file_player.cc\
file_recorder.cc\
level_indicator.cc\
monitor_module.cc\
output_mixer.cc\
shared_data.cc\
statistics.cc\
transmit_mixer.cc\
transport_feedback_packet_loss_tracker.cc\
utility.cc\
voe_audio_processing_impl.cc\
voe_base_impl.cc\
voe_codec_impl.cc\
voe_external_media_impl.cc\
voe_file_impl.cc\
voe_hardware_impl.cc\
voe_neteq_stats_impl.cc\
voe_network_impl.cc\
voe_rtp_rtcp_impl.cc\
voe_video_sync_impl.cc\
voe_volume_control_impl.cc\
voice_engine_impl.cc 
