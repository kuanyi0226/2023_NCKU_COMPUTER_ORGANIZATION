//description: cn = an * bn
#include <stdio.h>

int main(){
    int a[10] = {0}, b[10] = {0}, c[10] = {0};
    int i, arr_size = 10;
    FILE *input = fopen("../input/2.txt", "r");
    for(i = 0; i < arr_size; i++) fscanf(input, "%d", &a[i]);
    for(i = 0; i < arr_size; i++) fscanf(input, "%d", &b[i]);
    for(i = 0; i < arr_size; i++) fscanf(input, "%d", &c[i]);
    fclose(input);

    int *p_a = &a[0];
    int *p_b = &b[0];
    int *p_c = &c[0];

    /*
    original C code:
    for(int i = 0; i < arr_size; i++)
        *p_c++ = *p_a++ * *p_b++;
    */
    for(int i = 0; i < arr_size; i++)
        asm volatile(
            "mul %[A], %[B], %[C]\n\t"
            "addi %[D], %[D], 4\n\t"
            "addi %[E], %[E], 4\n\t"
            "addi %[F], %[F], 4\n\t"
            :[A] "=r"(*p_c), [B] "+r"(*p_a), [C] "+r"(*p_b), [D] "+r"(p_c), [E] "+r"(p_a), [F] "+r"(p_b)
            :
        ); //"+": both input and output

    p_c = &c[0];
    for(int i = 0; i < arr_size; i++)
        printf("%d ", *p_c++);
    
    return 0;
}