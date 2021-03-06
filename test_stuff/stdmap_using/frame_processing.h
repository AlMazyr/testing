#ifndef FRAME_PROCESSING_H
#define FRAME_PROCESSING_H

#include "converter.h"

typedef int(*converter)(const raw_frame_t*, raw_frame_t*);

int frame_conversion(const frame_in_t *in, frame_out_t *out);

#endif /*FRAME_PROCESSING*/
