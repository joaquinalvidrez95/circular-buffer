#include "circular_buffer.h"

#include <stdint.h>
#include <stddef.h>

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
    enum circular_buf_ret result = CIRCULAR_BUF_RET_ERR;

    if ((CIRCULAR_BUF_STS_FULL != p_this->status) && (NULL != p_this))
    {
        result = CIRCULAR_BUF_RET_OK;
        p_this->p_buffer[p_this->write_idx] = element;
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

    return result;
}

enum circular_buf_ret circular_buf_dequeue(uint8_t *p_element,
                                           struct circular_buffer *p_this)
{
    enum circular_buf_ret result = CIRCULAR_BUF_RET_ERR;

    if (((CIRCULAR_BUF_STS_EMPTY != p_this->status) &&
         (NULL != p_element)) &&
        (NULL != p_this))
    {
        result = CIRCULAR_BUF_RET_OK;
        *p_element = p_this->p_buffer[p_this->read_idx];
        p_this->read_idx++;
        p_this->read_idx %= p_this->length;
        if (p_this->read_idx == p_this->write_idx)
        {
            p_this->status = CIRCULAR_BUF_STS_EMPTY;
        }
        else
        {
            p_this->status = CIRCULAR_BUF_STS_OK;
        }
    }

    return result;
}