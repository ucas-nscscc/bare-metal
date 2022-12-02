.section entry, "ax"
.globl _start
.type _start, @function

_start:
	/* copy .data section to RAM */
	la	$t0, __data_start
	la	$t1, __data_size
	add.w	$t1, $t0, $t1
	la	$t2, __data_load_start
1:
	beq	$t0, $t1, 1f
	ld.w	$t3, $t2, 0
	st.w	$t3, $t0, 0
	addi.w	$t0, $t0, 4
	addi.w	$t2, $t2, 4
	b	1b
1:
	/* clear .bss section */
	la	$t0, __bss_start
	la	$t1, __bss_end
2:
	beq	$t0, $t1, 2f
	st.b	$zero, $t0, 0
	addi.w	$t0, $t0, 1
	b	2b
2:
	/* set stack pointer and jump to C code */
	la	$sp, bootstacktop
	bl	main
	
poweroff:
	b	poweroff
