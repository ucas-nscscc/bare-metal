.text
.globl _start
_start:
	la	$t0, __bss_start
	la	$t1, __bss_end
1:
	beq	$t0, $t1, 1f
	st.b	$zero, $t0, 0
	addi.w	$t0, $t0, 1
	b	1b
1:
	la	$sp, bootstacktop
	bl	main
poweroff:
	b	poweroff
