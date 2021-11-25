/* Script for -z combreloc */
/* Copyright (C) 2014-2020 Free Software Foundation, Inc.
   Copying and distribution of this script, with or without modification,
   are permitted in any medium without royalty provided the copyright
   notice and this notice are preserved.  */
OUTPUT_FORMAT("elf32-littleriscv", "elf32-littleriscv",
	      "elf32-littleriscv")
OUTPUT_ARCH(riscv)
MEMORY
{
  ROM (rwx)  : ORIGIN = 0x0, LENGTH = 0x10000
  RAM (rwx)  : ORIGIN = 0x10000, LENGTH = 0x4000 
}
ENTRY(_reset)
SEARCH_DIR("/opt/riscv64/riscv64-unknown-elf/lib");
SECTIONS
{
  /* Read-only sections, merged into text segment: */
  PROVIDE (__executable_start = SEGMENT_START("text-segment", 0x10000)); . = SEGMENT_START("text-segment", 0x10000) + SIZEOF_HEADERS;
  PROVIDE(__stack_top = ORIGIN(RAM) + LENGTH(RAM));
  .reset          : { KEEP(*(.reset)) } > ROM
  .text           :
  {
    KEEP(*(.text.unlikely .text.*_unlikely .text.unlikely.*))
    KEEP(*(.text.exit .text.exit.*))
    KEEP(*(.text.startup .text.startup.*))
    KEEP(*(.text.hot .text.hot.*))
    KEEP(*(SORT(.text.sorted.*)))
    KEEP(*(.text .stub .text.* .gnu.linkonce.t.*))
    /* .gnu.warning sections are handled specially by elf.em.  */
    KEEP(*(.gnu.warning))
  } > ROM 
  PROVIDE (__etext = .);
  PROVIDE (_etext = .);
  PROVIDE (etext = .);
  .rodata         : { KEEP(*(.rodata .rodata.* .gnu.linkonce.r.*)) } > RAM
  .data           :
  {
    __DATA_BEGIN__ = .;
    KEEP(*(.data .data.* .gnu.linkonce.d.*))
    SORT(CONSTRUCTORS)
     __SDATA_BEGIN__ = .;
    KEEP(*(.srodata.cst16)) KEEP(*(.srodata.cst8)) KEEP(*(.srodata.cst4)) KEEP(*(.srodata.cst2)) KEEP(*(.srodata .srodata.*))
    KEEP(*(.sdata .sdata.* .gnu.linkonce.s.*))
  } > RAM
  
 
  _edata = .; PROVIDE (edata = .);
  . = .;
  __bss_start = .;
  
  .sbss           :
  {
    KEEP(*(.dynsbss))
    KEEP(*(.sbss .sbss.* .gnu.linkonce.sb.*))
    KEEP(*(.scommon))
  } > RAM
  .bss            :
  {
   KEEP(*(.dynbss))
   KEEP(*(.bss .bss.* .gnu.linkonce.b.*))
   KEEP(*(COMMON))
   /* Align here to ensure that the .bss section occupies space up to
      _end.  Align after .bss to ensure correct alignment even if the
      .bss section disappears because there are no input sections.
      FIXME: Why do we need it? When there is no .bss section, we do not
      pad the .data section.  */
   . = ALIGN(. != 0 ? 32 / 8 : 1);
  } > RAM
  
  . = ALIGN(32 / 8);
  . = SEGMENT_START("ldata-segment", .);
  . = ALIGN(32 / 8);
  __BSS_END__ = .;
    __global_pointer$ = MIN(__SDATA_BEGIN__ + 0x800,
		            MAX(__DATA_BEGIN__ + 0x800, __BSS_END__ - 0x800));
  _end = .; PROVIDE (end = .);
}