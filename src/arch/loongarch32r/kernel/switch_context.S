.globl switch_context
.type switch_context, @function
switch_context:
	addi.w	$sp, $sp, -48
	ld.w	$t0, $a0, 0x0
	st.w	$sp, $t0, 0x4
	st.w	$ra, $sp, 0x0
	st.w	$tp, $sp, 0x4
	st.w	$a0, $sp, 0x8
	st.w	$s0, $sp, 0xc
	st.w	$s1, $sp, 0x10
	st.w	$s2, $sp, 0x14
	st.w	$s3, $sp, 0x18
	st.w	$s4, $sp, 0x1c
	st.w	$s5, $sp, 0x20
	st.w	$s6, $sp, 0x24
	st.w	$s7, $sp, 0x28
	st.w	$s8, $sp, 0x2c

	ld.w	$t0, $a1, 0x0
	ld.w	$sp, $t0, 0x4
	ld.w	$ra, $sp, 0x0
	ld.w	$tp, $sp, 0x4
	ld.w	$a0, $sp, 0x8
	ld.w	$s0, $sp, 0xc
	ld.w	$s1, $sp, 0x10
	ld.w	$s2, $sp, 0x14
	ld.w	$s3, $sp, 0x18
	ld.w	$s4, $sp, 0x1c
	ld.w	$s5, $sp, 0x20
	ld.w	$s6, $sp, 0x24
	ld.w	$s7, $sp, 0x28
	ld.w	$s8, $sp, 0x2c

	addi.w	$sp, $sp, 48
	jirl	$zero, $ra, 0
