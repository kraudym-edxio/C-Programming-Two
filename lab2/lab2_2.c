#include <stdio.h>

int sumOfN (int n) {

	static int sum = 0;
	int i = n;
		
	sum = sum + i;
	i--;
	
	if (i > 0) { 
		sum = sumOfN(i);
	}

	return sum;

}

int main() {

	int n;

	printf("Please enter a positive integer less than or equal to 100: ");
	scanf("%d", &n);

	int sum = sumOfN(n);
	printf("Sum of %d is %d\n", n, sum);
	
	return 0;

}
