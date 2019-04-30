/*
take 64 bit input
convert to binary
store in (8*8) matrix
store p-box matrix
do mapping
convert result to characters from binary
*/
#include<stdio.h>
void main()
{
    int i,j,m,n=7;
    //input matrix of size 8*8      
    int p[8][8] = {
                        1,1,0,1,0,0,1,1,
                        0,0,1,1,0,1,0,0,
                        1,1,1,0,0,1,0,0,
                        1,1,0,0,0,0,0,1,
                        1,0,0,0,0,0,1,1,
                        0,0,0,1,1,1,0,0,
                        0,0,1,1,1,1,0,1,
                        1,1,1,0,0,0,0,1
				 };                      
    
    int q[8][8]; //output matrix of size 8*8       
	
    for(i=0;i<=n;i++)
    {
    	for(j=0;j<=n;j++)
    		q[i][j]=p[7-i][j];//read rows in reverse order			
    }//for
   
	printf("OUTPUT of P-box is:\n");
	
	for(j=0;j<8;j++)
	{
		if( j%2==1)
		{
				for(i=0;i<8;i++)
					printf("%d",q[i][j]);
			printf("\n");
		}//if
	}//for			
	
	for(j=0;j<8;j++)
	{
		if( j%2==0)
		{
				for(i=0;i<8;i++)
					printf("%d",q[i][j]);
			printf("\n");
		}//if
	}//for		

}//main
