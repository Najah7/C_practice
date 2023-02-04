#include <stdio.h>
#include <string.h>

int COMPARE_COUNT, SWAP_COUNT;


void QuickSort(int x[],int min, int max)
{
    int p, i, j, tmp;
    
    if (min >= max) return;
    
    p = (x[min] + x[max]) / 2;
    
    i = min;
    j = max;
    
    while(1)
    {
        while(x[i] < p)
        {
            i++;
            COMPARE_COUNT++;
        }
        COMPARE_COUNT++;
        while(x[j] > p)
        {
            j--;
            COMPARE_COUNT++;
        }
        COMPARE_COUNT++;
        if (j <= i) break;
        tmp=x[i]; x[i] = x[j]; x[j] = tmp;
        i++; j--;
        SWAP_COUNT++;
    }
    
    QuickSort(x, min, i - 1);
    QuickSort(x, j + 1, max);
    
    return;
}


void main()
{
    int i;
    int data[8]={30,20,80,50,70,10,60,40};
    COMPARE_COUNT = SWAP_COUNT = 0;
 
    printf("\n並べ替え前\n");
    for(i=0;i<8;i++)printf("%d\t",data[i]);
    printf("\n");
 
    COMPARE_COUNT=SWAP_COUNT=0;
    QuickSort(data,0,7);
    printf("\n比較%d回、交換%d回\n",COMPARE_COUNT,SWAP_COUNT);
     
    printf("\n並べ替え後\n");
    for(i=0;i<8;i++) printf("%d\t",data[i]);
    printf("\n");
     
    return;
}