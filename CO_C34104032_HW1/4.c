// description: matrix multiply without for loop
#include<stdio.h>
    int main(){
    int i=0;
    int h[9]={0}, x[3]={0}, y[3]={0};
    FILE *input = fopen("../input/4.txt","r");
    for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
    for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
    for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
    fclose(input);
    int *p_x = &x[0] ;
    int *p_h = &h[0] ;
    int *p_y = &y[0] ;
    asm volatile(
        "li t3, 0\n\t" //counter1
        "li t4, 3\n\t" 
        "li t5, 0\n\t" //counter2
        "addi t6, %[p_x], 0\n\t"

        "loop1: \n\t" //outer loop
        "addi t3, t3, 1\n\t" //count1 ++
        "addi %[p_x], t6, 0\n\t" //copy t3's value into p_x(reset)
        "li t5, 0\n\t" //reset counter2

        "loop2: \n\t" //inner loop
        "addi t5, t5, 1\n\t" //count2 ++
        "lw t0, 0(%[p_x])\n\t" 
        "lw t1, 0(%[p_h])\n\t" 
        "lw t2, 0(%[p_y])\n\t" 
        "mul t0, t0, t1\n\t"  //x * h 
        "add t2, t2, t0\n\t"   
        "sw t2, 0(%[p_y])\n\t" 
        "addi %[p_x], %[p_x], 4\n\t"
        "addi %[p_h], %[p_h], 4\n\t"
        "blt t5, t4, loop2\n\t" //jump
        "addi %[p_y], %[p_y], 4\n\t"
        "blt t3, t4, loop1\n\t" //jump
        : [p_x] "+r" (p_x), [p_h] "+r" (p_h), [p_y] "+r" (p_y)
        : 
        : "t0", "t1", "t2", "t3", "t4", "t5", "t6"
        //"t0":for p_x,"t1": p_h, "t2": p_y's value, "t3": counter1, "t4": 3,"t5": counter2,"t6": original p_x
    );
    p_y = &y[0];
    for(i = 0; i<3; i++)
    printf("%d \n", *p_y++);
    return(0) ;

}