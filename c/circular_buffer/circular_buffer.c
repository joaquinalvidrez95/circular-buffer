#include "circular_buffer.h"

#include <stdint.h>

void circular_buf_init(struct circular_buffer *p_this,
                       uint8_t buffer[],
                       size_t length)
{
    p_this->p_buffer = &buffer[0];
    p_this->read_idx = 0u;
    p_this->write_idx = 0u;
    p_this->status = CIRCULAR_BUF_STS_EMPTY;
    p_this->length = length;
}

enum circular_buf_sts circular_buf_enqueue(uint8_t element,
                                           struct circular_buffer *p_this)
{
    if (CIRCULAR_BUF_STS_FULL != p_this->status)
    {
        p_this->p_buffer[p_this->write_idx];
        p_this->write_idx++;
        p_this->write_idx %= p_this->length;
    }
    return p_this->status;
}
enum circular_buf_sts circular_buf_dequeue(uint8_t element,
                                           struct circular_buffer *p_this)
{
    return p_this->status;
}