#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

int main()
{
 FILE *fp_write;
 int i, nt;
 float *a, b;
 char name[]="data.dat";

/* printf("Please input the nt of the data\n");
 scanf("%d", &nt);
 printf("Please input the name of the data\n");
 scanf("%s", name);*/
 nt=1000;

 a=(float *)malloc(sizeof(float)*nt);
 for(i=0;i<nt;i++)
    a[i]=sin(2*PI*0.01*i)+0.5*(rand()/(RAND_MAX+1.0))-0.25;
 fp_write=fopen(name,"wb");
 fwrite(a,sizeof(float),nt,fp_write);

 printf("have finised the file\n");
 fclose(fp_write);
 return 0;
}
