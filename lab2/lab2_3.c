#include <stdio.h>

int CountDigits (int n) {

	static int count = 0;

	n /= 10;
	++count;

	if (n != 0) {
		CountDigits(n);
	}
	
	return count;	

}

int main() {

	int n;
	
	printf("Enter an integer: ");
	scanf("%d", &n);

	int count = CountDigits(n);

	printf("Number of digits is: %d\n", count); 

}
