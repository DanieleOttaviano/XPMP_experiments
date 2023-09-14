# Copyright lowRISC contributors.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
#include "demo_system_regs.h"

.section .text

  .global reset_handler
reset_handler:

  /* Set CSRs init values  */
  li x10, 0x1800
  csrs mstatus, x10
  # Set vectored mode
  csrsi mtvec, 0x1

  /* set all registers to zero */
  mv  x1, x0
  mv  x2, x1
  mv  x3, x1
  mv  x4, x1
  mv  x5, x1
  mv  x6, x1
  mv  x7, x1
  mv  x8, x1
  mv  x9, x1
  mv x10, x1
  mv x11, x1
  mv x12, x1
  mv x13, x1
  mv x14, x1
  mv x15, x1
  mv x16, x1
  mv x17, x1
  mv x18, x1
  mv x19, x1
  mv x20, x1
  mv x21, x1
  mv x22, x1
  mv x23, x1
  mv x24, x1
  mv x25, x1
  mv x26, x1
  mv x27, x1
  mv x28, x1
  mv x29, x1
  mv x30, x1
  mv x31, x1

  .global _start
_start:

  /* stack initilization */
  la   sp, _stack_start

  /* jump to main program entry point (argc = argv = 0) */
  addi x10, x0, 0
  addi x11, x0, 0
  
  jal x0, main


  .globl transition_to_user_mode
transition_to_user_mode:
# jump to app program entry point (argc = argv = 0) 
# This time is a U-mode code, so let's change MPP, MEPC and then perform MRET 
  la    t0, app 
  csrw  mepc, t0         # Load main addres into mepc
  csrr  t1, mstatus
  li    t0, 0xffffe7ff   # Mask MPP in mstatus (00 means User mode)
  and   t1, t1, t0       # Let's change Machine previous privilege wutg a0 value
  csrw  mstatus, t1
  la    ra, sleep_loop   # Set sleep_loop as a return address. Once the main stops its execution it will come back to wfi.
  mret                   # Use MRET to jump to main in user mode

sleep_loop:
  wfi
  j sleep_loop

default_exc_handler:
  jal x0, sleep_loop

/* =================================================== [ exceptions ] === */
/* This section has to be down here, since we have to disable rvc for it  */

  .section .isr_vector, "ax"
  .option norvc;

  /* All unimplemented interrupts/exceptions go to the default_exc_handler. */
  .org 0x00
  jal x0, reset_handler
  .rept 32
  jal x0, default_exc_handler 
  .endr
  #jal x0, reset_handler
