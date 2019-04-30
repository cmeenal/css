#include <stdio.h>
#include <math.h>
void main()
{
	int q,alpha,xa,xb,ya,yb,ka,kb, x,y,z,count,ai[20][20];//ai is matrix of q-1 rows and columns. 
	printf("Enter a Prime Number q:");
	scanf("%d",&q);
	//PRIVATE KEYS
	printf("Enter a No for xA which is less than value of q:");//assume xa as private key for a
	scanf("%d",&xa);
	printf("Enter a No for xB which is less than value of q:");//assume xb as private key for user b
	scanf("%d",&xb);
	//MAKE ARRAY for Primitive Root Calculation
	for(x=0;x<q-1;x++) //rows: alpha
		for(y=0;y<q-1;y++)	//columns:p	//1 to 10 i.e. (q-1) values considered for q=11, or 0 to 9 array index
			ai[x][y] = ((int)pow(x+1,y+1))%q;//element = (alpha^p)mod q	//(row^column) mod q	//row or column value=array index+1
	//CALCULATE primitive root
	for(x=0;x<q-1;x++)//row
	{
		count = 0;//reset count value for each row calculation
		for(y=0;y<q-2;y++)//column
		{
			for(z=y+1;z<q-1;z++)//compare "y" value with next values after it i.e. "z"
				if(ai[x][y] == ai[x][z])//if repeated values in a row, then it is not primitive root
				{
					count = 1;
					break;
				}//if
			if(count == 1)
				break;
		}//for loop of y
		if (count == 0 )//no repeated values i.e. all uniqye values in a row
		{
			alpha = x+1;//primitive root,alpha is the row number i.e. array index,0 +1 = row number,1
			break;
		}//if
	}//for loop of x
	printf("alpha = %d\n",alpha);
	//PUBLIC KEYS
	ya = ((int)pow(alpha,xa))%q; //calculate public key of a, ya=(alpha^xa)mod q
	yb = ((int)pow(alpha,xb))%q; //calculate public key of b, yb=(alpha^xb)mod q
	//KEY GENERATION
	ka = ((int)pow(yb,xa))%q;//encrypted value key, ka=(yb^xa) mod q
	kb = ((int)pow(ya,xb))%q;//decrypted value key, kb=(ya^xb) mod q
	printf("ya = %d\nyb = %d\nka = %d\nkb = %d\n",ya,yb,ka,kb);
	if(ka == kb) //always this should be true
		printf("The keys exchanged are same");
	else 
		printf("The keys exchanged are not same");
}//main
