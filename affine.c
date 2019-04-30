#include<stdio.h>
#include<string.h>
int findinverse(int a)
{
	a = a%26;
	for (int x=1; x<26; x++)//check all the possible values of letters i.e. 1 to 26
   		if ((a*x) % 26 == 1)// if (a*b)%26=1, then b is inverse of a
      			return x;
}//findinverse function
void main ()
{
	char pt[50],ct[50];
	int k1,k2,i,e[50],d[50];
  
	printf("Enter the plain text ");
	scanf("%s",pt);
  
	printf("Enter first key ");
	scanf("%d",&k1);
  
	printf("Enter the second key ");
	scanf("%d",&k2);
  
	printf("ENCRYPTION ");
	for(i=0;i<strlen(pt);i++)
	{
	    	e[i]=(int)(pt[i]-65);//type cast & instead of ASCII value store 0,1,2... for letters A,B,C...
	    	e[i]=(e[i]*k1)%26;	//affine cipher: encryption: step 1: t=(pt*k1)%26
	    	e[i]=(e[i]+k2)%26;	//encryption: step 2: cipher text, ct=(t+k2)%26
	}//for
	
	for(i=0;i<strlen(pt);i++)//print cipher text i.e. encrypted plain text
    		printf("%c",e[i]+65);//+65 to again make the value ASCII eg. 0 becomes 0+65="A" & so on

	printf("\nDECRYPTION ");
	for(i=0;i<strlen(pt);i++)
	{
		d[i]=(e[i]-k2)%26;	//decryption: step 1: t=(ct-k2)%26
		d[i]=(((d[i]*findinverse(k1))%26) + 26 ) % 26;  ////decryption: step 2: t=(t*(k1 inverse))%26
	}//for
  
	for(i=0;i<strlen(pt);i++)//print plain text i.e. decrypted cipher text
    		printf("%c",d[i]+65);
}//main
