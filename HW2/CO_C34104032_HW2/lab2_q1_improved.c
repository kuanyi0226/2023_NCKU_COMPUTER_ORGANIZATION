// TODO : 
"addi t1, x0, 16\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"loop1:\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"

"vsetvli t0, t1, e16, ta, ma\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"

"vle16.v v0, (%[x])\n\t"
"addi %[lw_cnt], %[lw_cnt], 1\n\t"

"sub t1, t1, t0\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"slli t0, t0, 1\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"add %[x], %[x], t0\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"vle16.v v1, (%[h])\n\t"
"addi %[lw_cnt], %[lw_cnt], 1\n\t"

"add %[h], %[h], t0\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"vadd.vv v2, v0, v1\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"vse16.v v2, (%[y])\n\t"
"addi %[sw_cnt], %[sw_cnt], 1\n\t"

"add %[y], %[y], t0\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"bnez t1, loop1\n\t"

