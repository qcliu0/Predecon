  #include <stdlib.h>
  #include <math.h>
  #include <stdio.h>
int atlvs(float *t,int n, float *b,float *x)
{ int i,j,k;
  float a,beta,q,c,h,*y,*s;
  s=(float *)malloc(n*sizeof(float));
  y=(float *)malloc(n*sizeof(float));
  a=t[0];
  if(fabs(a)+1.0==1.0)
    {free(s); free(y); printf("fail\n"); return(-1);}
  y[0]=1.0;
  x[0]=b[0]/a;
  for(k=1; k<=n-1; k++){ 
     beta=0.0; q=0.0;
     for(j=0; j<=k-1; j++){
         beta=beta+y[j]*t[j+1];
         q=q+x[j]*t[k-j];
     }
     if(fabs(a)+1.0==1.0){
       free(s);
       free(y);
       printf("fail\n");
       return(-1);
     }
     c=-beta/a; s[0]=c*y[k-1]; y[k]=y[k-1];
     if(k!=1)
       for(i=1; i<=k-1; i++)
          s[i]=y[i-1]+c*y[k-i-1];
     a=a+c*beta;
     if(fabs(a)+1.0==1.0){
       free(s);
       free(y); 
       printf("fail\n");
       return(-1);
     }
     h=(b[k]-q)/a;
     for(i=0; i<=k-1; i++){
        x[i]=x[i]+h*s[i];
        y[i]=s[i];
     }
     x[k]=h*y[k];
  }
  free(s);
  free(y);
  return(1);
  }

