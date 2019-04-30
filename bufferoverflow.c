#include <stdlib.h>
#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
	// Reserve 5 byte of buffer plus the terminating NULL.
	// should allocate 8 bytes = 2 double words,
	// To overflow, need more than 8 bytes...
	char buffer[5]; // If more than 8 characters input by user, there will be access violation, segmentation fault

	// a prompt how to execute the program...
	if (argc < 2)
	{
		printf("strcpy() NOT executed....\n");
		printf("Syntax: %s <characters>\n", argv[0]);
		exit(0);
	}
	// copy the user input to mybuffer, without any bound checking. a secure version is srtcpy_s()
	strcpy(buffer, argv[1]);
	printf("buffer content= %s\n", buffer);
	printf("strcpy() executed...\n");	// you may want to try strcpy_s()
	return 0;
}//main 

//OUTPUT
/*
c502@comp:~$ gcc buff.c
c502@comp:~$ ./a.out
strcpy() NOT executed....
Syntax: ./a.out <characters>
c502@comp:~$ ./a.out 1
buffer content= 1
strcpy() executed...
c502@comp:~$ ./a.out 1 4 9
buffer content= 1
strcpy() executed...
*/
