	.arch armv6
	.text
	.align	2
	.global	binary_checksum_c
	.arm
binary_checksum_c:
	subs	r3, r0, #0
	mov	r0, #0
	ble	endwhile
while:
	and	r2, r3, #1
	asrs	r3, r3, #1
	add	r0, r0, r2
	bne	while	
	bx	lr
endwhile:
	bx	lr
