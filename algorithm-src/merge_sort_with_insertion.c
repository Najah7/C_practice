// データ数が少ない時に基本挿入法を用いるマージソート

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define N 1000
 
int tmp[N];
int COMPARE_COUNT,MOVE_COUNT;
 
void GenerateRandomData(int range,int Data[],int num)
{
    int i;
    srand(time(NULL));
    for(i=0;i<num;i++){
        Data[i]=rand()%range+1;
        //printf("%d\t",Data[i]);
    }
    printf("\n");
    return;
}
 
void InsertionSort(int x[],int n)
{
    int i,j,tmp;
 
    for(j=1;j<n;j++){
        tmp=x[j]; MOVE_COUNT++;
        for(i=j-1;i>=0;i--){
            COMPARE_COUNT++;
            if(x[i]>tmp){ x[i+1]=x[i]; MOVE_COUNT++; }
            else break;
        }
        x[i+1]=tmp; MOVE_COUNT++;
    }
    return;
}
 
void MergeSort_I(int x[ ], int min, int max)
{
    int mid,i,j,k;
 
    if(min>=max) return; //再帰の終了条件
 
    if(max-min<8){
        InsertionSort(x+min,max-min+1);
        return;
    }
 
    mid = (min+max)/2;
    MergeSort_I(x,min,mid);
    MergeSort_I(x,mid+1,max);
 
    i=min; j=mid+1;
    for(k=min;k<=max;k++){
        if(i<=mid && j<=max){
            if(x[i]<=x[j]){
                tmp[k]=x[i]; i++;
            }else{
                tmp[k]=x[j]; j++;
            }
        }else if(i<=mid){
            tmp[k]=x[i]; i++;
        }else{
            tmp[k]=x[j]; j++;
        }
        MOVE_COUNT++;
    }
    for(k=min;k<=max;k++){x[k]=tmp[k]; MOVE_COUNT++;}
    return;
}
 
void main()
{
    int i;
    int data[N];
     
    GenerateRandomData(N,data,N);
    printf("データ数 %d\n",N); //データ数の表示
 
    printf("\n=基本挿入法も利用したマージソート＝\n");
    COMPARE_COUNT=MOVE_COUNT=0;
    MergeSort_I(data,0,N-1);
    printf("比較%d回、移動%d回\n",COMPARE_COUNT,MOVE_COUNT);
     
    return;
}