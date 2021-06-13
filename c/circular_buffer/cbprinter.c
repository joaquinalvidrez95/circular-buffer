#include "cbprinter.h"

#include <stdio.h>
#include "circular_buffer.h"

void cbprinter_enqueue(uint8_t element, struct circular_buffer *p_cb)
{
    if (CIRCULAR_BUF_RET_ERR == circular_buf_enqueue(element, p_cb))
    {
        printf("Circular buffer full: %u could not be enqueued\n", element);
    }
    else
    {
        printf("Element enqueued: %u\n", element);
    }
}

uint8_t cbprinter_dequeue(struct circular_buffer *p_cb)
{
    uint8_t element = 0u;
    if (CIRCULAR_BUF_RET_ERR == circular_buf_dequeue(&element, p_cb))
    {
        printf("Circular buffer empty\n");
    }
    else
    {
        printf("Element dequeued: %u\n", element);
    }
    return element;
}
