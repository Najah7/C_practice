#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int Data[100];
  int i, m, n, tmp;

  for (i = 0; i < 100; i++)
    Data[i] = rand() % 100; // データ生成

  printf("＊＊ 並べ替え前 ＊＊\n");
  for (i = 0; i < 100; i++)
    printf("%d  ", Data[i]);

  // 並べ替え処理
  for (n = 100; n > 0; n--)
  {
    m = n;
    for (i = 0; i < n; i++)
    {
      if (Data[i] > Data[m])
        m = i;
    }
    tmp = Data[m];
    Data[m] = Data[n];
    Data[n] = tmp;
  }

  printf("\n\n＊＊ 並べ替え後 ＊＊\n");
  for (i = 0; i < 100; i++)
    printf("%d  ", Data[i]);
  printf("\n");

  return 0;
}