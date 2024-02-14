	global	main
	extern	printf
	section	.text
LC0:	db	"%d",10,0
printint:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 16
	mov	[rbp-4], edi
	mov	eax, [rbp-4]
	mov	esi, eax
	lea	rdi, [rel LC0]
	mov	eax, 0
	call	printf
	nop
	leave
	ret

main:
	push	rbp
	mov	rbp, rsp
	common	fred 8:8
	common	jim 8:8
	mov	r8, 5
	mov	[fred], r8
	mov	r8, 12
	mov	[jim], r8
	mov	r8, [fred]
	mov	r9, [jim]
	add	r9, r8
	mov	rdi, r9
	call	printint
	mov	eax, 0
	pop	rbp
	ret
