#include <stdio.h>

int main(void)
{
  int i, weight, ryoukin;
  int table[2][6] = {{50, 100, 150, 250, 500, 1000},
                     {120, 140, 210, 250, 390, 580}};

  printf("重さ(g)を入力: ");
  scanf("%d", &weight);
  if (weight > 1000)
  {
    printf("規格外です\n");
    return -1;
  }

  for (i = 5; i >= 0; i--)
  {
    if (weight <= table[0][i])
      ryoukin = table[1][i];
  }

  printf("料金は %d 円です\n", ryoukin);
  return 0;
}
