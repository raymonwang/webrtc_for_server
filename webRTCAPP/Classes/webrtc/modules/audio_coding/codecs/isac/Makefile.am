AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_audio_coding_isac_main.a

DEFS = -I./main/include -I../../../../../ -I../../../../../webrtc/common_audio/signal_processing/include

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_audio_coding_isac_main_a_SOURCES = empty.cc\
locked_bandwidth_info.cc\
main/source/audio_decoder_isac.cc\
main/source/audio_encoder_isac.cc\
main/source/arith_routines.c\
main/source/arith_routines_hist.c\
main/source/arith_routines_logist.c\
main/source/bandwidth_estimator.c\
main/source/crc.c\
main/source/decode.c\
main/source/decode_bwe.c\
main/source/encode.c\
main/source/encode_lpc_swb.c\
main/source/entropy_coding.c\
main/source/fft.c\
main/source/filter_functions.c\
main/source/filterbank_tables.c\
main/source/filterbanks.c\
main/source/intialize.c\
main/source/isac.c\
main/source/lattice.c\
main/source/lpc_analysis.c\
main/source/lpc_gain_swb_tables.c\
main/source/lpc_shape_swb12_tables.c\
main/source/lpc_shape_swb16_tables.c\
main/source/lpc_tables.c\
main/source/pitch_estimator.c\
main/source/pitch_filter.c\
main/source/pitch_gain_tables.c\
main/source/pitch_lag_tables.c\
main/source/spectrum_ar_model_tables.c\
main/source/transform.c\
main/util/utility.c
