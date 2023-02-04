#include <stdio.h>
#include <string.h>
 
int SimpleSearch( char text[ ], char key[ ])
{
  int i,j,m,n;
 
  n = strlen(text);
  m= strlen(key);
 
  for(i=0;i<=n-m;i++){
    for(j=0;j<m;j++){
      COUNT++;
      if(text[i+j] != key[j]) break;
    }
    if(j==m) return i;
  }
  return -1;
}



int main()
{
   char text[] = "She sells seashells.";
   char key[] = "sea";
   int  rc;
 
   printf("テキスト  ：%s\n",text);
   printf("キーワード：%s\n",key);
 
   rc = SimpleSearch(text,key);
 
   printf("検索結果  ：");
   if(rc!=-1){
      printf("キーワードは %d 文字目に検索されました\n",rc+1);
   }else{
      printf("キーワードは検索されませんでした\n");
   }
 
   return 0;
}