INCLUDE scripts/mysoc.ld
ENTRY(_start)
SECTIONS
{
    .text : {
        *(entry)
        *(.text)
    } > ROM
    .got : {
        *(.got)
    } > ROM
    .rodata : {
        *(.rodata)
        . = ALIGN(0x4);
        __rodata_end = .;
    } > ROM
    
    .data : AT(__rodata_end) {
        __data_start = .;
        *(.data)
        . = ALIGN(0x4);
        __data_end = .;
    } > RAM
    __data_size = SIZEOF(.data);
    __data_load_start = LOADADDR(.data);
    .bss : {
        __bss_start = .;
        *(.bss)
        . = ALIGN(0x4);
        __bss_end = .;
    } > RAM

    /DISCARD/ : {
        *(.eh_frame)
    }
    
    . = ALIGN(0x1000);
    bootstack = .;
    . += 0x1000;
    bootstacktop = .;
}