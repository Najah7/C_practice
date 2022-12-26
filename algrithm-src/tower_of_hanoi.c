#include <stdio.h>
#include <string.h>

void hanoi(int n,char start,char temp,char end);

int main()
{
    int n;
  printf("円盤の枚数："); scanf("%d",&n);
  hanoi(n,'A','B','C');
  return 0;
}

void hanoi(int n,char start,char temp,char end)
{
  if(n>0){
    hanoi(n-1,start,end,temp);
    printf("%d番目の円盤を%cから%cへ\n",n,start,end);
    hanoi(n-1,temp,start,end);
  }
}