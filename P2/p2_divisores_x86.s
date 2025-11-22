	.file	"p2_divisores.c"
	.text
	.p2align 4
	.globl	suma_divisores_propios
	.def	suma_divisores_propios;	.scl	2;	.type	32;	.endef
	.seh_proc	suma_divisores_propios
suma_divisores_propios:
	.seh_endprologue
	xorl	%r9d, %r9d
	cmpl	$1, %ecx
	jle	.L1
	cmpl	$3, %ecx
	movl	$1, %r9d
	jle	.L1
	movl	$2, %r8d
	.p2align 6
	.p2align 4,,10
	.p2align 3
.L4:
	movl	%ecx, %eax
	cltd
	idivl	%r8d
	testl	%edx, %edx
	jne	.L3
	cmpl	%r8d, %eax
	setne	%r10b
	xorl	%edx, %edx
	cmpl	%eax, %ecx
	setne	%dl
	addl	%r8d, %r9d
	andl	%r10d, %edx
	negl	%edx
	andl	%eax, %edx
	addl	%edx, %r9d
.L3:
	addl	$1, %r8d
	movl	%r8d, %eax
	imull	%r8d, %eax
	cmpl	%eax, %ecx
	jge	.L4
.L1:
	movl	%r9d, %eax
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "El arreglo es: \0"
.LC1:
	.ascii "%d\0"
.LC2:
	.ascii "\12\0"
.LC3:
	.ascii ", \0"
	.align 8
.LC4:
	.ascii "%d - Deficiente (suma divisores = %d)\12\0"
	.align 8
.LC5:
	.ascii "%d - Perfecto  (suma divisores = %d)\12\0"
	.align 8
.LC6:
	.ascii "%d - Abundante (suma divisores = %d)\12\0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	call	__main
	leaq	32(%rsp), %rbx
	xorl	%ecx, %ecx
	call	_time64
	leaq	92(%rsp), %rsi
	movq	%rbx, %rdi
	movl	%eax, %ecx
	call	srand
	.p2align 4,,10
	.p2align 3
.L10:
	call	rand
	addq	$4, %rdi
	movslq	%eax, %rdx
	movl	%eax, %ecx
	imulq	$1374389535, %rdx, %rdx
	sarl	$31, %ecx
	sarq	$37, %rdx
	subl	%ecx, %edx
	imull	$100, %edx, %edx
	subl	%edx, %eax
	addl	$1, %eax
	movl	%eax, -4(%rdi)
	cmpq	%rsi, %rdi
	jne	.L10
	leaq	.LC0(%rip), %rcx
	movq	%rbx, %rdi
	call	printf
	.p2align 4,,10
	.p2align 3
.L13:
	movl	(%rdi), %edx
	leaq	.LC1(%rip), %rcx
	addq	$4, %rdi
	call	printf
	cmpq	%rsi, %rdi
	je	.L26
	leaq	.LC3(%rip), %rcx
	call	printf
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L26:
	leaq	.LC2(%rip), %rcx
	call	puts
.L12:
	movl	(%rbx), %r9d
	cmpl	$1, %r9d
	jle	.L21
	cmpl	$3, %r9d
	movl	$1, %r8d
	jle	.L15
	movl	$2, %ecx
	.p2align 6
	.p2align 4,,10
	.p2align 3
.L17:
	movl	%r9d, %eax
	cltd
	idivl	%ecx
	testl	%edx, %edx
	jne	.L16
	cmpl	%ecx, %eax
	setne	%r10b
	xorl	%edx, %edx
	cmpl	%eax, %r9d
	setne	%dl
	addl	%ecx, %r8d
	andl	%r10d, %edx
	negl	%edx
	andl	%eax, %edx
	addl	%edx, %r8d
.L16:
	addl	$1, %ecx
	movl	%ecx, %eax
	imull	%ecx, %eax
	cmpl	%eax, %r9d
	jge	.L17
.L14:
	cmpl	%r8d, %r9d
	jg	.L15
	je	.L27
	leaq	.LC6(%rip), %rcx
	movl	%r9d, %edx
	call	printf
.L19:
	addq	$4, %rbx
	cmpq	%rsi, %rbx
	jne	.L12
	xorl	%eax, %eax
	addq	$96, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.p2align 4,,10
	.p2align 3
.L15:
	leaq	.LC4(%rip), %rcx
	movl	%r9d, %edx
	call	printf
	jmp	.L19
	.p2align 4,,10
	.p2align 3
.L21:
	xorl	%r8d, %r8d
	jmp	.L14
	.p2align 4,,10
	.p2align 3
.L27:
	leaq	.LC5(%rip), %rcx
	movl	%r9d, %r8d
	movl	%r9d, %edx
	call	printf
	jmp	.L19
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-Builds project) 15.2.0"
	.def	srand;	.scl	2;	.type	32;	.endef
	.def	rand;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
