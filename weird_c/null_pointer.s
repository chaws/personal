	.file	"null_pointer.c"
	.intel_syntax noprefix
	.section	.rodata
.LC0:
	.string	"/bin/sh"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-16], 0
	mov	QWORD PTR [rbp-8], 0
	mov	QWORD PTR [rbp-32], 0
	lea	rdx, [rbp-32]
	lea	rax, [rbp-16]
	mov	rsi, rax
	mov	edi, OFFSET FLAT:.LC0
	call	execve
	mov	eax, 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
