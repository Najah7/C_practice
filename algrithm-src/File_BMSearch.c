#include <stdio.h>
#include <string.h>

#define TEXT_SIZE 10000
#define STR_SIZE 128
#define KEY_SIZE 64

int BMSearch(unsigned char text[], unsigned char key[])
{	
    int table[256];
    int nt, nk, i,  t, k;
    
    nt = strlen(text);
    nk = strlen(key);
    
//     スキップ表の作成
    for(i = 0; i <256; i++) table[i]=nk;
    for(i = 0; i < nk; i++) table[key[i]] = nk - i- 1;
    
//     検索開始
    t = k = nk - 1;
    
    while(t < nt)
    {
    	if(text[t] == key[k])
        {
        	if(k == 0) return t;
            t--; k--;
        }
        else
        {
        	if(table[text[i]] <= nk-1-k) t = t + nk - k;
            else t = t + table[text[t]];
            k = nk - 1;
        }
    }
    return -1;
}




int main()
{
  FILE *fp;
  char filename[20];
  char str[STR_SIZE];
  char Text[TEXT_SIZE];
  char Key[KEY_SIZE];
  int  rc,i,s,nt,nk;
 
  //テキストファイル読み込みく
  printf("\nファイル名 : "); scanf("%s", filename);
  fp=fopen(filename, "r"); 
  if(fp==NULL){
    printf("ファイルをオープンできませんでした\n");
    return 1;
  }
  nt = 0;
  while(nt<TEXT_SIZE-STR_SIZE){
    if(fgets(str,STR_SIZE,fp)==NULL)break;
    strcpy(Text+nt,str);  nt=nt+strlen(str);
  }
  fclose(fp); 
  printf("\n=====テキスト=====\n%s\n",Text);
 
  printf("\n====キーワード=====\n");
  scanf("%s",Key); nk=strlen(Key);
 
  printf("\n=====検索結果=====\n");
  s=0;
  while(1){
    rc = BMSearch(Text+s,Key);
    if(rc!=-1){
      for(i=s;i<s+rc;i++) printf("%c",Text[i]);
      printf("\e[7m"); //反転表示
      for(i=s+rc;i<s+rc+nk;i++) printf("%c",Text[i]);
      printf("\e[0m"); //表示リセット
      s=s+rc+nk;
    }else{
      printf("%s\n",Text+s);
      break;
    }
  }
  return 0;
}


