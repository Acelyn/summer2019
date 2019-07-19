.cpu cortex-a7
.text
.align 2
.global power

power:
	sub sp, sp,#12 
	str r14, [sp, #0]
	str r4, [sp, #4]
	str r5, [sp, #8]

	mov r4, r0 // store x0 in x19
	mov r5, r1 // store x1 in x20
	cmp r5, #0 // if y == 0 or not
	bne power_else   // y == 0
	mov r0, #1  // return 1
	ldr r5, [sp,#8]
	ldr r4, [sp,#4] 
	ldr r14, [sp,#0]
	add sp,sp,#12
	bx	lr	

power_else:
	and r1, r5, #1  // y % 2 = ?
	cmp r0,#0   // if y % 2 == 0 or not
	bne power_of_odd   // y % 2 != 0
	beq power_of_even  // y % 2 == 0

power_of_odd:
	sub r1, r5, #1 // y = y -1
	bl power  // power_c(x,y/2);
	mul r0, r4, r0  // return x*power_c(x,y-1)
	ldr r5, [sp,#8]
	ldr r4, [sp,#4]
	ldr r14, [sp,#0 ]
	add sp,sp,#12
	bx	lr	

power_of_even:
	lsr r1, r5, #1  // y = y / 2
	bl power   //  power_c(x,y/2)
	mul r0, r0, r0  //  return power_c(x,y/2)* power_c(x,y/2);
	ldr r5, [sp, #8]
	ldr r4, [sp, #4]
	ldr r14, [sp,#0]
	add sp,sp,#12
	bx	lr	

