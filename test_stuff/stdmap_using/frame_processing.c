#include "frame_processing.h"

#include <stdlib.h>

static converter converter_map[FORMATS_TOTAL][FORMATS_TOTAL] = {
	{NULL, rgb32_to_rgb24, NULL, NULL, NULL},
	{rgb24_to_rgb32, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL},
	{yuv_to_rgb32, NULL, NULL, NULL, NULL},
	{NULL, NULL, raw8_to_nv12, NULL, NULL}
};

int frame_conversion(const frame_in_t *in, frame_out_t *out)
{
	converter conv = NULL;
	conv = converter_map[in->format][out->format];
	if (conv == NULL)
		return -1;
	return conv(&in->frame, &out->frame);
}
