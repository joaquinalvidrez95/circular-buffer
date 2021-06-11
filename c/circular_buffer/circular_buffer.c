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

enum circular_buf_ret circular_buf_enqueue(uint8_t element,
                                           struct circular_buffer *p_this)
{
    enum circular_buf_ret return_sts = CIRCULAR_BUF_RET_ERR;
    uint8_t x = 0u;

    if (CIRCULAR_BUF_STS_FULL != p_this->status)
    {
        return_sts = CIRCULAR_BUF_RET_OK;
        p_this->p_buffer[p_this->write_idx];
        p_this->write_idx++;
        p_this->write_idx %= p_this->length;
        if (p_this->read_idx == p_this->write_idx)
        {
            p_this->status = CIRCULAR_BUF_STS_FULL;
        }
        else
        {
            p_this->status = CIRCULAR_BUF_STS_OK;
        }
    }

    return return_sts;
}

enum circular_buf_ret circular_buf_dequeue(uint8_t element,
                                           struct circular_buffer *p_this)
{
    return p_this->status;
}