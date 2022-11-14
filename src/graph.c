#include <stdio.h>
 
int main(void)
{
  int i,h,height[4];

  for(i=0;i<4;i++)
  {
    printf("身長（整数で入力）:");
    scanf("%d",&height[i]);
  }
 
  printf("\n");
  for(i=0;i<4;i++)
  {
    printf("%d\t",height[i]);
    for(h=0;h<height[i]/10;h++) printf("*");
    printf("\n");
  }
  printf("\n");
   
  return 0;
}
