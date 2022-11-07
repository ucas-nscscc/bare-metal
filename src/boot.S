.section entry, "ax"
.globl _start
.type _start, @function

_start:
	la	$t0, __code_start
	la	$t1, __code_end
	li.w	$t2, 0x8000
	sub.w	$t2, $t0, $t2
1:
	beq	$t0, $t1, 1f
	ld.w	$t3, $t2, 0
	st.w	$t3, $t0, 0
	addi.w	$t0, $t0, 4
	addi.w	$t2, $t2, 4
	b	1b
1:

	// dbar	0
	la	$t0, real_start
	jr	$t0

real_start:
	la	$t0, __bss_start
	la	$t1, __bss_end
2:
	beq	$t0, $t1, 2f
	st.b	$zero, $t0, 0
	addi.w	$t0, $t0, 1
	b	2b
2:

	la	$sp, bootstacktop
	bl	main
	
poweroff:
	b	poweroff
