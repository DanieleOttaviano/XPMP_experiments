#include "pmp.h"

static void write_pmpaddr(uint32_t x, uint32_t value) {
    switch (x) {
        case 0: __asm__ inline("csrw pmpaddr0, %0" :: "r"(value)); break;
        case 1: __asm__ inline("csrw pmpaddr1, %0" :: "r"(value)); break;
        case 2: __asm__ inline("csrw pmpaddr2, %0" :: "r"(value)); break;
        case 3: __asm__ inline("csrw pmpaddr3, %0" :: "r"(value)); break;
        case 4: __asm__ inline("csrw pmpaddr4, %0" :: "r"(value)); break;
        case 5: __asm__ inline("csrw pmpaddr5, %0" :: "r"(value)); break;
        case 6: __asm__ inline("csrw pmpaddr6, %0" :: "r"(value)); break;
        case 7: __asm__ inline("csrw pmpaddr7, %0" :: "r"(value)); break;
        case 8: __asm__ inline("csrw pmpaddr8, %0" :: "r"(value)); break;
        case 9: __asm__ inline("csrw pmpaddr9, %0" :: "r"(value)); break;
        case 10: __asm__ inline("csrw pmpaddr10, %0" :: "r"(value)); break;
        case 11: __asm__ inline("csrw pmpaddr11, %0" :: "r"(value)); break;
        case 12: __asm__ inline("csrw pmpaddr12, %0" :: "r"(value)); break;
        case 13: __asm__ inline("csrw pmpaddr13, %0" :: "r"(value)); break;
        case 14: __asm__ inline("csrw pmpaddr14, %0" :: "r"(value)); break;
        case 15: __asm__ inline("csrw pmpaddr15, %0" :: "r"(value)); break;
        case 16: __asm__ inline("csrw pmpaddr16, %0" :: "r"(value)); break;
        case 17: __asm__ inline("csrw pmpaddr17, %0" :: "r"(value)); break;
        case 18: __asm__ inline("csrw pmpaddr18, %0" :: "r"(value)); break;
        case 19: __asm__ inline("csrw pmpaddr19, %0" :: "r"(value)); break;
        case 20: __asm__ inline("csrw pmpaddr20, %0" :: "r"(value)); break;
        case 21: __asm__ inline("csrw pmpaddr21, %0" :: "r"(value)); break;
        case 22: __asm__ inline("csrw pmpaddr22, %0" :: "r"(value)); break;
        case 23: __asm__ inline("csrw pmpaddr23, %0" :: "r"(value)); break;
        case 24: __asm__ inline("csrw pmpaddr24, %0" :: "r"(value)); break;
        case 25: __asm__ inline("csrw pmpaddr25, %0" :: "r"(value)); break;
        case 26: __asm__ inline("csrw pmpaddr26, %0" :: "r"(value)); break;
        case 27: __asm__ inline("csrw pmpaddr27, %0" :: "r"(value)); break;
        case 28: __asm__ inline("csrw pmpaddr28, %0" :: "r"(value)); break;
        case 29: __asm__ inline("csrw pmpaddr29, %0" :: "r"(value)); break;
        case 30: __asm__ inline("csrw pmpaddr30, %0" :: "r"(value)); break;
        case 31: __asm__ inline("csrw pmpaddr31, %0" :: "r"(value)); break;
        case 32: __asm__ inline("csrw pmpaddr32, %0" :: "r"(value)); break;
        case 33: __asm__ inline("csrw pmpaddr33, %0" :: "r"(value)); break;
        case 34: __asm__ inline("csrw pmpaddr34, %0" :: "r"(value)); break;
        case 35: __asm__ inline("csrw pmpaddr35, %0" :: "r"(value)); break;
        case 36: __asm__ inline("csrw pmpaddr36, %0" :: "r"(value)); break;
        case 37: __asm__ inline("csrw pmpaddr37, %0" :: "r"(value)); break;
        case 38: __asm__ inline("csrw pmpaddr38, %0" :: "r"(value)); break;
        case 39: __asm__ inline("csrw pmpaddr39, %0" :: "r"(value)); break;
        case 40: __asm__ inline("csrw pmpaddr40, %0" :: "r"(value)); break;
        case 41: __asm__ inline("csrw pmpaddr41, %0" :: "r"(value)); break;
        case 42: __asm__ inline("csrw pmpaddr42, %0" :: "r"(value)); break;
        case 43: __asm__ inline("csrw pmpaddr43, %0" :: "r"(value)); break;
        case 44: __asm__ inline("csrw pmpaddr44, %0" :: "r"(value)); break;
        case 45: __asm__ inline("csrw pmpaddr45, %0" :: "r"(value)); break;
        case 46: __asm__ inline("csrw pmpaddr46, %0" :: "r"(value)); break;
        case 47: __asm__ inline("csrw pmpaddr47, %0" :: "r"(value)); break;
        case 48: __asm__ inline("csrw pmpaddr48, %0" :: "r"(value)); break;
        case 49: __asm__ inline("csrw pmpaddr49, %0" :: "r"(value)); break;
        case 50: __asm__ inline("csrw pmpaddr50, %0" :: "r"(value)); break;
        case 51: __asm__ inline("csrw pmpaddr51, %0" :: "r"(value)); break;
        case 52: __asm__ inline("csrw pmpaddr52, %0" :: "r"(value)); break;
        case 53: __asm__ inline("csrw pmpaddr53, %0" :: "r"(value)); break;
        case 54: __asm__ inline("csrw pmpaddr54, %0" :: "r"(value)); break;
        case 55: __asm__ inline("csrw pmpaddr55, %0" :: "r"(value)); break;
        case 56: __asm__ inline("csrw pmpaddr56, %0" :: "r"(value)); break;
        case 57: __asm__ inline("csrw pmpaddr57, %0" :: "r"(value)); break;
        case 58: __asm__ inline("csrw pmpaddr58, %0" :: "r"(value)); break;
        case 59: __asm__ inline("csrw pmpaddr59, %0" :: "r"(value)); break;
        case 60: __asm__ inline("csrw pmpaddr60, %0" :: "r"(value)); break;
        case 61: __asm__ inline("csrw pmpaddr61, %0" :: "r"(value)); break;
        case 62: __asm__ inline("csrw pmpaddr62, %0" :: "r"(value)); break;
        case 63: __asm__ inline("csrw pmpaddr63, %0" :: "r"(value)); break;
        default:
            // Handle invalid case
            break;
    }
}

