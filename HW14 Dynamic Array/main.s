	.file	"main.cc"
	.text
	.p2align 4
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB3137:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.p2align 4
	.globl	_Z10polar2rectddRdS_
	.def	_Z10polar2rectddRdS_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z10polar2rectddRdS_
_Z10polar2rectddRdS_:
.LFB2460:
	.seh_endprologue
	movq	.LC0(%rip), %rax
	movq	%rax, (%r8)
	movq	.LC1(%rip), %rax
	movq	%rax, (%r9)
	ret
	.seh_endproc
	.p2align 4
	.globl	_Z10polar2rectdd
	.def	_Z10polar2rectdd;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z10polar2rectdd
_Z10polar2rectdd:
.LFB2461:
	.seh_endprologue
	movupd	.LC2(%rip), %xmm0
	movq	%rcx, %rax
	movups	%xmm0, (%rcx)
	ret
	.seh_endproc
	.p2align 4
	.globl	_Z11polar2rect3ddRdS_
	.def	_Z11polar2rect3ddRdS_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z11polar2rect3ddRdS_
_Z11polar2rect3ddRdS_:
.LFB2462:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$72, %rsp
	.seh_stackalloc	72
	movups	%xmm6, 48(%rsp)
	.seh_savexmm	%xmm6, 48
	.seh_endprologue
	movapd	%xmm0, %xmm6
	movq	%r8, %rsi
	movapd	%xmm1, %xmm0
	movq	%r9, %rbx
	leaq	40(%rsp), %rdx
	leaq	32(%rsp), %r8
	call	sincos
	movsd	32(%rsp), %xmm0
	mulsd	%xmm6, %xmm0
	movsd	%xmm0, (%rsi)
	mulsd	40(%rsp), %xmm6
	movsd	%xmm6, (%rbx)
	movups	48(%rsp), %xmm6
	addq	$72, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.section	.text.startup,"x"
	.p2align 4
	.def	_GLOBAL__sub_I__Z10polar2rectddRdS_;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z10polar2rectddRdS_
_GLOBAL__sub_I__Z10polar2rectddRdS_:
.LFB3138:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	addq	$40, %rsp
	jmp	atexit
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__Z10polar2rectddRdS_
.lcomm _ZStL8__ioinit,1,1
	.set	.LC0,.LC2
	.set	.LC1,.LC2+8
	.section .rdata,"dr"
	.align 16
.LC2:
	.long	0
	.long	1075052544
	.long	0
	.long	1076953088
	.ident	"GCC: (Rev2, Built by MSYS2 project) 12.1.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	sincos;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
