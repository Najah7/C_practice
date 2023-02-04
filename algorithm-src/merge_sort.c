#include <stdio.h>
#define N 8

int tmp[N];
int COMPARE_COUNT,MOVE_COUNT;

void MergeSort(int x[], int min, int max)
{
    int mid, i, j, k;
    
    if (min >= max) return;
    
    mid = (min+max)/2;
    MergeSort(x, min, mid);
    MergeSort(x, mid+1, max);
    
    i=min; j=mid+1;
    for (k = min; k <= max; k++)
    {
    	if (i <= mid && j <= max)
        {
            if (x[i] <= x[j])
            {
                tmp[k] = x[i]; i++;
            }
            else
            {
                tmp[k] = x[j]; j++;
            }
        	COMPARE_COUNT++;
        }
        else if (i <= mid)
        {
            tmp[k] = x[i]; i++;
        }
        else
        {
            tmp[k] = x[j]; j++;
        }
        MOVE_COUNT++;
    }
    for (k = min; k <= max; k++) 
    {
        x[k]=tmp[k];
        MOVE_COUNT++;
    }
}

void main(void)
{
    int i;
    int data[N]={3,2,8,5,7,1,6,4};
 
    printf("\n並べ替え前\n");
    for(i=0;i<N;i++)printf("%d\t",data[i]);
    printf("\n");
 
    COMPARE_COUNT=MOVE_COUNT=0;
    MergeSort(data,0,N-1);
    printf("\n比較%d回、移動%d回\n",COMPARE_COUNT,MOVE_COUNT);
 
    printf("\n並べ替え後\n");
    for(i=0;i<N;i++) printf("%d\t",data[i]);
    printf("\n");
 
    return; 
}
