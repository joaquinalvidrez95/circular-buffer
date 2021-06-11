#include <stdio.h>

#include "circular_buffer/circular_buffer.h"

int main()
{
    struct circular_buffer cb = {0u};
    uint8_t buffer[4u];
    circular_buf_init(&cb, &buffer[0], sizeof(buffer));

    printf("Hello man\n");
    return 0;
}