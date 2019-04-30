#include<stdio.h> 
#include<math.h> 
int gcd(int a, int h) 
{ 
   	 int temp; 
   	 while (1) 
   	 { 
        		temp = a%h; 
        		if (temp == 0) 
          		return h; 
        		a = h; 
      		  h = temp; 
   	 }//while
}//gcd function ends here

unsigned long long int power(int x,  int y, int n) 
{ 
    unsigned long long int temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2,n)%n; 
    if (y & 1) 
        return x*temp*temp; 
    else
        return temp*temp; 
}//power function ends here   

int main() 
{ 
    double p,q;		// double p = 7; double q = 11; 
    //2 prime numbers are the keys
    printf("Enter 2 prime numbers as keys:\n");
    scanf("%lf\n%lf",&p,&q);		//%lf format specifier for double datatype in C
  
    int n = (int)p*q; //modulus

    double phi = (p-1)*(q-1); //totient
    
    double e = 13; //assume public key 'e' such that gcd(e,phi)=1
    while (e < phi) //for checking co-prime which satisfies e>1
    {    
        	if (gcd(e, phi)==1) 
          	 	break; 
       	 else
            	e++; 
    }//while
     
    int k = 8;  //assume private key 'd' such that (d*e) mod phi=1   //k can be any arbitrary value
    double d = (1 + (k*phi))/e;   //choosing d such that it satisfies (d*e) = 1 + (k*phi)
    
    double msg;	//double msg = 5; 
    printf("\nEnter message:\n");
    scanf("%lf",&msg);
  
    //double c = pow(msg,e);
    //double m = pow(c,d);
    //c=fmod(c,n);
    //m=fmod(m,n);

    double c = pow(msg, e); 
    c = fmod(c, n); //cipher text   //the fmod function returns the remainder when x is divided by y
    printf("\nEncrypted data = %.2lf", c); 	//.2lf to display till 2 digits after decimal point
 
    int m = power(c, d, n)%n; //c^d mod n
  
    printf("\nDECRYPTION\nOriginal Message Sent = %d", m);  
    return 0; 
}//main function

