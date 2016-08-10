	.file	"branch_preditction.c"
	.text
.Ltext0:
	.comm	data,131072,32
	.comm	sdata,131072,32
	.globl	compare
	.type	compare, @function
compare:
.LFB2:
	.file 1 "branch_preditction.c"
	.loc 1 19 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	.loc 1 20 0
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	.loc 1 21 0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	compare, .-compare
	.section	.rodata
.LC0:
	.string	"Running %s: "
.LC1:
	.string	"sum = %llu, took "
	.text
	.globl	sorted_if
	.type	sorted_if, @function
sorted_if:
.LFB3:
	.loc 1 24 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	.loc 1 25 0
	movl	$__func__.2811, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	.loc 1 28 0
	movl	$0, -12(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L4
.L6:
	.loc 1 30 0
	movl	-12(%rbp), %eax
	cltq
	movl	sdata(,%rax,4), %eax
	cmpl	$128, %eax
	jle	.L5
	.loc 1 32 0
	movl	-12(%rbp), %eax
	cltq
	movl	sdata(,%rax,4), %eax
	cltq
	addq	%rax, -8(%rbp)
.L5:
	.loc 1 28 0
	addl	$1, -12(%rbp)
.L4:
	.loc 1 28 0 is_stmt 0 discriminator 1
	cmpl	$32767, -12(%rbp)
	jle	.L6
	.loc 1 35 0 is_stmt 1
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	.loc 1 36 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	sorted_if, .-sorted_if
	.globl	sorted_bitwise
	.type	sorted_bitwise, @function
sorted_bitwise:
.LFB4:
	.loc 1 39 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	.loc 1 40 0
	movl	$__func__.2819, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	.loc 1 43 0
	movl	$0, -16(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L8
.L9:
	.loc 1 45 0 discriminator 2
	movl	-16(%rbp), %eax
	cltq
	movl	sdata(,%rax,4), %eax
	addl	$-128, %eax
	sarl	$31, %eax
	movl	%eax, -12(%rbp)
	.loc 1 46 0 discriminator 2
	movl	-12(%rbp), %eax
	notl	%eax
	movl	%eax, %edx
	movl	-16(%rbp), %eax
	cltq
	movl	sdata(,%rax,4), %eax
	andl	%edx, %eax
	cltq
	addq	%rax, -8(%rbp)
	.loc 1 43 0 discriminator 2
	addl	$1, -16(%rbp)
.L8:
	.loc 1 43 0 is_stmt 0 discriminator 1
	cmpl	$32767, -16(%rbp)
	jle	.L9
	.loc 1 48 0 is_stmt 1
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	.loc 1 49 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	sorted_bitwise, .-sorted_bitwise
	.globl	sorted_ternary
	.type	sorted_ternary, @function
sorted_ternary:
.LFB5:
	.loc 1 52 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	.loc 1 53 0
	movl	$__func__.2828, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	.loc 1 56 0
	movl	$0, -12(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L11
.L12:
	.loc 1 58 0 discriminator 2
	movl	-12(%rbp), %eax
	cltq
	movl	sdata(,%rax,4), %eax
	cmpl	$192, %eax
	setg	%al
	movzbl	%al, %edx
	movl	-12(%rbp), %eax
	cltq
	movl	sdata(,%rax,4), %eax
	imull	%edx, %eax
	cltq
	addq	%rax, -8(%rbp)
	.loc 1 56 0 discriminator 2
	addl	$1, -12(%rbp)
.L11:
	.loc 1 56 0 is_stmt 0 discriminator 1
	cmpl	$32767, -12(%rbp)
	jle	.L12
	.loc 1 60 0 is_stmt 1
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	.loc 1 61 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	sorted_ternary, .-sorted_ternary
	.globl	unsorted_if
	.type	unsorted_if, @function
unsorted_if:
.LFB6:
	.loc 1 64 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	.loc 1 65 0
	movl	$__func__.2836, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	.loc 1 68 0
	movl	$0, -12(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L14
.L16:
	.loc 1 70 0
	movl	-12(%rbp), %eax
	cltq
	movl	data(,%rax,4), %eax
	cmpl	$128, %eax
	jle	.L15
	.loc 1 72 0
	movl	-12(%rbp), %eax
	cltq
	movl	data(,%rax,4), %eax
	cltq
	addq	%rax, -8(%rbp)
.L15:
	.loc 1 68 0
	addl	$1, -12(%rbp)
.L14:
	.loc 1 68 0 is_stmt 0 discriminator 1
	cmpl	$32767, -12(%rbp)
	jle	.L16
	.loc 1 75 0 is_stmt 1
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	.loc 1 76 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	unsorted_if, .-unsorted_if
	.globl	unsorted_bitwise
	.type	unsorted_bitwise, @function
unsorted_bitwise:
.LFB7:
	.loc 1 79 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	.loc 1 80 0
	movl	$__func__.2844, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	.loc 1 83 0
	movl	$0, -16(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L18
.L19:
	.loc 1 85 0 discriminator 2
	movl	-16(%rbp), %eax
	cltq
	movl	data(,%rax,4), %eax
	addl	$-128, %eax
	sarl	$31, %eax
	movl	%eax, -12(%rbp)
	.loc 1 86 0 discriminator 2
	movl	-12(%rbp), %eax
	notl	%eax
	movl	%eax, %edx
	movl	-16(%rbp), %eax
	cltq
	movl	data(,%rax,4), %eax
	andl	%edx, %eax
	cltq
	addq	%rax, -8(%rbp)
	.loc 1 83 0 discriminator 2
	addl	$1, -16(%rbp)
.L18:
	.loc 1 83 0 is_stmt 0 discriminator 1
	cmpl	$32767, -16(%rbp)
	jle	.L19
	.loc 1 88 0 is_stmt 1
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	.loc 1 89 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	unsorted_bitwise, .-unsorted_bitwise
	.globl	unsorted_ternary
	.type	unsorted_ternary, @function
unsorted_ternary:
.LFB8:
	.loc 1 92 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	.loc 1 93 0
	movl	$__func__.2853, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	.loc 1 96 0
	movl	$0, -12(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L21
.L22:
	.loc 1 98 0 discriminator 2
	movl	-12(%rbp), %eax
	cltq
	movl	data(,%rax,4), %eax
	cmpl	$192, %eax
	setg	%al
	movzbl	%al, %edx
	movl	-12(%rbp), %eax
	cltq
	movl	data(,%rax,4), %eax
	imull	%edx, %eax
	cltq
	addq	%rax, -8(%rbp)
	.loc 1 96 0 discriminator 2
	addl	$1, -12(%rbp)
.L21:
	.loc 1 96 0 is_stmt 0 discriminator 1
	cmpl	$32767, -12(%rbp)
	jle	.L22
	.loc 1 100 0 is_stmt 1
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	.loc 1 101 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	unsorted_ternary, .-unsorted_ternary
	.section	.rodata
.LC2:
	.string	"%.f ms\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB9:
	.loc 1 104 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	.loc 1 105 0
	movq	$sorted_if, -48(%rbp)
	movq	$sorted_bitwise, -40(%rbp)
	movq	$sorted_ternary, -32(%rbp)
	movq	$unsorted_if, -24(%rbp)
	movq	$unsorted_bitwise, -16(%rbp)
	movq	$unsorted_ternary, -8(%rbp)
	.loc 1 106 0
	movl	$6, -64(%rbp)
	.loc 1 110 0
	movl	$0, %edi
	call	time
	movl	%eax, %edi
	call	srand
	.loc 1 111 0
	movl	$0, -60(%rbp)
	jmp	.L24
.L25:
	.loc 1 113 0 discriminator 2
	call	rand
	cltd
	shrl	$24, %edx
	addl	%edx, %eax
	movzbl	%al, %eax
	subl	%edx, %eax
	movl	%eax, %edx
	movl	-60(%rbp), %eax
	cltq
	movl	%edx, data(,%rax,4)
	movl	-60(%rbp), %eax
	cltq
	movl	data(,%rax,4), %edx
	movl	-60(%rbp), %eax
	cltq
	movl	%edx, sdata(,%rax,4)
	.loc 1 111 0 discriminator 2
	addl	$1, -60(%rbp)
.L24:
	.loc 1 111 0 is_stmt 0 discriminator 1
	cmpl	$32767, -60(%rbp)
	jle	.L25
	.loc 1 117 0 is_stmt 1
	movl	$compare, %ecx
	movl	$4, %edx
	movl	$32768, %esi
	movl	$sdata, %edi
	call	qsort
	.loc 1 120 0
	jmp	.L26
.L27:
	.loc 1 122 0
	call	clock
	movq	%rax, -56(%rbp)
	.loc 1 123 0
	movl	-64(%rbp), %eax
	cltq
	movq	-48(%rbp,%rax,8), %rax
	call	*%rax
	.loc 1 124 0
	call	clock
	subq	-56(%rbp), %rax
	cvtsi2sdq	%rax, %xmm0
	movl	$.LC2, %edi
	movl	$1, %eax
	call	printf
.L26:
	.loc 1 120 0 discriminator 1
	movl	-64(%rbp), %eax
	leal	-1(%rax), %edx
	movl	%edx, -64(%rbp)
	testl	%eax, %eax
	jne	.L27
	.loc 1 126 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	main, .-main
	.section	.rodata
	.type	__func__.2811, @object
	.size	__func__.2811, 10
__func__.2811:
	.string	"sorted_if"
	.type	__func__.2819, @object
	.size	__func__.2819, 15
__func__.2819:
	.string	"sorted_bitwise"
	.type	__func__.2828, @object
	.size	__func__.2828, 15
__func__.2828:
	.string	"sorted_ternary"
	.type	__func__.2836, @object
	.size	__func__.2836, 12
__func__.2836:
	.string	"unsorted_if"
	.align 16
	.type	__func__.2844, @object
	.size	__func__.2844, 17
__func__.2844:
	.string	"unsorted_bitwise"
	.align 16
	.type	__func__.2853, @object
	.size	__func__.2853, 17
__func__.2853:
	.string	"unsorted_ternary"
	.text
.Letext0:
	.file 2 "/usr/include/x86_64-linux-gnu/bits/types.h"
	.file 3 "/usr/include/time.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x3b8
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF26
	.byte	0x1
	.long	.LASF27
	.long	.LASF28
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF7
	.uleb128 0x4
	.long	.LASF10
	.byte	0x2
	.byte	0x87
	.long	0x5e
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF8
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF9
	.uleb128 0x4
	.long	.LASF11
	.byte	0x3
	.byte	0x3b
	.long	0x6c
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF12
	.uleb128 0x5
	.byte	0x8
	.long	0x9d
	.uleb128 0x6
	.uleb128 0x7
	.long	.LASF20
	.byte	0x1
	.byte	0x12
	.long	0x57
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0xd8
	.uleb128 0x8
	.string	"a"
	.byte	0x1
	.byte	0x12
	.long	0x97
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x8
	.string	"b"
	.byte	0x1
	.byte	0x12
	.long	0x97
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.byte	0
	.uleb128 0x9
	.long	.LASF13
	.byte	0x1
	.byte	0x17
	.quad	.LFB3
	.quad	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x123
	.uleb128 0xa
	.long	.LASF15
	.long	0x133
	.uleb128 0x9
	.byte	0x3
	.quad	__func__.2811
	.uleb128 0xb
	.string	"i"
	.byte	0x1
	.byte	0x1a
	.long	0x57
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xb
	.string	"sum"
	.byte	0x1
	.byte	0x1b
	.long	0x7e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0xc
	.long	0x77
	.long	0x133
	.uleb128 0xd
	.long	0x65
	.byte	0x9
	.byte	0
	.uleb128 0xe
	.long	0x123
	.uleb128 0x9
	.long	.LASF14
	.byte	0x1
	.byte	0x26
	.quad	.LFB4
	.quad	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.long	0x18f
	.uleb128 0xa
	.long	.LASF15
	.long	0x19f
	.uleb128 0x9
	.byte	0x3
	.quad	__func__.2819
	.uleb128 0xb
	.string	"i"
	.byte	0x1
	.byte	0x29
	.long	0x57
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xb
	.string	"t"
	.byte	0x1
	.byte	0x29
	.long	0x57
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xb
	.string	"sum"
	.byte	0x1
	.byte	0x2a
	.long	0x7e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0xc
	.long	0x77
	.long	0x19f
	.uleb128 0xd
	.long	0x65
	.byte	0xe
	.byte	0
	.uleb128 0xe
	.long	0x18f
	.uleb128 0x9
	.long	.LASF16
	.byte	0x1
	.byte	0x33
	.quad	.LFB5
	.quad	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.long	0x1ef
	.uleb128 0xa
	.long	.LASF15
	.long	0x1ef
	.uleb128 0x9
	.byte	0x3
	.quad	__func__.2828
	.uleb128 0xb
	.string	"i"
	.byte	0x1
	.byte	0x36
	.long	0x57
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xb
	.string	"sum"
	.byte	0x1
	.byte	0x37
	.long	0x7e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0xe
	.long	0x18f
	.uleb128 0x9
	.long	.LASF17
	.byte	0x1
	.byte	0x3f
	.quad	.LFB6
	.quad	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.long	0x23f
	.uleb128 0xa
	.long	.LASF15
	.long	0x24f
	.uleb128 0x9
	.byte	0x3
	.quad	__func__.2836
	.uleb128 0xb
	.string	"i"
	.byte	0x1
	.byte	0x42
	.long	0x57
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xb
	.string	"sum"
	.byte	0x1
	.byte	0x43
	.long	0x7e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0xc
	.long	0x77
	.long	0x24f
	.uleb128 0xd
	.long	0x65
	.byte	0xb
	.byte	0
	.uleb128 0xe
	.long	0x23f
	.uleb128 0x9
	.long	.LASF18
	.byte	0x1
	.byte	0x4e
	.quad	.LFB7
	.quad	.LFE7-.LFB7
	.uleb128 0x1
	.byte	0x9c
	.long	0x2ab
	.uleb128 0xa
	.long	.LASF15
	.long	0x2bb
	.uleb128 0x9
	.byte	0x3
	.quad	__func__.2844
	.uleb128 0xb
	.string	"i"
	.byte	0x1
	.byte	0x51
	.long	0x57
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xb
	.string	"t"
	.byte	0x1
	.byte	0x51
	.long	0x57
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xb
	.string	"sum"
	.byte	0x1
	.byte	0x52
	.long	0x7e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0xc
	.long	0x77
	.long	0x2bb
	.uleb128 0xd
	.long	0x65
	.byte	0x10
	.byte	0
	.uleb128 0xe
	.long	0x2ab
	.uleb128 0x9
	.long	.LASF19
	.byte	0x1
	.byte	0x5b
	.quad	.LFB8
	.quad	.LFE8-.LFB8
	.uleb128 0x1
	.byte	0x9c
	.long	0x30b
	.uleb128 0xa
	.long	.LASF15
	.long	0x30b
	.uleb128 0x9
	.byte	0x3
	.quad	__func__.2853
	.uleb128 0xb
	.string	"i"
	.byte	0x1
	.byte	0x5e
	.long	0x57
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xb
	.string	"sum"
	.byte	0x1
	.byte	0x5f
	.long	0x7e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0xe
	.long	0x2ab
	.uleb128 0xf
	.long	.LASF21
	.byte	0x1
	.byte	0x67
	.long	0x57
	.quad	.LFB9
	.quad	.LFE9-.LFB9
	.uleb128 0x1
	.byte	0x9c
	.long	0x369
	.uleb128 0x10
	.long	.LASF22
	.byte	0x1
	.byte	0x69
	.long	0x369
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0xb
	.string	"i"
	.byte	0x1
	.byte	0x6a
	.long	0x57
	.uleb128 0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0xb
	.string	"c"
	.byte	0x1
	.byte	0x6a
	.long	0x57
	.uleb128 0x3
	.byte	0x91
	.sleb128 -76
	.uleb128 0x10
	.long	.LASF23
	.byte	0x1
	.byte	0x6b
	.long	0x85
	.uleb128 0x3
	.byte	0x91
	.sleb128 -72
	.byte	0
	.uleb128 0xc
	.long	0x379
	.long	0x379
	.uleb128 0xd
	.long	0x65
	.byte	0x5
	.byte	0
	.uleb128 0x5
	.byte	0x8
	.long	0x37f
	.uleb128 0x11
	.uleb128 0xc
	.long	0x57
	.long	0x391
	.uleb128 0x12
	.long	0x65
	.value	0x7fff
	.byte	0
	.uleb128 0x13
	.long	.LASF24
	.byte	0x1
	.byte	0x10
	.long	0x380
	.uleb128 0x9
	.byte	0x3
	.quad	data
	.uleb128 0x13
	.long	.LASF25
	.byte	0x1
	.byte	0x10
	.long	0x380
	.uleb128 0x9
	.byte	0x3
	.quad	sdata
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x26
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x34
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x15
	.byte	0
	.uleb128 0x27
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF13:
	.string	"sorted_if"
.LASF17:
	.string	"unsorted_if"
.LASF22:
	.string	"functions"
.LASF15:
	.string	"__func__"
.LASF11:
	.string	"clock_t"
.LASF24:
	.string	"data"
.LASF1:
	.string	"unsigned char"
.LASF0:
	.string	"long unsigned int"
.LASF26:
	.string	"GNU C 4.8.4 -mtune=generic -march=x86-64 -g -fstack-protector"
.LASF2:
	.string	"short unsigned int"
.LASF19:
	.string	"unsorted_ternary"
.LASF27:
	.string	"branch_preditction.c"
.LASF21:
	.string	"main"
.LASF16:
	.string	"sorted_ternary"
.LASF3:
	.string	"unsigned int"
.LASF28:
	.string	"/home/charlesoliveira/src/chaws/personal/weird_c"
.LASF12:
	.string	"long long unsigned int"
.LASF23:
	.string	"elapsed"
.LASF25:
	.string	"sdata"
.LASF18:
	.string	"unsorted_bitwise"
.LASF14:
	.string	"sorted_bitwise"
.LASF10:
	.string	"__clock_t"
.LASF7:
	.string	"sizetype"
.LASF9:
	.string	"long long int"
.LASF8:
	.string	"char"
.LASF5:
	.string	"short int"
.LASF6:
	.string	"long int"
.LASF4:
	.string	"signed char"
.LASF20:
	.string	"compare"
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
