
start.elf:     file format elf32-loongarch


Disassembly of section .text:

1c000000 <_start>:
1c000000:	1c000003 	pcaddu12i	$r3,0
1c000004:	28954063 	ld.w	$r3,$r3,1360(0x550)
1c000008:	1c00000c 	pcaddu12i	$r12,0
1c00000c:	2895118c 	ld.w	$r12,$r12,1348(0x544)
1c000010:	4c000180 	jirl	$r0,$r12,0

1c000014 <poweroff>:
1c000014:	50000000 	b	0 # 1c000014 <poweroff>

1c000018 <uart_put_c>:
1c000018:	143fc00e 	lu12i.w	$r14,130560(0x1fe00)
1c00001c:	038795cd 	ori	$r13,$r14,0x1e5
1c000020:	2a0001ac 	ld.bu	$r12,$r13,0
1c000024:	0340818c 	andi	$r12,$r12,0x20
1c000028:	5bfff980 	beq	$r12,$r0,-8(0x3fff8) # 1c000020 <uart_put_c+0x8>
1c00002c:	038781ce 	ori	$r14,$r14,0x1e0
1c000030:	290001c4 	st.b	$r4,$r14,0
1c000034:	4c000020 	jirl	$r0,$r1,0

1c000038 <print_s>:
1c000038:	2800008e 	ld.b	$r14,$r4,0
1c00003c:	58002dc0 	beq	$r14,$r0,44(0x2c) # 1c000068 <print_s+0x30>
1c000040:	143fc00f 	lu12i.w	$r15,130560(0x1fe00)
1c000044:	038795ed 	ori	$r13,$r15,0x1e5
1c000048:	038781ef 	ori	$r15,$r15,0x1e0
1c00004c:	2a0001ac 	ld.bu	$r12,$r13,0
1c000050:	0340818c 	andi	$r12,$r12,0x20
1c000054:	5bfff980 	beq	$r12,$r0,-8(0x3fff8) # 1c00004c <print_s+0x14>
1c000058:	290001ee 	st.b	$r14,$r15,0
1c00005c:	02800484 	addi.w	$r4,$r4,1(0x1)
1c000060:	2800008e 	ld.b	$r14,$r4,0
1c000064:	5fffe9c0 	bne	$r14,$r0,-24(0x3ffe8) # 1c00004c <print_s+0x14>
1c000068:	4c000020 	jirl	$r0,$r1,0

Disassembly of section .text.startup:

1c00006c <main>:
1c00006c:	143fc010 	lu12i.w	$r16,130560(0x1fe00)
1c000070:	0387960d 	ori	$r13,$r16,0x1e5
1c000074:	1c00000f 	pcaddu12i	$r15,0
1c000078:	0280c1ef 	addi.w	$r15,$r15,48(0x30)
1c00007c:	0280280e 	addi.w	$r14,$r0,10(0xa)
1c000080:	03878210 	ori	$r16,$r16,0x1e0
1c000084:	2a0001ac 	ld.bu	$r12,$r13,0
1c000088:	0340818c 	andi	$r12,$r12,0x20
1c00008c:	5bfff980 	beq	$r12,$r0,-8(0x3fff8) # 1c000084 <main+0x18>
1c000090:	2900020e 	st.b	$r14,$r16,0
1c000094:	028005ef 	addi.w	$r15,$r15,1(0x1)
1c000098:	280001ee 	ld.b	$r14,$r15,0
1c00009c:	5fffe9c0 	bne	$r14,$r0,-24(0x3ffe8) # 1c000084 <main+0x18>
1c0000a0:	4c000020 	jirl	$r0,$r1,0
