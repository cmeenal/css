#include<stdio.h>
#include<string.h>
void main()
{
	int n,c,k,p,a[512],msg[512],i;
	printf("Enter a number: ");
	scanf("%d",&n);
   
	//CONVERT DECIMAL NUMBER TO BINARY REPRESENTATION
	//calulate remainders 0 or 1
	for (c = n-1; c >= 0; c--)
	{
	  	k = n >> c;
	  	if (k & 1)
		 		msg[c]=1;
	  	else
		  		msg[c]=0;    
	}//for
 
    //read in reverse order to get binary number
    for (c = n - 1, i = 0; c >= 0; c--, i++)
    	a[i]=msg[c];
    
    printf("\n%d bits long binary number is:\n", n);
    for(i=0;i<n;i++)
   		printf("%d",a[i]);
    printf("\n\n");
   
 	  //PADDING
	if(n<512)
	{
	   	p=512-64-n;//padding length
	   	printf("padding length is %d\n",p);
	   	a[n]=1;//add first padding digit as 1 
	  	printf("before appending 0s in padding, message is\n");
	   	 for(i=0;i<=n;i++)
	   		 printf("%d",a[i]);
	   	 printf("\n\n\n");
	  	 
	  	 //add rest all digits in padding length as 0
	  	  for(i=n+1;i<=p+n;i++)
		    		a[i]=0;   	 
	}//if
    
	printf("After doing padding, n+p=%d\n",n+p);//length of message in binary+padding length
	printf("after padding, message is\n");
  	for(c=0;c<n+p;c++)//c<total length i.e. (n+p)
		printf("%d",a[c]);
	printf("\n\n");
}//main
