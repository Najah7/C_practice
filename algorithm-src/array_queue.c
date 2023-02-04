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