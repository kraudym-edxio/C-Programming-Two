/*
	Algorithms and Programming II
	Created by: Edxio Kraudy Mora
	Date: January 29, 2020

*/

#include <stdio.h>
#include <stdlib.h>

//Function 1
int fun1 (int n);
int fun1_r (int n);

//Function 2
int fun2 (int n);
int fun2_r (int n);

//Function 3
int Fibonacci (int n);
int Fibonacci_r (int n);

//Function 4
int gcd (int num1, int num2);
int gcd_r (int num1, int num2);

//Function 5
long power (int a, int b);
long power_r (int a, int b); 

//Function 6
void fun6 (int n, int m);
void fun6_r (int n, int m);

//Function 7
void DrawTriangle (int rows);
void DrawTriangle_r (int rows);
void stars (int j, int i, int rows);

int main (void) {

	int selection;
	int input;
	int x;
	int y;
	
	printf("Choose the function you would like to test to display the iterative and recursive output (1-7): ");
	scanf("%d", &selection);

	switch (selection) {

		case 1:
		
			printf("Pick a postive integer to determine the sum up to and including that number: "); 
			scanf("%d", &input);
	
			printf("Iterative output is: %d.\nRecursive output is: %d.\n", fun1(input), fun1_r(input));

			break;

		case 2:

			printf("Pick a postive integer to determine the summation outlined on the lab sheet: "); 
			scanf("%d", &input);
	
			printf("Iterative output is: %d.\nRecursive output is: %d.\n", fun2(input), fun2_r(input));

			break;

		case 3: 

			printf("Enter an integer n to determine Fibonacci(n): ");
			scanf("%d", &input);
		
			printf("Iterative output is: %d.\nRecursive output is: %d.\n", Fibonacci(input), Fibonacci_r(input));		

			break;

		case 4: 

			printf("Pick two integers to determine their greatest common divisor: ");
			scanf("%d %d", &x, &y);

			printf("Iterative output is: %d.\nRecursive output is: %d.\n", gcd(x,y), gcd_r(x,y));

			break;			

		case 5:

			printf("Pick a base and an exponent to determine the result: ");
			scanf("%d %d", &x, &y);

			printf("Iterative output is: %ld.\nRecursive output is: %ld.\n", power(x,y), power_r(x,y));

			break;			

		case 6:
	
			printf("Enter two numbers, n and m, to determine all the postive integers up to n that are divisible by m: ");
			scanf("%d %d", &x, &y);
			
			fun6(x,y);
			
			printf("Recursive output is: ");
			fun6_r(x,y);

			printf("\n");			

			break;
		
		case 7:

			printf("Enter an integer n to generate a pyramid with n rows: ");
			scanf("%d", &input);

			DrawTriangle(input);
	
			printf("\nRecursive output is: \n");
			DrawTriangle_r(input);

			printf("\n");
		
			break;

	}

}

//Function 1A
int fun1 (int n) {

	//Iterative approach
	int sum = 0;

	for (int i = 1; i <= n; i++) {
		sum = sum + i;
	}

	return sum;

}

//Function 1B
int fun1_r (int n) {

	//Recursive approach
	static int sum = 0;
	int i = n;

	sum = sum + i;
	i--;

	if (i > 0) {
		sum = fun1_r(i);
	}

	return sum;

}

//Function 2A
int fun2 (int n) { 

	//Iterative approach
	int total = 0;
	int addition = 0;

	for (int a = 1; a <= n; a++) { 
		addition = a + 1;
		total = (addition * addition) + total;
	}

	return total;

}

//Function 2B
int fun2_r (int n) {

	//Recursive approach
	static int total = 0;
	static int a = 1;

	int addition = 0;

	if (a <= n) {

		addition = a + 1; 
		total = (addition * addition) + total;

		a++;
		fun2_r(n);

	}
	
	return total;

}

//Function 3A
int Fibonacci (int n) {

	//Iterative approach
	int term0 = 0;
	int term1 = 1;

	int next_num;

	if (n == 0) {
		next_num = 0;
	}

	else if (n == 1) {
		next_num = 1;
	}

	else { 

		for (int y = 1; y < n; y++) {

			next_num = term0 + term1;
			term0 = term1;
			term1 = next_num;							

		}

	}	

	return next_num;

}

//Function 3B
int Fibonacci_r (int n) {

	//Recursive approach
	if (n == 0) {
		return 0;
	}

	else if (n == 1) {
		return 1;
	}

	else {
		return (Fibonacci_r(n - 1) + Fibonacci_r( n- 2));
	}

}	

//Function 4A
int gcd (int num1, int num2) {

	//Iterative approach
	int gcd = 0;	

	if (num1 == 0) {
		gcd = num2;
	}

	else if (num2 == 0) {
		gcd = num1;
	}

	for (int i = 1; i <= num1 && i <= num2; i++) {

		if (num1 % i == 0 && num2 % i == 0) {
			gcd = i;
		}

	}
	
	return gcd;

}

//Function 4B
int gcd_r (int num1, int num2) {

	//Recursive approach
	static int gcd = 0;
	static int i = 1;

	if (num1 == 0) {
		gcd = num2;
	}

	else if (num2 == 0) {
		gcd = num1;
	}

	if (i <= num1 && i <= num2) {

		if (num1 % i == 0 && num2 % i == 0) {
			gcd = i;
		}

		i++;
		gcd_r(num1, num2);

	}

	return gcd;

}

//Function 5A
long power (int a, int b) {

	//Iterative approach
	long result = 1;

	while (b > 0) {
		result = result * a;
		b--;
	}
	
	return result;

}

//Function 5B
long power_r (int a, int b) {

	//Recursive approach
	static long result = 1;
	static int counter = 1;

	result = result * a; 
	counter++;

	if (counter <= b) {
		power_r(a, b);
	}

	return result;

}

//Function 6A
void fun6 (int n, int m) {

	//Iterative approach
	printf("Iterative output is: ");

	for (int i = 1; i <= n; i++) {

		if (i % m == 0) {
			printf("%d ", i);
		}

	}

	printf("\n");

}

//Function 6B
void fun6_r (int n, int m) {

	//Recursive approach
	static int i = 1;

	if (i <= n) {

		if (i % m == 0) {
			printf("%d ", i);
			i++;
			fun6_r(n, m);
		}
	
		i++;
		fun6_r(n, m);

	}	

}

//Function 7A
void DrawTriangle (int rows) {

	//Iterative approach
	printf("Iterative output is: \n");
	
	for (int i = 1; i <= rows; i++) {

        	for (int j = 1; j <= i; j++) {
            		printf("* ");
        	}
	
		printf("\n");	

    	}

}

//Functions 7B
void DrawTriangle_r (int rows) {

	//Recursive approach
	static int i = 0;
	int j = 1;

	++i;

	if (i <= rows && rows > 0) {	

		stars(j, i, rows);
		
		DrawTriangle_r(rows);

	}

}

void stars(int j, int i, int rows) {

	if (j <= i) {

		++j;
		printf("* ");
		stars(j, i, rows);
	
	}

	else { 
		printf("\n");		
		DrawTriangle_r(rows);
	}

}
