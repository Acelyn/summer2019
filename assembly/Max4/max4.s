.cpu cortex-a7
.text
.align 2
.global max4,max

max:
	cmp r0, r1
	blt endif_max
	bx	lr

endif_max:
	mov r0, r1
	bx	lr

max4:
	push {r4-r6, lr}
        //sub sp, sp, #16
	//str lr, [sp,#0]  // save frame pointer
	//str r15, [sp,#4]
	//str r4, [sp,#8]  // save the registers that must be preserved across a call
	//str r5, [sp, #12]
	//str r6, [sp, #16]


	mov r4, r2
	mov r5, r3  //save y and z
	bl max // compute max of x0, x1
	mov r6, r0  // make sure we save return result

	mov r0, r4
	mov r1, r5
	bl max

	mov r1, r6 // put result of first call to max in x1
	bl max

        pop {r4-r6, lr}
	//ldr r6, [sp, #16]
	//ldr r5, [sp, #12]
	//ldr r4, [sp, #8]
	//ldr r15, [sp,#4]
	//ldr lr, [sp, #0]
	//add sp, sp, #16
	bx	lr


