#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
	printf("****S-box****\n\n");
	int sip[6],sop[4],i,rno[2],colno[4];
	
	//ACCEPT INPUT
	printf("enter 6 bit binary input:\n");
	for(i=0;i<6;i++)
	scanf("%d",&sip[i]);
	
	//row number
	rno[0]=sip[0];
	rno[1]=sip[5];
	//column number
	colno[0]=sip[1];
	colno[1]=sip[2];
	colno[2]=sip[3];
	colno[3]=sip[4];
	
	//CONVERT BINARY VALUE TO DECIMAL VALUE i.e. (*2) for each digit
	//convert row number to decimal value
	int output=0, power=1;
   	for (i=0; i<2; i++)
  	{
       output += rno[1-i]*power;
       power *= 2;
   	}//for
   	int rowno=output;
   
   	//convert column number to decimal value
	int output2=0, power2=1;
   	for (i=0; i<4; i++)
   	{

       output2 += colno[3-i]*power2;
       power2 *= 2;
  	 }//for
   int columnno=output2;
   
   printf("Row number=%d\t",rowno);
   printf("Column number=%d\n",columnno);
   
   //sbox matrix
	int S1[4][16] = 
	{
		14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
		0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
		4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
		15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13
	};
	
	//OUTPUT
	int soutput=S1[rowno][columnno];
	 printf("Output value=%d\n",soutput);
	 
	//convert output decimal to binary
	 printf("Output in binary:\n");
	 int  c, k;
	 for (c = 3; c >= 0; c--)//c=32
 	 {
		k = soutput >> c;
		if (k & 1)
		  printf("1");
		else
		  printf("0");
 	 }//for
}//main
