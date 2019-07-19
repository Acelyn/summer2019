.cpu cortex-a7 
.text
.align 2
.global fastpow


fastpow:
	mov r2, #1   // rv = 1
	mov r3, r0  // curr_pow = x
	b while_fastpow

while_fastpow:
	cmp r1, #0 // y ? 0
	ble end_while  // y <= 0
	and r0, r1, #1 // y % 2 == ?
	cmp r0, #1 // if y % 2 == 1 or not
	beq iftrue // y % 2 == 1
	mov r0,#2
	sdiv r1, r1,r0  // y = y /2
	mul r3, r3, r3  // curr_pow = curr_pow * curr_pow
	b while_fastpow

iftrue:
	mul r2, r2, r3  //  rv = rv * curr_pow;
	mov r0, #2
	sdiv r1, r1,r0  // y = y /2
	mul r3, r3, r3   // curr_pow = curr_pow * curr_pow
	b while_fastpow



end_while:
	mov r0, r2
	bx	lr	
