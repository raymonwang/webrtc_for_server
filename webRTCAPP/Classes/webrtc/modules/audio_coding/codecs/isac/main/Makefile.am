UTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_audio_coding_isac.a

DEFS = -I../../../../../../ -I../../../../../../webrtc/common_audio/signal_processing/include -Iinclude

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_audio_coding_isac_a_SOURCES = source/arith_routines.c\
source/arith_routines_hist.c\
source/arith_routines_logist.c\
source/bandwidth_estimator.c\
source/crc.c\
source/decode_bwe.c\
source/decode.c\
source/encode.c\
source/encode_lpc_swb.c\
source/entropy_coding.c\
source/fft.c\
source/filterbanks.c\
source/filterbank_tables.c\
source/filter_functions.c\
source/intialize.c\
source/isac.c\
source/lattice.c\
source/lpc_analysis.c\
source/lpc_gain_swb_tables.c\
source/lpc_shape_swb12_tables.c\
source/lpc_shape_swb16_tables.c\
source/lpc_tables.c\
source/pitch_estimator.c\
source/pitch_filter.c\
source/pitch_gain_tables.c\
source/pitch_lag_tables.c\
source/spectrum_ar_model_tables.c\
source/transform.c\
source/audio_decoder_isac.cc\
source/audio_encoder_isac.cc
