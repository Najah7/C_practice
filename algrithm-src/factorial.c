#include <stdio.h>
#include <string.h>

int func(int n);

int main()
{
    int n = 0;

    printf("正の整数を入力："); scanf("%d", &n);
    if (n > 0) printf("%d! = %d \n", n, func(n));
    return 0;
}

int func(int n)
{
    if (n == 1) return 1;
    return (n * func(n-1));
}