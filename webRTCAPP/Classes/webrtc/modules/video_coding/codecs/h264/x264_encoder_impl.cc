/*
*
*
*
*
*
*/
#include "webrtc/modules/video_coding/codecs/h264/x264_encoder_impl.h"
#include "webrtc/common_video/libyuv/include/webrtc_libyuv.h"
#include "third_party/x264/x264.h"
#include "webrtc/base/logging.h"

namespace webrtc {

X264EncoderImpl::X264EncoderImpl(const cricket::VideoCodec& codec)
	: encoded_image_(),
	encoded_complete_callback_(NULL),
	inited_(false),
	x264_encoder(NULL),
	frame_cnt(0)
{
	memset(&codec_, 0x0, sizeof(codec_));
}

X264EncoderImpl::~X264EncoderImpl()
{
	inited_ = true;  // in order to do the actual release
	Release();
}

int32_t X264EncoderImpl::Release()
{
	if (encoded_image_._buffer) {
		delete[] encoded_image_._buffer;
		encoded_image_._buffer = NULL;
	}

	if (x264_encoder) {
		x264_encoder_close(x264_encoder);
		x264_encoder = NULL;
		//x264_picture_clean(&x264_pic);
	}
	
	inited_ = false;
	return WEBRTC_VIDEO_CODEC_OK;
}

int32_t X264EncoderImpl::InitEncode(const VideoCodec *inst,
										int32_t number_of_cores,
										size_t max_payload_size)
{
	if (!inst)
		return WEBRTC_VIDEO_CODEC_ERR_PARAMETER;
	
	if (inst->maxFramerate < 1)
		return WEBRTC_VIDEO_CODEC_ERR_PARAMETER;
	
	// Allow zero to represent an unspecified maxBitRate
	if (inst->maxBitrate > 0 && inst->startBitrate > inst->maxBitrate)
		return WEBRTC_VIDEO_CODEC_ERR_PARAMETER;
	
	if (inst->width < 1 || inst->height < 1)
		return WEBRTC_VIDEO_CODEC_ERR_PARAMETER;
	
	if (number_of_cores < 1)
		return WEBRTC_VIDEO_CODEC_ERR_PARAMETER;
	
	int retVal = Release();
	if (retVal < 0)
		return retVal;

	if (&codec_ != inst)
		codec_ = *inst;

	encoded_image_._size   = CalcBufferSize(kI420, codec_.width, codec_.height);
	encoded_image_._buffer = new uint8_t[encoded_image_._size];
	encoded_image_._completeFrame = true;

	x264_param_t param;
	x264_param_default(&param);

	if (0 != x264_param_default_preset(&param, "veryfast", "zerolatency"))
		return -1;

	param.i_threads = (1280 * 720) <= (codec_.width * codec_.height) ? X264_THREADS_AUTO : 1;
	param.b_sliced_threads = 0;
	param.i_csp = X264_CSP_I420;
	param.i_width = codec_.width;
	param.i_height = codec_.height;
	param.b_vfr_input = 0;
	param.b_repeat_headers = 1;
	param.b_annexb = 0;
	param.i_log_level = X264_LOG_NONE;
	param.i_fps_num = 25; // codec_.maxFramerate;
	param.i_keyint_max = codec_.maxFramerate * 3;
	param.i_keyint_min = codec_.maxFramerate;
	param.i_bframe = 0;
	param.rc.i_rc_method = X264_RC_ABR;
//	param.rc.b_filler = true;
//	param.rc.i_bitrate = codec_.targetBitrate ? codec_.targetBitrate
//											  : codec_.startBitrate;
	param.rc.i_bitrate = codec_.maxBitrate * 0.8;
	param.rc.i_vbv_max_bitrate = codec_.maxBitrate;
	//param.rc.i_vbv_buffer_size = codec_.maxBitrate; 
	//param.rc.f_rate_tolerance = 0.1;
	LOG(LS_INFO) << "X264 initialized param. width is " << param.i_width
				 << ", height is " << param.i_height
				 << ", framerate is " << param.i_fps_num
				 << ", bitrate is " << param.rc.i_bitrate
				 << ", vbv bitrate is " << param.rc.i_vbv_max_bitrate; 

	x264_param_apply_fastfirstpass(&param);
	if (0 != x264_param_apply_profile(&param, "baseline")) {
		return -1;
	}

	//if (0 != x264_picture_alloc(&x264_pic, param.i_csp, param.i_width, param.i_height)) {
	//	return -1;
	//}

	x264_picture_init(&x264_pic);
	x264_pic.img.i_csp = X264_CSP_I420;
	x264_pic.img.i_plane = 3;
	
	x264_encoder = x264_encoder_open(&param);
	if (!x264_encoder) {
		//x264_picture_clean(&x264_pic);
		return -1;
	}

	inited_ = true;
	return WEBRTC_VIDEO_CODEC_OK;
}

int32_t X264EncoderImpl::RegisterEncodeCompleteCallback(EncodedImageCallback *callback)
{
	encoded_complete_callback_ = callback;
	return WEBRTC_VIDEO_CODEC_OK;
}

int32_t X264EncoderImpl::Encode(const VideoFrame &input_frame,
								const CodecSpecificInfo *codec_specific_info,
								const std::vector <FrameType> *frame_types)
{
	if (!inited_)
		return WEBRTC_VIDEO_CODEC_UNINITIALIZED;

	if (encoded_complete_callback_ == NULL) 
		return WEBRTC_VIDEO_CODEC_UNINITIALIZED;

	FrameType frame_type = kVideoFrameDelta;
	if (frame_types && frame_types->size() > 0)
		frame_type = (*frame_types)[0];

	bool send_keyframe = (frame_type == kVideoFrameKey);
	if (send_keyframe)
		x264_pic.i_type = X264_TYPE_IDR;
		//x264_pic.b_keyframe = true;

	//int len = codec_.width * codec_.height;
	//memcpy(x264_pic.img.plane[0], input_frame.video_frame_buffer()->DataY(), len);
	//memcpy(x264_pic.img.plane[1], input_frame.video_frame_buffer()->DataU(), len >> 2);
	//memcpy(x264_pic.img.plane[2], input_frame.video_frame_buffer()->DataV(), len >> 2);
	x264_pic.img.plane[0] = (uint8_t*)input_frame.video_frame_buffer()->DataY();
	x264_pic.img.plane[1] = (uint8_t*)input_frame.video_frame_buffer()->DataU();
	x264_pic.img.plane[2] = (uint8_t*)input_frame.video_frame_buffer()->DataV();
	x264_pic.img.i_stride[0] = input_frame.video_frame_buffer()->StrideY();
	x264_pic.img.i_stride[1] = input_frame.video_frame_buffer()->StrideU();
	x264_pic.img.i_stride[2] = input_frame.video_frame_buffer()->StrideV();
		
	int nal = 0;
	x264_nal_t *x264_nal = NULL;
	x264_picture_t pic_out;
	int size = x264_encoder_encode(x264_encoder, &x264_nal, &nal, &x264_pic, &pic_out);
	if (0 > size) {
		LOG(LS_ERROR) << "X264 Encode failed";
		return -1;
	}

	x264_pic.i_pts++;

	if (0 == nal) {
		LOG(LS_WARNING) << "X264 Encode success, but have no nal";
		return WEBRTC_VIDEO_CODEC_OK;
	}
		
	RTPFragmentationHeader frag_info;
	frag_info.VerifyAndAllocateFragmentationHeader(nal);

	{
		//if (1 < nal)  printf("encoded I frame. nal is %d\n", nal);
	}

	encoded_image_._length = 0;
	for (int i = 0; i < nal; i++) {
		uint8_t *buffer = x264_nal[i].p_payload;
		int length = x264_nal[i].i_payload;
	
		frag_info.fragmentationOffset[i] = encoded_image_._length + 4;
		frag_info.fragmentationLength[i] = x264_nal[i].i_payload - 4;
		frag_info.fragmentationPlType[i] = x264_nal[i].i_type;

		length = x264_nal[i].i_payload;
		memcpy(encoded_image_._buffer + encoded_image_._length, buffer, length);
		encoded_image_._length += length;
	}


	if (encoded_image_._length) {
		encoded_image_._timeStamp = input_frame.timestamp();
		encoded_image_.capture_time_ms_ = input_frame.render_time_ms();
		encoded_image_._encodedWidth = input_frame.width();
		encoded_image_._encodedHeight = input_frame.height();
		encoded_image_._frameType = ConvertToFrameType(pic_out.i_type);

	    CodecSpecificInfo codec_specific;
	    codec_specific.codecType = kVideoCodecH264;
	    codec_specific.codecSpecific.H264.packetization_mode = H264PacketizationMode::NonInterleaved;
		encoded_complete_callback_->OnEncodedImage(encoded_image_,
												   &codec_specific,
												   &frag_info);
	}
	
	x264_pic.i_type = X264_TYPE_AUTO;
	return WEBRTC_VIDEO_CODEC_OK;
}

FrameType X264EncoderImpl::ConvertToFrameType(const int type)
{
	return (X264_TYPE_IDR == type ? kVideoFrameKey : kVideoFrameDelta);
}

int32_t X264EncoderImpl::SetChannelParameters(uint32_t packet_loss, int64_t rtt)
{
	return WEBRTC_VIDEO_CODEC_OK;
}

int32_t X264EncoderImpl::SetRates(uint32_t bitrate, uint32_t framerate)
{
	return WEBRTC_VIDEO_CODEC_OK;
}

}  // namespace webrtc

