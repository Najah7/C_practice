// マージソートの作業領域を半分にするバージョンのマージソート


#include <stdio.h>
#define N 8
 
int tmp[N/2];
int COMPARE_COUNT,MOVE_COUNT;
 
void MergeSort(int x[ ], int min, int max)
{
    int mid,i,j,k;
 
    if(min>=max) return; //再帰の終了条件
 
    mid = (min+max)/2;
    MergeSort(x,min,mid);
    MergeSort(x,mid+1,max);
 
    //前半分をtmpにコピー
    for(i=min,k=0;i<=mid;i++,k++){tmp[k]=x[i];MOVE_COUNT++;}
 
    i=min; j=mid+1; k=0;
    for(i=min;i<=max;i++){
        if(j<=max && k<=mid-min){
            if(tmp[k]<=x[j]){
                x[i]=tmp[k]; k++;
            }else{
                x[i]=x[j]; j++;
            }
            COMPARE_COUNT++;
        }else if(j<=max){
            x[i]=x[j]; j++;
        }else{
            x[i]=tmp[k]; k++;
        }
        MOVE_COUNT++;
    }
    return;
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