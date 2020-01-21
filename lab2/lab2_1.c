#include <stdio.h>

void func_02 (int *num2) 
{
	(*num2) = (*num2) - 1;
}

void func_01 (int *num1)
{
	(*num1) = (*num1) - 1;
	func_02(num1);
}

int main () 
{
	int num = 10;
	func_01(&num);
	printf("New number is %d\n", num);

	return 0;
}

/*

	Q1.1) The code will print the following: New number is 8
	This is so because after num gets passed into func_01, the new value 
	for num1 is 9. Then num1 gets passed into func_02 where it then 
	receives a value of 8.

	Q1.2) Removing the & symbol from the line func_01(&num) will result in a warning 
	when compiled. The program can still be ran, but it will result in a segmentation
	fault. As the warning states, func_01 makes pointer from integer without cast. 

	Q1.3) We do not use the & character for calling func_02 within func_01 because
	using the & sign means we are passing the address of the variable, whereas we actually
	want to pass the variable's value into func_02.  

	Q1.4) The code will print the following: New number is 9
	The compiler warns us regarding an incompatible pointer type due to the addition of the &
	character in the line: func_02(num1) in func_01. This warning resulted in func_01 being the only 
	function performed due to func_02 not being properly called. This is why the output was only 9
	rather than 8. 
	 	
*/
