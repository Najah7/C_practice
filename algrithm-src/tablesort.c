#include <stdio.h>
#include <string.h>
 
typedef struct student{
  int grade;        //学年
  char name[2][20]; //姓名
}Student;
 
void InsertionSortP_grade(Student* x[],int n)
{
  int i,j;
  Student* tmp;
  for(j=1;j<n;j++){
    tmp=x[j];
    for(i=j-1;i>=0;i--){
      if(x[i]->grade>tmp->grade)x[i+1]=x[i];
      else break;
    }
    x[i+1]=tmp;
  }
  return;
}
 
void InsertionSortP_name(Student* x[],int n,int f)
{
  int i,j;
  Student* tmp;
  for(j=1;j<n;j++){
    tmp=x[j];
    for(i=j-1;i>=0;i--){
      if(strcmp(tmp->name[f],x[i]->name[f])<0)x[i+1]=x[i];
      else break;
    }
    x[i+1]=tmp;
  }
  return;
}
 
void main()
{
  int i;
  Student data[5]={{2,{"いとう","たけし"}},
                   {2,{"かとう","まさる"}},
                   {2,{"いとう","ありさ"}},
                   {1,{"たなか","はるき"}},
                   {3,{"かとう","さちこ"}}};
 
  Student* p[5];
  for(i=0;i<5;i++) p[i]=&data[i];  //構造体へのポインタを格納
 
  printf("\n並べ替え前\n");
  for(i=0;i<5;i++)printf("学年:%d 姓:%s 名:%s\n",
                  p[i]->grade,p[i]->name[0],p[i]->name[1]);
 
  printf("\n「名」により 並べ替え\n");
  InsertionSortP_name(p,5,1);
  for(i=0;i<5;i++)printf("学年:%d 姓:%s 名:%s\n",
                  p[i]->grade,p[i]->name[0],p[i]->name[1]);
 
  printf("\n「姓」により 並べ替え\n");
  InsertionSortP_name(p,5,0);
  for(i=0;i<5;i++)printf("学年:%d 姓:%s 名:%s\n",
                  p[i]->grade,p[i]->name[0],p[i]->name[1]);
 
  printf("\n「学年」により並べ替え\n");
  InsertionSortP_grade(p,5);
  for(i=0;i<5;i++)printf("学年:%d 姓:%s 名:%s\n",
                  p[i]->grade,p[i]->name[0],p[i]->name[1]);
 
  return;
}