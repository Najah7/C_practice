#include <stdio.h>

#define MAX_NUM 10

int stack[MAX_NUM];
int num = 0;

void push(int data)
{
    if (num == MAX_NUM)
    {
    	printf("これ以上、スタックに積めません");
        return;
    }
    stack[num] = data;
    num ++;
    return;
}

int pop(void)
{
    if (num == 0)
    {
    	printf("スタックにデータがありません\n");
        return -1;
    }
    num--;
    return stack[num];
    
}