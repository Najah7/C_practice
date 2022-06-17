#include <stdio.h>
#define MAX 10000
 
int main(void)
{
  int i,n;
  int N[MAX];
   
  for(i=0;i<MAX;i++) N[i]=0; // 素数候補として全て0に初期化
  N[0]=N[1]=1;               // 0と1は素数でないため候補から除外
 
  for(n=2;n*n<MAX;n++)
  {
    if(N[n]!=0) continue;          // nが素数でない場合
    for(i=n*n;i<MAX;i+=n
) N[i]=1; // nの倍数を候補から除外
  }
   
  for(i=0;i<MAX;i++) if(N[i]==0)printf("%d ",i); // 素数を表示
  printf("\n");
 
  return 0;
}