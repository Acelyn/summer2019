.cpu cortex-a7
.text
.align 2 //instruction are aligned on a four
.global array_sum


 array_sum:
 	mov r2, #0 //sum = 0
 	mov r3, #0 // i = 0
 begin_while_array_sum:
 	cmp r3, r1
 	bge end_while_array_sum
 	ldr r4, [r0, #0] // r4 = mem[r0+0]  r0 is the address of the first array in memory
 	add r2, r2, r4
 	add r3, r3, #1
 	add r0, r0, #4 // move to next array element
 	b begin_while_array_sum
 end_while_array_sum:
 	mov r0, r2
	bx	lr

