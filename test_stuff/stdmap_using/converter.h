#ifndef CONVERTER_H
#define CONVERTER_H

#include <stdint.h>

typedef enum {
	RGB32,
	RGB24,
	NV12,
	YUV,
	RAW8,
	FORMATS_TOTAL
} format_t;

typedef struct {
	uint32_t width;
	uint32_t height;
	void *buffer;
} raw_frame_t;

typedef struct {
	format_t format;
	raw_frame_t frame;
} frame_in_t;

typedef struct {
	format_t format;
	raw_frame_t frame;
} frame_out_t;

int rgb32_to_rgb24(const raw_frame_t *in, raw_frame_t *out);
int rgb24_to_rgb32(const raw_frame_t *in, raw_frame_t *out);
int raw8_to_nv12(const raw_frame_t *in, raw_frame_t *out);
int yuv_to_rgb32(const raw_frame_t *in, raw_frame_t *out);

#endif /*CONVERTER_H*/
