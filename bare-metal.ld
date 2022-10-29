ENTRY(_start)
SECTIONS
{
    . = 0x1c000000;
    .text : {
        *(.text)
    }
    .rodata : {
        *(.rodata)
    }
    .data : {
        *(.data)
    }

    __bss_start = .;
    .bss : { *(.bss) }
    __bss_end = .;

    . = ALIGN(0x1000);
    bootstack = .;
    bootstacktop = . + 0x1000;
}