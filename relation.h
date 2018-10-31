void xcorr(float *x,float *y,float *corr,int n)
{
 int i,j;
 float sum;
// for(i=0;i<n;i++)
//    corr[i]=0;
	
 for(i=0;i<n;i++){
     sum=0.0;
     for(j=0;j<n-i;j++){
	if(i+j<n)
        sum=sum+x[j+i]*y[j];
     }
     corr[i]=sum;
 } 	
} 
