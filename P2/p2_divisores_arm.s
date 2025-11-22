	.cpu cortex-m4
	.arch armv7e-m
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 2
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"p2_divisores.c"
	.text
	.align	1
	.p2align 2,,3
	.global	suma_divisores_propios
	.syntax unified
	.thumb
	.thumb_func
	.type	suma_divisores_propios, %function
suma_divisores_propios:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	cmp	r0, #1
	ble	.L5
	cmp	r0, #3
	mov	r2, r0
	ble	.L6
	push	{r4}
	movs	r0, #1
	movs	r3, #2
.L4:
	sdiv	r1, r2, r3
	mls	r4, r3, r1, r2
	cbnz	r4, .L3
	cmp	r3, r1
	add	r0, r0, r3
	beq	.L3
	cmp	r2, r1
	it	ne
	addne	r0, r0, r1
.L3:
	adds	r3, r3, #1
	mul	r1, r3, r3
	cmp	r2, r1
	bge	.L4
	pop	{r4}
	bx	lr
.L5:
	movs	r0, #0
	bx	lr
.L6:
	movs	r0, #1
	bx	lr
	.size	suma_divisores_propios, .-suma_divisores_propios
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	"El arreglo es: \000"
	.align	2
.LC1:
	.ascii	"%d\000"
	.align	2
.LC2:
	.ascii	"\012\000"
	.align	2
.LC3:
	.ascii	", \000"
	.align	2
.LC4:
	.ascii	"%d - Deficiente (suma divisores = %d)\012\000"
	.align	2
.LC5:
	.ascii	"%d - Perfecto  (suma divisores = %d)\012\000"
	.align	2
.LC6:
	.ascii	"%d - Abundante (suma divisores = %d)\012\000"
	.section	.text.startup,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 64
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, r7, r8, lr}
	movs	r0, #0
	sub	sp, sp, #64
	bl	time
	bl	srand
	ldr	r7, .L32
	movs	r4, #100
	mov	r5, sp
	add	r6, sp, #60
	mov	r8, sp
.L14:
	bl	rand
	smull	r3, r2, r7, r0
	asrs	r3, r0, #31
	rsb	r3, r3, r2, asr #5
	mls	r0, r4, r3, r0
	adds	r0, r0, #1
	str	r0, [r8, #4]!
	cmp	r8, r6
	bne	.L14
	ldr	r0, .L32+4
	bl	printf
	mov	r4, r5
.L17:
	ldr	r1, [r4, #4]!
	ldr	r0, .L32+8
	bl	printf
	cmp	r4, r6
	ldr	r0, .L32+12
	beq	.L31
	bl	printf
	b	.L17
.L31:
	ldr	r0, .L32+16
	bl	puts
.L16:
	ldr	r1, [r5, #4]!
	cmp	r1, #1
	ble	.L25
	cmp	r1, #3
	mov	r2, #1
	ble	.L19
	movs	r3, #2
.L21:
	sdiv	r0, r1, r3
	mls	r4, r3, r0, r1
	cbnz	r4, .L20
	cmp	r0, r3
	add	r2, r2, r3
	beq	.L20
	cmp	r1, r0
	it	ne
	addne	r2, r2, r0
.L20:
	adds	r3, r3, #1
	mul	r0, r3, r3
	cmp	r1, r0
	bge	.L21
.L18:
	cmp	r1, r2
	bgt	.L19
	ittet	eq
	moveq	r2, r1
	ldreq	r0, .L32+20
	ldrne	r0, .L32+24
	moveq	r1, r2
	bl	printf
.L23:
	cmp	r5, r6
	bne	.L16
	movs	r0, #0
	add	sp, sp, #64
	@ sp needed
	pop	{r4, r5, r6, r7, r8, pc}
.L19:
	ldr	r0, .L32+28
	bl	printf
	b	.L23
.L25:
	movs	r2, #0
	b	.L18
.L33:
	.align	2
.L32:
	.word	1374389535
	.word	.LC0
	.word	.LC1
	.word	.LC3
	.word	.LC2
	.word	.LC5
	.word	.LC6
	.word	.LC4
	.size	main, .-main
	.ident	"GCC: (Arm GNU Toolchain 14.3.Rel1 (Build arm-14.174)) 14.3.1 20250623"
