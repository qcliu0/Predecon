#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "atlvs.h"
#include "relation.h"
#include "xconv1.h"

int main()
{
 FILE *fp_read;
 FILE *fp_result;
 FILE *fp_prede;
 float *xt,*xa,*f;                
 float *p,*r,*b,*re;
 int i,nt,n,k,a, m;
 char read[]="data.dat", result[]="result1.dat", prede[]="prede1.dat";        

 nt=1000; n=3; a=1;

 m=nt+n-1;

 xt=(float *)malloc(sizeof(float)*nt);
 xa=(float *)malloc(sizeof(float)*nt);
 r=(float *)malloc(sizeof(float)*n);
 b=(float *)malloc(sizeof(float)*n);
 p=(float *)malloc(sizeof(float)*m);
 f=(float *)malloc(sizeof(float)*n);
 re=(float *)malloc(sizeof(float)*nt);

 if((fp_read=fopen(read,"rb"))==NULL)
    printf( "Cannot open inputfile.\n"); 
 fread(xt,sizeof(float),nt,fp_read);

 xcorr(xt,xt,xa,nt);    

 if(n>nt) printf("The n is too long\n");
 for(i=0;i<n;i++)
    r[i] = xa[i]; 
 r[0]=r[0]*(1+0.1);
 for(i=0;i<n;i++){
    if((i+a)<nt) b[i]=xa[i+a];
    else b[i]=0;
 }      

 k=atlvs(r,n,b,f);     
	                                
 xconv1(xt,f,p,nt,n);   

 for(i=0;i<a;i++)
    re[i]=xt[i];
 for(i=a;i<nt;i++)
    re[i]=xt[i]-p[i-a];

 fp_prede=fopen(prede,"wb");
 fwrite(p,sizeof(float),m,fp_prede);

 fp_result=fopen(result,"wb");
 fwrite(re,sizeof(float),nt,fp_result);

 fclose(fp_read);
 fclose(fp_prede);
 fclose(fp_result);

 free(xt);
 free(xa);
 free(r);
 free(p);
 free(b);
 free(f);
 free(re);

 return 0;
}
