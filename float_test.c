#include <stdio.h>

int digit_counter(int num)
{
    return(num / 10);
}

int main()
{
    float int_float;

    int_float = 1;
    printf("%f\n", int_float);
    printf("%d", digit_counter(int_float));
}