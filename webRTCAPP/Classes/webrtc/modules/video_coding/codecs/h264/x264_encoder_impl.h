/*
*
*
*
*
*
*/
#ifndef WEBRTC_MODULES_VIDEO_CODING_CODECS_X264_ENCODER_IMPL_H_
#define WEBRTC_MODULES_VIDEO_CODING_CODECS_X264_ENCODER_IMPL_H_

#include "webrtc/modules/video_coding/codecs/h264/include/h264.h"

#include "third_party/x264/x264.h"

namespace webrtc {

class X264EncoderImpl : public H264Encoder
{
 public:
	X264EncoderImpl(const cricket::VideoCodec& codec);
	~X264EncoderImpl();

	//implement VideoEncoder
	virtual int32_t InitEncode(const VideoCodec *codec_settings, 
							 		int32_t number_of_cores,
							 		size_t max_payload_size);
	virtual int32_t RegisterEncodeCompleteCallback(EncodedImageCallback *callback);
	virtual int32_t Release();
	virtual int32_t Encode(const VideoFrame &frame,
							const CodecSpecificInfo *codec_specific_info,
							const std::vector <FrameType> *frame_types);
	virtual int32_t SetChannelParameters(uint32_t packet_loss, int64_t rtt);
	virtual int32_t SetRates(uint32_t bitrate, uint32_t framerate);

 private:
 	FrameType ConvertToFrameType(const int type);

 private:
 	EncodedImage encoded_image_;
	EncodedImageCallback* encoded_complete_callback_;
	VideoCodec codec_;
	bool inited_;

	x264_picture_t x264_pic;
	x264_t *x264_encoder;
	int frame_cnt;
};

}

#endif
