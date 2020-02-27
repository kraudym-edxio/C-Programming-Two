#include <stdio.h>

int main () {

	float b = 3.7f;
	float *bPtr;

	//This statement will print stat: 01: value of b = 3.700000
	printf("stat 01: value of b = %f \n", b);

	//This statement will print the unsigned int presentation of the address
	//that bPtr is pointing at in memory

	printf("stat 02: %u \n", bPtr); //Prints stat 02: 0

	//Let bPtr point to the address of the variable b in memory
	bPtr = &b;

	//Write down the value you will get from this print statement, call it var1
	printf("stat 03: %u \n", bPtr); //var 1 = 3184975108   

	//This statement will prints stat 04: 3184975108 
	printf("stat 04: %u \n", &b); 

	//This statement prints stat 05: Currently bPtr stores the address of variable b which is 2179137412 in unsigned int format or 0x7fff81e2ff84 in hexadecimal format.
	printf("stat 05: Currently bPtr stores the address of variable b which is %u in unsigned int format or %p in hexadecimal format. \n", bPtr, bPtr);

	//This statement will print stat 06: the size of b in memory is: 4
	printf("stat 06: the size of b in memory is: %d \n", sizeof(b));

	//This statement is going to add 4 to the currently address of b  
	bPtr++;

	//Write down the value you will get from this print statement, call it var2
	printf("stat 07: %u \n", bPtr); //var 2 = 2179137416

	/*
		The difference between var2 and var1, i.e. (var2 - var1 = 4).
		This is so because the size of b in memory is 4 and due to the bPtr++
		statement we increment var1 by 4. This is why the difference is 4.
	*/

	return 0;

}
