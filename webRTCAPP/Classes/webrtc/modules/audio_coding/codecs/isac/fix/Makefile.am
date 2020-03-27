AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_audio_coding_isac_fix.a

DEFS = -I../../../../../../ -I../../../../../../webrtc/common_audio/signal_processing/include

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX
AM_CXXFLAGS = -std=gnu++11

libwebrtc_audio_coding_isac_fix_a_SOURCES = source/audio_decoder_isacfix.cc\
source/audio_encoder_isacfix.cc\
source/arith_routines.c\
source/arith_routines_hist.c\
source/arith_routines_logist.c\
source/bandwidth_estimator.c\
source/decode.c\
source/decode_bwe.c\
source/decode_plc.c\
source/encode.c\
source/entropy_coding.c\
source/fft.c\
source/filterbank_tables.c\
source/filterbanks.c\
source/filters.c\
source/initialize.c\
source/isacfix.c\
source/lattice.c\
source/lattice_c.c\
source/lpc_masking_model.c\
source/lpc_tables.c\
source/pitch_estimator.c\
source/pitch_estimator_c.c\
source/pitch_filter.c\
source/pitch_filter_c.c\
source/pitch_gain_tables.c\
source/pitch_lag_tables.c\
source/spectrum_ar_model_tables.c\
source/transform.c\
source/transform_tables.c