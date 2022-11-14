#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int computer, user;
  srand(time(NULL));
  while (1)
  {
    printf("\n===じゃんけん===\n");
    printf("グー:1  チョキ:2  パー:3  (0で終了） : ");
    scanf("%d", &user);
    printf("あなたは ");
    switch (user)
    {
    case 0:
      return 0;
    case 1:
      printf("グー    ");
      break;
    case 2:
      printf("チョキ  ");
      break;
    case 3:
      printf("パー    ");
      break;
    default:
      continue;
    }
    printf("コンピュータは ");
    computer = rand() % 3 + 1;
    switch (computer)
    {
    case 1:
      printf("グー    ");
      break;
    case 2:
      printf("チョキ  ");
      break;
    case 3:
      printf("パー    ");
      break;
    }
    if (user == computer)
      printf("あいこ！\n");
    else if (user % 3 == computer - 1)
      printf("あなたの勝ち！\n");
    else
      printf("コンピュータの勝ち！\n");
  }
  return 0;
}
