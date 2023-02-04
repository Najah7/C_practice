#include <stdio.h>

#define MAX_NUM 10

int queue[MAX_NUM];
int first = 0;
int last = 0;

void enqueue(int data)
{
    if ((last+1)%MAX_NUM == first)
    {
    	printf("キューは満杯で、追加できません");
        return;
    }
    queue[last] = data;
    last = (last + 1) % MAX_NUM;
    return;
}

int dequeue(void)
{
    if (first == last)
    {
    	printf("キューにデータがありません");
        return -1;
    }
    int retval = queue[first];
    first++;
    return retval;
}

void print_queue(void)
{
    int i;
    for (i = first; i <= last; i++) printf("%d\n",queue[i]);
}

int firstdata_queue(void)
{
    return queue[first];
}

void main(void)
{
   int rc,data;
   char menu[4][20]={"","カレー","牛丼","ラーメン"};
 
   while(1){
      printf("\nカレー:1 牛丼:2 ラーメン:3 出来上がり:0 キュー表示:-1\n");
      printf("注文を入力 : ");
      scanf("%d",&data);
      switch(data){
         case -1:
            printf("\n＝調理待ちリスト＝\n");
            print_queue();
            break;
         case 0:
            rc=dequeue();
            if(rc != -1) printf("%sできあがりですね\n",menu[rc]);
            rc=firstdata_queue();
            if(rc != -1) printf("次は%sです\n",menu[rc]);
            break;
         case 1:
         case 2:
         case 3:
            enqueue(data);
            printf("%s の注文を登録しました\n",menu[data]);
            break;
         default:
            printf("終了します\n"); return;
      }
   }
   return;
}