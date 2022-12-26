#include <stdio.h>
#include <string.h>
#define N 8  // データ件数
 
typedef struct person{
    int id;
    char name[20];
}Person;

// 下記のカウントを探索の繰り返しの中に入れることで評価回数を数える時に使える
int COUNT;

int LinearSearch(int x[],int n,int y);
int SnetinelSearch(int x[],int n,int y);
int LinearSearch_id(Person x[],int n, int y);
int LinearSearch_name(Person x[],int n, char y[]);
int BinarySearch(int x[], int n, int y);



void main()
{
    // Person data[N]={{101,"Ann"},{202,"Bob"},
    //                {303,"Carol"},{404,"Jack"},{505,"Karen"},
    //                {606,"Lucy"},{707,"Maria"},{808,"Ted"}};
    // int  target_id;
    // char target_name[20];
    // int  rc;
 
    // // 会員番号で検索
    // printf("\n会員番号を入力:");
    // scanf("%d",&target_id);
    // rc = LinearSearch_id(data,N,target_id);
    // if(rc==-1) printf("見つかりません\n");
    // else printf("要素番号:%d  会員番号:%d  名前:%s\n"
    //             ,rc,data[rc].id,data[rc].name);
     
    // // 名前で検索
    // printf("\n名前を入力:");
    // scanf("%s",target_name);
    // rc = LinearSearch_name(data,N,target_name);
    // if(rc==-1) printf("見つかりません\n");
    // else printf("要素番号:%d  会員番号:%d  名前:%s\n"
    //             ,rc,data[rc].id,data[rc].name);
 
    // return;
    int data[N]={11,22,33,44,55,66,77,88};
    int target,rc;
   
    printf("目標データを入力：");
    scanf("%d",&target);
    
    printf("\n線形探索\n");
    COUNT=0;
       // rc = LinearSearch(data,N,target);
    rc = SnetinelSearch(data,N,target);
    if(rc==-1) printf("見つかりません\n");
    else printf("要素番号 %d のデータです\n",rc);
    printf("%d個の要素数について調べました\n",COUNT);
    
    printf("\n二分探索\n");
    COUNT=0;
    rc = BinarySearch(data, N, target);
    if(rc==-1) printf("見つかりません");
    else printf("要素番号%dのデータです",rc);
    printf("\n%d個の要素数について調べました。", COUNT);
    
    return;
}

int LinearSearch(int x[],int n,int y)
{
    int i=0;
    while(i<n){
        if(x[i]==y) return i;
        else i++;
    }
    return -1;
}

int SnetinelSearch(int x[],int n,int y){
    int i=0;
    x[n]=y;
    while(x[i]!=y){
        COUNT++;
        i++;
    }
    if(i<n) return i;
    return -1;
    
    while(i<n){
        if(x[i]==y) return i;
        else i++;
    }
    if(i<n) return i;
    return -1;
}

int LinearSearch_id(Person x[],int n, int y){
    int i=0;
    while(i<n){
        if(x[i].id==y) return i;
        else i++;
    }
    return -1;
}

int LinearSearch_name(Person x[],int n, char y[]){
    int i=0;
    while(i<n){
        if(strcmp(x[i].name,y)==0) return i;
        else i++;
    }
    return -1;
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