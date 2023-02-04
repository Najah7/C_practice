#include <stdio.h>
#include <string.h>

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
  char text[]="She sells seashells by the seashore.";
  char key[64];
  int rc;
 
  printf("テキスト  ：%s\n",text);
  printf("キーワード："); scanf("%s",key);
 
  rc = BMSearch(text,key);
 
  printf("検索結果  ：");
  if(rc!=-1){
    printf("キーワードは%d文字目に検索されました\n",rc+1);
  }else{
    printf("キーワードは検索されませんでした\n");
  }
  return 0;
}


