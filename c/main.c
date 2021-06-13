#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "circular_buffer/circular_buffer.h"
#include "circular_buffer/cbprinter.h"

#define BUF_LEN (20u)

static uint8_t get_random_num_u8(void)
{
    static bool b_first_call = true;

    if (b_first_call)
    {
        srand(time(0));
        b_first_call = false;
    }
    return (uint8_t)(rand() % UINT8_MAX);
}

static void enqueue_random_nums(struct circular_buffer *p_cb)
{
    for (size_t idx = 0u; idx < p_cb->length; idx++)
    {
        const uint8_t random_num = get_random_num_u8();
        cbprinter_enqueue(random_num, p_cb);
    }
}

static void dequeue_random_nums(struct circular_buffer *p_cb)
{
    for (size_t idx = 0u; idx < p_cb->length; idx++)
    {
        cbprinter_dequeue(p_cb);
    }
}

int main()
{
    struct circular_buffer circular_buf = {0u};
    uint8_t buffer[BUF_LEN] = {0u};

    circular_buf_init(&circular_buf, &buffer[0], BUF_LEN);
    enqueue_random_nums(&circular_buf);
    dequeue_random_nums(&circular_buf);

    cbprinter_dequeue(&circular_buf);
    return 0;
}