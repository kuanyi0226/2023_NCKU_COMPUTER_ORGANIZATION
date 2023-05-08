// TODO : 
"addi x18, x0, 16\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"loop:\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"

"lh x20, 0(%[h])\n\t"
"lh x21, 0(%[x])\n\t"
"addi %[lw_cnt], %[lw_cnt], 2\n\t"

"add x22, x20, x21\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"sh x22, 0(%[y])\n\t"
"addi %[sw_cnt], %[sw_cnt], 1\n\t"

"addi %[h], %[h], 2\n\t"
"addi %[x], %[x], 2\n\t"
"addi %[y], %[y], 2\n\t"
"addi x18, x18, -1\n\t"
"addi %[arith_cnt], %[arith_cnt], 4\n\t"


"bnez x18, loop\n\t"
