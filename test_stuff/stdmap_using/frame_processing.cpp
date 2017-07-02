#include "frame_processing.hpp"

#include <map>

static std::map<std::pair<format_t, format_t>, converter> converter_map;

int frame_conversion(const frame_in_t *in, frame_out_t *out)
{
	return converter_map[std::make_pair(in->format, out->format)](&in->frame, &out->frame);
}

void init_converter()
{
	converter_map[std::make_pair(rgb32, rgb24)] = rgb32_to_rgb24;
	converter_map[std::make_pair(rgb24, rgb32)] = rgb24_to_rgb32;
	converter_map[std::make_pair(raw8, nv12)] = raw8_to_nv12;
	converter_map[std::make_pair(yuv, rgb32)] = yuv_to_rgb32;
}

