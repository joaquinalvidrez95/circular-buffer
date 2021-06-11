#include "cbprinter.h"

#include <stdio.h>
#include "circular_buffer.h"

void cbprinter_enqueue(uint8_t element, struct circular_buffer *p_cb)
{
    if (CIRCULAR_BUF_RET_ERR == circular_buf_enqueue(element, p_cb))
    {
        printf("Circular buffer full\n");
    }
    else
    {
        printf("Element enqueued: %u\n", element);
    }
}

void cbprinter_dequeue(uint8_t element, struct circular_buffer *p_cb)
{
    if (CIRCULAR_BUF_RET_ERR == circular_buf_enqueue(element, p_cb))
    {
        printf("Circular buffer empty\n");
    }
    else
    {
        printf("Element dequeued: %u\n", element);
    }
}