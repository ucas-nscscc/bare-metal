// #include <stdio.h>

int fib(int end_i)
{
    int i;
    // scanf("%d", &end_i);
    int f0 = 1, f1 = 1, f2, sum;
    if (end_i == 1) sum = 1;
    else if (end_i == 2) sum = 2;
    else {
        sum = f0 + f1;
        for (i = 2; i < end_i; i++) {
            f2 = f0 + f1;
            f0 = f1;
            f1 = f2;
            sum += f2;
        }
    }

    // printf("sum is %d\n", sum);
    return sum;
}
