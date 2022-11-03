ENTRY(_start)
SECTIONS
{
    . = 0x1c008000;
    __code_start = .;
    .text : {
        *(.text)
    }
    .rodata : {
        *(.rodata)
    }
    .data : {
        *(.data)
    }
    .bss : {
        __bss_start = .;
        *(.bss)
        __bss_end = .;
    }
    . = ALIGN(0x4);
    __code_end = .;
    . = ALIGN(0x1000);
    bootstack = .;
    . += 0x1000;
    bootstacktop = . ;
}