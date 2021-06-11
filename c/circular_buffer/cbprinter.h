#ifndef CBPRINTER_H
#define CBPRINTER_H

#include "circular_buffer.h"

void cbprinter_enqueue(uint8_t element, struct circular_buffer *p_cb);
void cbprinter_dequeue(uint8_t element, struct circular_buffer *p_cb);

#endif // CBPRINTER_H