
#include "readwrite.h"

uint8_t * vptr = (uint8_t *) 0x00104000;

void readwrite_init(){
    vptr[0] = 16;
}

void readwrite_main( void ){
    uint32_t value;
    value = vptr[0];
}
