#ifndef PMP_H__
#define PMP_H__

#include <stdint.h>

void set_pmp_addr(uint32_t x, uint32_t base, uint32_t range);
void set_pmp_cfg(uint32_t x, uint32_t value);
void set_pmp_rel(uint32_t x, uint32_t value);


#endif