static void write_pmpcfg(uint32_t x, uint32_t value) {
    switch (x) {
        case 0: __asm__ inline("csrw pmpcfg0, %0" :: "r"(value)); break;
        case 1: __asm__ inline("csrw pmpcfg1, %0" :: "r"(value)); break;
        case 2: __asm__ inline("csrw pmpcfg2, %0" :: "r"(value)); break;
        case 3: __asm__ inline("csrw pmpcfg3, %0" :: "r"(value)); break;
        case 4: __asm__ inline("csrw pmpcfg4, %0" :: "r"(value)); break;
        case 5: __asm__ inline("csrw pmpcfg5, %0" :: "r"(value)); break;
        case 6: __asm__ inline("csrw pmpcfg6, %0" :: "r"(value)); break;
        case 7: __asm__ inline("csrw pmpcfg7, %0" :: "r"(value)); break;
        case 8: __asm__ inline("csrw pmpcfg8, %0" :: "r"(value)); break;
        case 9: __asm__ inline("csrw pmpcfg9, %0" :: "r"(value)); break;
        case 10: __asm__ inline("csrw pmpcfg10, %0" :: "r"(value)); break;
        case 11: __asm__ inline("csrw pmpcfg11, %0" :: "r"(value)); break;
        case 12: __asm__ inline("csrw pmpcfg12, %0" :: "r"(value)); break;
        case 13: __asm__ inline("csrw pmpcfg13, %0" :: "r"(value)); break;
        case 14: __asm__ inline("csrw pmpcfg14, %0" :: "r"(value)); break;
        case 15: __asm__ inline("csrw pmpcfg15, %0" :: "r"(value)); break;
        default:
            // Handle invalid case
            break;
    }
}

