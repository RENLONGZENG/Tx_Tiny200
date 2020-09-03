#include "main.h"

void my_thread_entry(ULONG thread_input);


unsigned long my_thread_counter = 0;
TX_THREAD my_thread;

int main(void)
{
    return 0;
}

void tx_application_define(void *first_unused_memory)
{
    /* Create my_thread!  */
    tx_thread_create(&my_thread, 
                    "My Thread",
                    my_thread_entry, 
                    0x1234, 
                    first_unused_memory, 
                    1024, 
                    3, 
                    3, 
                    TX_NO_TIME_SLICE, 
                    TX_AUTO_START); 
}

void my_thread_entry(ULONG thread_input)
{
    /* Enter into a forever loop.  */
//    UCHAR my_trace_buffer[64000];
//    UCHAR status = 0;
    
//    status = tx_trace_enable (&my_trace_buffer, 64000, 30);
    
    while(1)
    {
        /* Increment thread counter.  */ 
        my_thread_counter++;
        /* Sleep for 1 tick.  */
        tx_thread_sleep(1000);

//        signal_led_toggle();

    }
}
