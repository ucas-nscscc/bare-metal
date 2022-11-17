# interrupts and exceptions handler
# push all registers, call trap_handler(), restore, return.
#
.globl trap_entry
.align 6
.type trap_entry, @function
trap_entry:
	// make room to save registers.
	addi.w	$sp, $sp, -128

	// save the registers.
	st.w	$ra, $sp, 0
	st.w	$tp, $sp, 4
	st.w	$sp, $sp, 8
	st.w	$a0, $sp, 12
	st.w	$a1, $sp, 16
	st.w	$a2, $sp, 20
	st.w	$a3, $sp, 24
	st.w	$a4, $sp, 28
	st.w	$a5, $sp, 32
	st.w	$a6, $sp, 36
	st.w	$a7, $sp, 40
	st.w	$t0, $sp, 44
	st.w	$t1, $sp, 48
	st.w	$t2, $sp, 52
	st.w	$t3, $sp, 56
	st.w	$t4, $sp, 60
	st.w	$t5, $sp, 64
	st.w	$t6, $sp, 68
	st.w	$t7, $sp, 72
	st.w	$t8, $sp, 76
	st.w	$r21, $sp,80
	st.w	$fp, $sp, 84
	st.w	$s0, $sp, 88
	st.w	$s1, $sp, 92
	st.w	$s2, $sp, 96
	st.w	$s3, $sp, 100
	st.w	$s4, $sp, 104
	st.w	$s5, $sp, 108
	st.w	$s6, $sp, 112
	st.w	$s7, $sp, 116
	st.w	$s8, $sp, 120

	move	$a0, $sp
	bl	print_hex
	ld.w	$a0, $sp, 0
	bl	print_hex

	// call the C trap handler in trap.c
	bl trap_handler

	move	$a0, $sp
	bl	print_hex
	ld.w	$a0, $sp, 0
	bl	print_hex

	// restore register
	ld.w	$ra, $sp, 0
	ld.w	$tp, $sp, 4
	ld.w	$sp, $sp, 8
	ld.w	$a0, $sp, 12
	ld.w	$a1, $sp, 16
	ld.w	$a2, $sp, 20
	ld.w	$a3, $sp, 24
	ld.w	$a4, $sp, 28
	ld.w	$a5, $sp, 32
	ld.w	$a6, $sp, 36
	ld.w	$a7, $sp, 40
	ld.w	$t0, $sp, 44
	ld.w	$t1, $sp, 48
	ld.w	$t2, $sp, 52
	ld.w	$t3, $sp, 56
	ld.w	$t4, $sp, 60
	ld.w	$t5, $sp, 64
	ld.w	$t6, $sp, 68
	ld.w	$t7, $sp, 72
	ld.w	$t8, $sp, 76
	ld.w	$r21, $sp,80
	ld.w	$fp, $sp, 84
	ld.w	$s0, $sp, 88
	ld.w	$s1, $sp, 92
	ld.w	$s2, $sp, 96
	ld.w	$s3, $sp, 100
	ld.w	$s4, $sp, 104
	ld.w	$s5, $sp, 108
	ld.w	$s6, $sp, 112
	ld.w	$s7, $sp, 116
	ld.w	$s8, $sp, 120

	addi.w	$sp, $sp, 128

	// exception return
	ertn
