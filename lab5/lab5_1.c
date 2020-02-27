#include <stdio.h>

int main () {

	int a = 7;
	int *aPtr;
	aPtr = &a;

	//This statement will print the value of a- which is 7.
	printf("stat 01: %d \n", a);

	//This statement will print stat: 02: 0x7fff377d674c  
	printf("stat 02: %p \n", &a);

	//This statement will print stat 3: 0x7fff377d674c 
	printf("stat 03: %p \n", aPtr);

	//This statement will print stat 04: 0x7fff377d674c 
	printf("stat 04: %p \n", &aPtr);

	//This statement will print the value of a- which is 7. 
	printf("stat 05: %d \n", a);

	//This statement will print the value aPtr is pointing to- which is 7.
	printf("stat 06: %d \n", *aPtr);

	//This statement will print stat 7: 0x7fff377d674c 
	printf("stat 07: %p \n", *&aPtr);

	//This statement will print stat 08: 0x7fff377d674c 
	printf("stat 08: %p \n", &*aPtr);

	//This statement will print the value that the address of 'a' is pointing to- which is 7.
	printf("stat 09: %d \n", *&a);

	return 0;

}
