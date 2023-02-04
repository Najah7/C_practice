// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #define N 1000

// int COMPARE_COUNT;
// int MOVE_COUNT;
 
// void GenerateRandomData(int range,int Data[],int num)
// {
//     int i;
//     srand(time(NULL));
//     for(i=0;i<num;i++){
//         Data[i]=rand()%range+1;
//         //printf("%d\t",Data[i]);
//     }
//     printf("\n");
//     return;
// }

// void ShellSort(int x[], int n){
//     int i, j, k, tmp, gap;
    
//     gap=1;
//     while(n>gap)gap=3*gap+1;
//     gap=(gap-1)/3;
    
//     while(gap>0){
//     	for(k=0;k<gap;k++){
//         	for(j=k+gap;j<n;j=j+gap){
//             	tmp=x[j]; MOVE_COUNT++;
//                 for(i=j-gap;i>=0;i=i-gap){
//                 	COMPARE_COUNT++;
//                     if(x[i]>tmp) {x[i+gap] = x[i]; MOVE_COUNT++;}
//                     else break;
//                 }
//                 x[i+gap]=tmp; MOVE_COUNT++;
//             }
//         }
//         gap=(gap-1)/3;
//     }
//     return;
// }


// void InsertionSort(int x[], int n){
//     int i, j, tmp;
    
//     for(j=1; j<n;j++){
//     	tmp=x[j];
//         for(i=j-1; i>=0;i--){
//         	if(x[i]>tmp) x[i+1] = x[i];
//             else break;
//         }
//         x[i+1] = tmp;
//     }
//     return;
// }

// void BynaryInsertionSort(int x[],int n)
// {
//    int i,j,tmp,min,max,mid;
 
//    for(j=1;j<n;j++){
//       tmp=x[j];
//       min=0;max=j;
//       while(min<max){
//          mid=(min+max)/2;
//          if(x[mid]<=tmp) min=mid+1;
//          else max=mid;
//       }
//       for(i=j-1;i>=min;i--)x[i+1]=x[i];
//       x[min]=tmp;
//    }
//    return;
// }

// void main()
// {
//    int i;
//    int data[8]={3,2,8,5,7,1,6,4};
    
//    printf("\n並べ替え前\n");
//    for(i=0;i<8;i++) printf("%d\t",data[i]);
//    printf("\n");
 
//    printf("\n=シェルソート=\n");
//    COMPARE_COUNT=MOVE_COUNT=0;
//    ShellSort(data,8);
//    printf("比較%d回、移動%d回\n",COMPARE_COUNT,MOVE_COUNT);
 
//    printf("\n並べ替え後\n");
//    for(i=0;i<8;i++) printf("%d\t",data[i]);
//    printf("\n");
 
//    return;
// }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000
 
int COMPARE_COUNT;
int MOVE_COUNT;
 
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
 
void BestGapShellSort(int x[],int n)
{
   int i,j,k,tmp,gap;
 
   gap=1;
   while(n>gap)gap=3*gap+1;
   gap=(gap-1)/3;
 
   while(gap>0){
      for(k=0;k<gap;k++){
         for(j=k+gap;j<n;j=j+gap){
            tmp=x[j]; MOVE_COUNT++;
            for(i=j-gap;i>=0;i=i-gap){
               COMPARE_COUNT++;
               if(x[i]>tmp){ x[i+gap]=x[i]; MOVE_COUNT++; }
               else break;
            }
            x[i+gap]=tmp; MOVE_COUNT++;
         }
      }
      gap=(gap-1)/3;
   }
   return;
}
 
void main()
{
   int i;
   int data1[N];
   int data2[N];
 
   GenerateRandomData(N,data1,N);
   for(i=0;i<N;i++)data2[i]=data1[i]; //データのコピー
   printf("データ数 %d\n",N); //データ数の表示
 
   printf("\n=基本挿入法＝\n");
   COMPARE_COUNT=MOVE_COUNT=0;
   InsertionSort(data1,N);  
   printf("比較%d回、移動%d回\n",COMPARE_COUNT,MOVE_COUNT);
 
   printf("\n=シェルソート(ギャップ改良版）＝\n");
   COMPARE_COUNT=MOVE_COUNT=0;
   BestGapShellSort(data2,N);  
   printf("比較%d回、移動%d回\n",COMPARE_COUNT,MOVE_COUNT);
 
   return;
}