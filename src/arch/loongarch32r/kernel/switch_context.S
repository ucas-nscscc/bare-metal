.globl switch_context
.type switch_context, @function
switch_context:
	addi.w	$sp, $sp, -132
	st.w	$sp, $a0, 0x4
	st.w	$ra, $sp, 0x4
	st.w	$tp, $sp, 0x8
	st.w	$a0, $sp, 0x10
	st.w	$s0, $sp, 0x5c
	st.w	$s1, $sp, 0x60
	st.w	$s2, $sp, 0x64
	st.w	$s3, $sp, 0x68
	st.w	$s4, $sp, 0x6c
	st.w	$s5, $sp, 0x70
	st.w	$s6, $sp, 0x74
	st.w	$s7, $sp, 0x78
	st.w	$s8, $sp, 0x7c

	ld.w	$sp, $a1, 0x4
	ld.w	$ra, $sp, 0x4
	ld.w	$tp, $sp, 0x8
	ld.w	$a0, $sp, 0x10
	ld.w	$s0, $sp, 0x5c
	ld.w	$s1, $sp, 0x60
	ld.w	$s2, $sp, 0x64
	ld.w	$s3, $sp, 0x68
	ld.w	$s4, $sp, 0x6c
	ld.w	$s5, $sp, 0x70
	ld.w	$s6, $sp, 0x74
	ld.w	$s7, $sp, 0x78
	ld.w	$s8, $sp, 0x7c

	addi.w	$sp, $sp, 132
	jirl	$zero, $ra, 0
