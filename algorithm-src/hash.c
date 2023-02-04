#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 11

#define SUCCESS 0
#define FAILURE 1

#define EMPTY 0
#define DELETED -1

typedef struct record{
    long int tel;
    char name[32];
}Record;

Record Table[TABLE_SIZE];

int hash(long int key)
{
    return key % TABLE_SIZE;
}


          
          
int rehash(int bucket)
{
    return (bucket + 1) % TABLE_SIZE;
}

// NOTE:その他のhash
/*
(hash(key)+k)%TABLE_SIZE
(hash(key) + k * k) % TABLE_SIZE
*/


int add_hashtable(Record new_data)
{
    int bucket, k;
    long int key, data;
    
    key = new_data.tel;
    bucket=hash(key);
    for (k=1; k <= TABLE_SIZE; k++)
    {
    	data = Table[bucket].tel;
        if (data == EMPTY || data==DELETED)
        {
        	Table[bucket]=new_data;
            printf("追加しました\n");
            return SUCCESS;
        }
        bucket = rehash(bucket);
    }
    printf("追加できませんでした");
    return FAILURE;
}

int search_hashtable(long int key)
{
    int bucket, k;
    long int data;
    
    bucket = hash(key);
    for (k=1; k <= TABLE_SIZE;k++)
    {
    	data = Table[bucket].tel;
        if (data == key)
        {
        	printf("%sさんの電話番号です。\n", Table[bucket].name);
            return SUCCESS;
        }
        if (data == EMPTY) break;
        bucket = rehash(bucket);
    }
    printf("見つかりませんでした\n");
    return FAILURE;
}

int delete_hashtable(long int key)
{
    int bucket, k;
    long int data;
    
    bucket = hash(key);
    for (k=1; k <= TABLE_SIZE; k++)
    {
        data = Table[bucket].tel;
        if (data==key)
        {
        	Table[bucket].tel = DELETED;
        	printf("削除しました/\n");
        	return SUCCESS;
        }
    	if (data == EMPTY) break;
    	bucket = rehash(bucket);
    }
    printf("見つかりませんでした\n");
    return FAILURE;
}

void main(void)
{
   Record new_data;
   int i,menu,rc;
   long int  key;
 
   for(i=0;i<TABLE_SIZE;i++)Table[i].tel=EMPTY;
 
   while(1){
      printf("\n登録 1  削除 2  検索 3  表示 4\nメニュー番号： ");      scanf("%d",&menu);
      switch(menu){
         case 1:
            printf("\n=データ登録=\n");
            while(1){
               printf("電話番号(-1で登録終了)：");
               scanf("%ld",&new_data.tel);
               if(new_data.tel==-1) break;
               printf("名前：");
               scanf("%s",new_data.name);
               rc=add_hashtable(new_data);
               if(rc==FAILURE) break;
            }
            break;
         case 2:
            printf("\n＝データ削除＝\n");
            while(1){
               printf("電話番号(-1で削除終了)：");
               scanf("%ld",&key);
               if(key==-1)break;
               delete_hashtable(key);
            }
            break;
         case 3:
            printf("\n＝データ検索＝\n");
            while(1){
               printf("電話番号(-1で検索終了)：");
               scanf("%ld",&key);
               if(key==-1)break;
               search_hashtable(key);
            }
            break;
         case 4:
            printf("\n=データ表示=\n");
            for(i=0;i<TABLE_SIZE;i++){
               if(Table[i].tel==EMPTY||Table[i].tel==DELETED)continue;
               printf("%d\t%ld\t%s\n",i,Table[i].tel,Table[i].name);
            }
            break;
         default:
            return;
      }
   }
   return;
}