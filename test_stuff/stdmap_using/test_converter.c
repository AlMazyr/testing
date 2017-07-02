#include "frame_processing.h"

int main()
{
	int err = 0;
	frame_in_t in;
	frame_out_t out;
	in.format = RGB32;
	out.format = RGB24;

	err = frame_conversion(&in, &out);
	return 0;
}
