# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void GenerateRandomData(int range, int data[], int num){
    int i;
    srand(time(NULL));
    
    for(i=0;i<num;i++){
    	data[i]=rand()%range+1;
        printf("%d\t", data[i]);
    } 
    printf("\n");
    return;
}
    
void main(){
    int data[10];
    int range;
    
    printf("数の範囲：");
    scanf("%d",&range);
    
    GenerateRandomData(range, data, 10);
    return;
}