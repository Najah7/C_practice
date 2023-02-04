#include <stdio.h>
#include <math.h>
#define N 1000
 
int COUNT;
 
int prime(int x[])
{
    int i,j,n=0;
    int p[N];
 
    for(i=0;i<N;i++) p[i]=0;  //初期化
    for(j=2;j<sqrt(N);j++){
        if(p[j]==0) for(i=j*j;i<N;i=i+j) p[i]=1;  // 倍数のチェック
    }
 
    for(i=2;i<N;i++){
        if(p[i]==0){      // i が素数なら
            x[n]=i; n++;  // 配列 x に格納
            printf("%d\t",i);  //表示
        }
    }
    printf("\n\n");
    return n;
}
 
int BinarySearch(int x[],int n,int y)
{
    int min,mid,max;
    min=0;
    max=n-1;
    while(min<=max){
        mid=(min+max)/2;
        COUNT++;
        if(x[mid]<y) min=mid+1;
        else if(x[mid]>y) max=mid-1;
        else return mid;
    }
    return -1;
}
 
int LinearSearch(int x[],int n,int y)
{
    int i=0;
    while(i<n){
        COUNT++;
        if(x[i]==y) return i;
        else i++;
    }
    return -1;
}
 
void main()
{
    int data[N];
    int n,target,rc;
 
    n=prime(data);   // nの素数を配列dataに格納 
 
    printf("目標データ（%d未満の数）を入力：",N);
    scanf("%d",&target);
 
    printf("\n線形探索\n");
    COUNT=0;
    rc = LinearSearch(data,n,target);
    if(rc==-1) printf("素数ではありません\n");
    else printf("%d 番目の素数です\n",rc+1);
    printf("%d 個の素数について調べました\n",COUNT);
 
    printf("\n二分探索\n");
    COUNT=0;
    rc = BinarySearch(data,n,target);
    if(rc==-1) printf("素数ではありません\n");
    else printf("%d 番目の素数です\n",rc+1);
    printf("%d 個の素数について調べました\n",COUNT);
 
    return;
}