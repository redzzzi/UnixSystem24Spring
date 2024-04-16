	.file	"loop.c"
	.text
	.globl	pcount_for
	.type	pcount_for, @function
pcount_for:
.LFB23:
	.cfi_startproc
	endbr64
	movl	$0, %edx
	movl	$0, %ecx
	jmp	.L2
.L3:
	movq	%rdi, %rax
	shrq	%cl, %rax
	andl	$1, %eax
	addq	%rax, %rdx
	addq	$1, %rcx
.L2:
	cmpq	$31, %rcx
	jbe	.L3
	movq	%rdx, %rax
	ret
	.cfi_endproc
.LFE23:
	.size	pcount_for, .-pcount_for
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	endbr64
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
