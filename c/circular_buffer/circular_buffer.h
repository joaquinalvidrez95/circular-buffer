#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stddef.h>

enum circular_buf_sts
{
    CIRCULAR_BUF_STS_OK,
    CIRCULAR_BUF_STS_EMPTY,
    CIRCULAR_BUF_STS_FULL,
};

struct circular_buffer
{
    uint8_t *p_buffer;
    enum circular_buf_sts status;
    size_t write_idx;
    size_t read_idx;
    size_t length;
};

void circular_buf_init(struct circular_buffer *p_this,
                       uint8_t buffer[],
                       size_t length);

enum circular_buf_sts circular_buf_enqueue(uint8_t element,
                                           struct circular_buffer *p_this);

enum circular_buf_sts circular_buf_dequeue(uint8_t element,
                                           struct circular_buffer *p_this);

#endif // CIRCULAR_BUFFER_H