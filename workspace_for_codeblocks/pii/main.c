#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double pi()
{
    double s=0.0;
    for(int i=1;i<100;i++)
        s+=pow(-1,i+1)/(2*i-1);
    return s*4;
}
int main()
{
   printf("the π is :%lf",pi());
}
