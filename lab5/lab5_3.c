#include <stdio.h>

void PrintArray (int size, int array[]) {

	for (int i = 0; i < size; i++) {

		//Question 2.2) Changed to print memory address as well
		printf("array[%d] = %d and its address is %p \n", i, array[i], &array[i]); 

	}

	/*
		The memory addresses of the array elements are similar, but
		differ slightly nearing the end. Every element has its own
		designated location within the memory:

		array[0] = 0x7ffd2d340f70 
		array[1] = 0x7ffd2d340f74 
		array[2] = 0x7ffd2d340f78 
		array[3] = 0x7ffd2d340f7c 
		array[4] = 0x7ffd2d340f80 
		array[5] = 0x7ffd2d340f84 
		array[6] = 0x7ffd2d340f88 
		array[7] = 0x7ffd2d340f8c 

	*/ 

}

//Question 2.1)
void swap (int * var1, int * var2) {

	//Provide the implementation
	int selection;

	selection = *var1;
	*var1 = *var2;
	*var2 = selection;

}

void SelectionSort (int size, int array[]) {
	
	//Provide the implementation
	int a, b, c;
	
	for (a = 0; a < size - 1; a++) {
		
		c = 0;

		for (b = 0; b < size - a; b++) {
			
			if (array[c] < array[b]) {
				c = b;
			}

		}

		//Call to swap function	
		swap (&array[c], &array[size - 1 - a]);
	
	}
	
}

//Question 2.3)
void ArrayInfo (int size, int array[]) {

	int sum = 0;
	
	//Calculating the sum of the elements
	for (int i = 0; i < size; i++) {
		sum = sum + array[i];
	}

	printf("The sum of the elements is: %d\n", sum);

	float average = (float) sum / size;

	//Calculating and printing the average
	printf("The average is: %.3f\n", average);

	int min = array[0];
	int max = array[0];

	for (int i = 0; i < size; i++) {
		
		if (array[i] < min) {
			min = array[i];	
		}

		if (array[i] > max) {
			max = array[i];
		}

	}

	//Printing the minimum and maximum
	printf("The minimum element is %d. The maximum element is %d.\n", min, max);
	
}

void ReverseArray (int size, int *ptr2Array) {

	int swap;

	for (int i = 0; i < size - 1; i++) {

		for (int j = 0; j < (size - i) - 1; j++) {

			if (*(ptr2Array + j) < *(ptr2Array + j + 1)) {
				
				swap = *(ptr2Array + j);
				*(ptr2Array + j) = *(ptr2Array + j + 1);
				*(ptr2Array + j + 1) = swap;

			}

		}

	}

}

int main () {

	int data[] = {2, 7, 8, -8, 1, 9, 3, 5};

	//Sort array in ascending order and print
	SelectionSort (sizeof(data) / sizeof(int), data); 
	PrintArray (sizeof(data) / sizeof(int), data);

	printf("\n");

	//Display array info
	ArrayInfo (sizeof(data) / sizeof(int), data);

	printf("\n");

	//Sort array in decending order and print
	ReverseArray (sizeof(data) / sizeof(int), data);
	PrintArray (sizeof(data) / sizeof(int), data);
	
	return 0;

}
