#ifndef FRAME_PROCESSING_HPP
#define FRAME_PROCESSING_HPP

extern "C" {
#include "converter.h"
}

typedef int(*converter)(const raw_frame_t*, raw_frame_t*);

int frame_conversion(const frame_in_t *in, frame_out_t *out);
void init_converter();

#endif /*FRAME_PROCESSING*/
