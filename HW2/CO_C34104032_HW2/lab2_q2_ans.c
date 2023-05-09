// TODO : 
"addi t1, x0, 8\n\t"//length of x[8] 
"addi t2, %[p_x], 14\n\t"//address of x[8] 
"addi t5, x0, -1\n\t" //for judge jump to SETflag

"loop2:\n\t"
"vsetvli t0, t1, e16, ta, ma\n\t"
"vle16.v v0, (%[p_x])\n\t" //load x

"lh t3, 0(t2)\n\t"
"addi t2, t2, -2\n\t"//address minus 2

"vadd.vx v1, v0, t3\n\t" //v1 = v0 + t3
"vmseq.vx v2, v1, %[target]\n\t" //=flag?

"vfirst.m t4, v2\n\t" //find 1 then set 1, else set -1
"bne t4, t5, SETflag\n\t" //check whether the flag is set

"bge t2, %[p_x], loop2\n\t" //jump back to loop2
"beq x0, x0, EXIT\n\t" //directly jump to EXIT

"SETflag:\n\t"
"addi %[flag], %[flag], 1\n\t" //set flag

"EXIT:\n\t"

