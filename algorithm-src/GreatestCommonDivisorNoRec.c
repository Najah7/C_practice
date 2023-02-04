#include <stdio.h>
#include <string.h>

int GCD_no_rec(int n, int m);

int main()
{
    int n, m;
    n = m = 0;

    printf("値１："); scanf("%d", &n);
    printf("値２："); scanf("%d", &m);
    if (n > 0 || m > 0) printf("%dと%d最大公約数は%dです。\n", n, m, GCD_no_rec(n, m));
    else printf("正の整数限定です。");
    return 0;
}

int GCD_no_rec( int A, int B)
{
    int i,i0;
     
    if(A<B) i0=A;
    else i0=B;
     
    for(i=i0;i>=1;i--){
        if((A%i==0)&&(B%i==0)) return i;
    }
}