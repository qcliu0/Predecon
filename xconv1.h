#include <stdio.h>
#include <stdlib.h>

void xconv1(float *x,float *y,float *conv,int nt,int n)
{
 int i,j,conv_length, na, nn;
 float *xa, *conva;
 nn=nt+n-1;
 na=nn+n-1;
 conv_length=na+n-1;

 xa=(float *)malloc(sizeof(float)*na);
 conva=(float *)malloc(sizeof(float)*conv_length);

 for(i=0; i<n-1; i++)
    xa[i]=x[nt-n+i+1];
 for(i=n-1; i<nn; i++)
    xa[i]=x[i-n+1];
 for(i=nn; i<na; i++)
    xa[i]=x[i-nn];

 for(i=0;i<conv_length;i++)
    conva[i]=0.0;

 for(i=0;i<na;i++)
     for(j=0;j<n;j++)
	 if(i+j<conv_length)  conva[i+j]=conva[i+j]+xa[i]*y[j];

 for(i=0; i<nt+n-1; i++)
    conv[i]=conva[i+n-1];    
    
 free(xa);
 free(conva);
}