void set_pmp_rel(uint32_t x, uint32_t value){
    switch (x) {
        case 0:   __asm__ volatile("csrw 0xbc0, %0" :: "r"(value)); break;
        case 1:   __asm__ volatile("csrw 0xbc1, %0" :: "r"(value)); break;
        case 2:   __asm__ volatile("csrw 0xbc2, %0" :: "r"(value)); break;
        case 3:   __asm__ volatile("csrw 0xbc3, %0" :: "r"(value)); break;
        case 4:   __asm__ volatile("csrw 0xbc4, %0" :: "r"(value)); break;
        case 5:   __asm__ volatile("csrw 0xbc5, %0" :: "r"(value)); break;
        case 6:   __asm__ volatile("csrw 0xbc6, %0" :: "r"(value)); break;
        case 7:   __asm__ volatile("csrw 0xbc7, %0" :: "r"(value)); break;
        case 8:   __asm__ volatile("csrw 0xbc8, %0" :: "r"(value)); break;
        case 9:   __asm__ volatile("csrw 0xbc9, %0" :: "r"(value)); break;
        case 10:  __asm__ volatile("csrw 0xbca, %0" :: "r"(value)); break;
        case 11:  __asm__ volatile("csrw 0xbcb, %0" :: "r"(value)); break;
        case 12:  __asm__ volatile("csrw 0xbcc, %0" :: "r"(value)); break;
        case 13:  __asm__ volatile("csrw 0xbcd, %0" :: "r"(value)); break;
        case 14:  __asm__ volatile("csrw 0xbce, %0" :: "r"(value)); break;
        case 15:  __asm__ volatile("csrw 0xbcf, %0" :: "r"(value)); break;
        case 16:  __asm__ volatile("csrw 0xbd0, %0" :: "r"(value)); break;
        case 17:  __asm__ volatile("csrw 0xbd1, %0" :: "r"(value)); break;
        case 18:  __asm__ volatile("csrw 0xbd2, %0" :: "r"(value)); break;
        case 19:  __asm__ volatile("csrw 0xbd3, %0" :: "r"(value)); break;
        case 20:  __asm__ volatile("csrw 0xbd4, %0" :: "r"(value)); break;
        case 21:  __asm__ volatile("csrw 0xbd5, %0" :: "r"(value)); break;
        case 22:  __asm__ volatile("csrw 0xbd6, %0" :: "r"(value)); break;
        case 23:  __asm__ volatile("csrw 0xbd7, %0" :: "r"(value)); break;
        case 24:  __asm__ volatile("csrw 0xbd8, %0" :: "r"(value)); break;
        case 25:  __asm__ volatile("csrw 0xbd9, %0" :: "r"(value)); break;
        case 26:  __asm__ volatile("csrw 0xbda, %0" :: "r"(value)); break;
        case 27:  __asm__ volatile("csrw 0xbdb, %0" :: "r"(value)); break;
        case 28:  __asm__ volatile("csrw 0xbdc, %0" :: "r"(value)); break;
        case 29:  __asm__ volatile("csrw 0xbdd, %0" :: "r"(value)); break;
        case 30:  __asm__ volatile("csrw 0xbde, %0" :: "r"(value)); break;
        case 31:  __asm__ volatile("csrw 0xbdf, %0" :: "r"(value)); break;
        case 32:  __asm__ volatile("csrw 0xbe0, %0" :: "r"(value)); break;
        case 33:  __asm__ volatile("csrw 0xbe1, %0" :: "r"(value)); break;
        case 34:  __asm__ volatile("csrw 0xbe2, %0" :: "r"(value)); break;
        case 35:  __asm__ volatile("csrw 0xbe3, %0" :: "r"(value)); break;
        case 36:  __asm__ volatile("csrw 0xbe4, %0" :: "r"(value)); break;
        case 37:  __asm__ volatile("csrw 0xbe5, %0" :: "r"(value)); break;
        case 38:  __asm__ volatile("csrw 0xbe6, %0" :: "r"(value)); break;
        case 39:  __asm__ volatile("csrw 0xbe7, %0" :: "r"(value)); break;
        case 40:  __asm__ volatile("csrw 0xbe8, %0" :: "r"(value)); break;
        case 41:  __asm__ volatile("csrw 0xbe9, %0" :: "r"(value)); break;
        case 42:  __asm__ volatile("csrw 0xbea, %0" :: "r"(value)); break;
        case 43:  __asm__ volatile("csrw 0xbeb, %0" :: "r"(value)); break;
        case 44:  __asm__ volatile("csrw 0xbec, %0" :: "r"(value)); break;
        case 45:  __asm__ volatile("csrw 0xbed, %0" :: "r"(value)); break;
        case 46:  __asm__ volatile("csrw 0xbee, %0" :: "r"(value)); break;
        case 47:  __asm__ volatile("csrw 0xbef, %0" :: "r"(value)); break;
        case 48:  __asm__ volatile("csrw 0xbf1, %0" :: "r"(value)); break;
        case 49:  __asm__ volatile("csrw 0xbf2, %0" :: "r"(value)); break;
        case 50:  __asm__ volatile("csrw 0xbf3, %0" :: "r"(value)); break;
        case 51:  __asm__ volatile("csrw 0xbf4, %0" :: "r"(value)); break;
        case 52:  __asm__ volatile("csrw 0xbf5, %0" :: "r"(value)); break;
        case 53:  __asm__ volatile("csrw 0xbf6, %0" :: "r"(value)); break;
        case 54:  __asm__ volatile("csrw 0xbf7, %0" :: "r"(value)); break;
        case 55:  __asm__ volatile("csrw 0xbf8, %0" :: "r"(value)); break;
        case 56:  __asm__ volatile("csrw 0xbfb, %0" :: "r"(value)); break;
        case 57:  __asm__ volatile("csrw 0xbfd, %0" :: "r"(value)); break;
        case 58:  __asm__ volatile("csrw 0xbfe, %0" :: "r"(value)); break;
        case 59:  __asm__ volatile("csrw 0xbff, %0" :: "r"(value)); break;
        case 60:  __asm__ volatile("csrw 0x7c0, %0" :: "r"(value)); break;
        case 61:  __asm__ volatile("csrw 0x7c1, %0" :: "r"(value)); break;
        case 62:  __asm__ volatile("csrw 0x7c2, %0" :: "r"(value)); break;
        case 63:  __asm__ volatile("csrw 0x7c3, %0" :: "r"(value)); break;
        default:
            // Handle invalid case
            break;
    }
}

static uint32_t napot_addr_encoding(uint32_t base, uint32_t range){
   return (base + (range/2 - 1)) >> 2;
}

void set_pmp_addr(uint32_t x, uint32_t base, uint32_t range){   
    //check input ...
    uint32_t value = napot_addr_encoding(base, range);
    write_pmpaddr(x,value);
}

void set_pmp_cfg(uint32_t x, uint32_t value) {
    //check input ...
    // to implement napot encoding also for cfg
    write_pmpcfg(x,value);
}