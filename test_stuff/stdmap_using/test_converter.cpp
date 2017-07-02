#include "frame_processing.hpp"

int main()
{
	int err = 0;
	frame_in_t in;
	frame_out_t out;

	init_converter();

	in.format = RGB32;
	out.format = RGB24;

	err = frame_conversion(&in, &out);
	return 0;
}
