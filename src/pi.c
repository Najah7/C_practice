#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    double x,y;
    int i,cnt=0,num=1000000;
     
    for(i=0; i<num; i=i+1)
    {
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        if( x*x+y*y < 1.0 ) cnt++;
    }
    printf("円周率は %f です\n",4.0*cnt/num);
 
    return 0;
}