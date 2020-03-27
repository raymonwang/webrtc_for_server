AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_audio_processing.a

DEFS = -I../../../

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX -DWEBRTC_NS_FIXED -DWEBRTC_APM_DEBUG_DUMP=0 -DWEBRTC_INTELLIGIBILITY_ENHANCER=1
AM_CXXFLAGS = -std=gnu++11

libwebrtc_audio_processing_a_SOURCES = aec/aec_core.cc\
aec/aec_core_sse2.cc\
aec/aec_resampler.cc\
aec/echo_cancellation.cc\
aec3/block_framer.cc\
aec3/block_processor.cc\
aec3/cascaded_biquad_filter.cc\
aec3/echo_canceller3.cc\
aec3/frame_blocker.cc\
aecm/aecm_core.cc\
aecm/aecm_core_c.cc\
aecm/echo_control_mobile.cc\
agc/legacy/analog_agc.c\
agc/legacy/digital_agc.c\
agc/agc.cc\
agc/agc_manager_direct.cc\
agc/loudness_histogram.cc\
agc/utility.cc\
beamformer/array_util.cc\
beamformer/covariance_matrix_generator.cc\
beamformer/nonlinear_beamformer.cc\
echo_detector/circular_buffer.cc\
echo_detector/mean_variance_estimator.cc\
echo_detector/moving_max.cc\
echo_detector/normalized_covariance_estimator.cc\
intelligibility/intelligibility_enhancer.cc\
intelligibility/intelligibility_utils.cc\
level_controller/biquad_filter.cc\
level_controller/down_sampler.cc\
level_controller/gain_applier.cc\
level_controller/gain_selector.cc\
level_controller/level_controller.cc\
level_controller/noise_level_estimator.cc\
level_controller/noise_spectrum_estimator.cc\
level_controller/peak_level_estimator.cc\
level_controller/saturating_gain_estimator.cc\
level_controller/signal_classifier.cc\
ns/noise_suppression.c\
ns/noise_suppression_x.c\
ns/ns_core.c\
ns/nsx_core.c\
ns/nsx_core_c.c\
transient/click_annotate.cc\
transient/file_utils.cc\
transient/moving_moments.cc\
transient/transient_detector.cc\
transient/transient_suppressor.cc\
transient/wpd_node.cc\
transient/wpd_tree.cc\
utility/block_mean_calculator.cc\
utility/delay_estimator.cc\
utility/delay_estimator_wrapper.cc\
utility/ooura_fft.cc\
utility/ooura_fft_sse2.cc\
vad/gmm.cc\
vad/pitch_based_vad.cc\
vad/pitch_internal.cc\
vad/pole_zero_filter.cc\
vad/standalone_vad.cc\
vad/vad_audio_proc.cc\
vad/vad_circular_buffer.cc\
vad/voice_activity_detector.cc\
audio_buffer.cc\
audio_processing_impl.cc\
echo_cancellation_impl.cc\
echo_control_mobile_impl.cc\
gain_control_for_experimental_agc.cc\
gain_control_impl.cc\
level_estimator_impl.cc\
low_cut_filter.cc\
noise_suppression_impl.cc\
residual_echo_detector.cc\
rms_level.cc\
splitting_filter.cc\
three_band_filter_bank.cc\
typing_detection.cc\
voice_detection_impl.cc      

libwebrtc_audio_processing_a_SOURCES += logging/apm_data_dumper.cc include/audio_processing.cc include/config.cc
