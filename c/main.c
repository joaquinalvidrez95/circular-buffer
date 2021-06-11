#include <stdio.h>

#include "circular_buffer/circular_buffer.h"
#if 1
#include "circular_buffer/cbprinter.h"
#endif

int main()
{
    #if 1
    struct circular_buffer cb = {0u};
    uint8_t buffer[4u];
    circular_buf_init(&cb, &buffer[0], sizeof(buffer));
    cbprinter_enqueue(3u, &cb);
    cbprinter_enqueue(4u, &cb);
    cbprinter_enqueue(5u, &cb);
    cbprinter_enqueue(10u, &cb);
    cbprinter_enqueue(38u, &cb);
#endif
    return 0;
}