#include <stdio.h>

int binarySearch (int arr[], int size, int x); //Function 1
void selectionSort (float nums[], int size); //Function 2
int IsPartiallySorted (int numbers[], int size, int m); //Function 3
int testing_degree (int numbers[], int size, int m, int test_array[], int a); //Function 3- recursive function

//User-input functions
void EnterArrayData (int size, int data[]);
void PrintArrayData (int size, int data[]);

//Main function
int main (void) {

	int size;
	int data[size];	

	//Binary Search
	
		printf("Binary Search: \n");

		printf("Enter the size of the array: ");
		scanf("%d", &size);

		EnterArrayData(size, data); //Calling user-input function
		
		int key; //Search integer

		printf("\nEnter an integer to attempt to locate it within the array: ");
		scanf("%d", &key);

		PrintArrayData(size, data);

		printf("\nInteger %d was found within index position %d.\n \n", key, binarySearch(data, size, key));

	//Selection Sort

		printf("Selection Sort: \n");
	
		printf("Enter the size of the array: ");
		scanf("%d", &size);

		float array_of_floats[size];

		printf("Enter the elements of the array, i.e. floats: ");

		for (int i = 0; i < size; i++) {
			scanf("%f", &array_of_floats[i]);
		}

		printf("\nUnsorted Array: \n");

		for (int i = 0; i < size; i++) {
			printf("%f\n", array_of_floats[i]);
		}

		selectionSort(array_of_floats, size);

	//Partially Sorted
	
		printf("\nPartially Sorted: \n");
	
		printf("Enter the size of the array: ");
		scanf("%d", &size);

		int array_nums[size];
		int degree;

		EnterArrayData(size, array_nums);

		printf("\nEnter a degree to test against the imperfect array: ");
		scanf("%d", &degree);

		PrintArrayData(size, array_nums);			

		IsPartiallySorted(array_nums, size, degree);

}

//Q1. Binary Search Algorithm
int binarySearch (int arr[], int size, int x) {

	int first = 0;
	int last = size - 1;

	int middle;

	while (first <= last) {
	
		//Splitting the list in half
		middle = (first + last) / 2;

		if (x == arr[first]) {
			return first;
		}

		if (x > arr[middle]) {
			first = middle + 1;
		}

		else {
			last = middle - 1;
		}
	
	} //End while 

	if (first > last) {
		return -1;
	}

	return 0;

}

//Q2. Selection Sort Algorithm
void selectionSort (float nums[], int size) {

	int a, b, c;
	float selection;

	for (a = 0; a < size - 1; a++) {
		
		c = 0;

		for (b = 0; b < size - a; b++) {
			
			if (nums[c] < nums[b]) {
				c = b;
			}

		}
			
		//Swapping logic
		selection = nums[c];
		nums[c] = nums[size - 1 - a];
		nums[size - 1 - a] = selection;	 
	
	}

	//Printing sorted array
	printf("\nSorted Array: \n");
	
	for (int i = 0; i < size; i++) {
		printf("%f\n", nums[i]);
	}

}

//Q3. Partially Sorted Algorithm
int IsPartiallySorted (int numbers[], int size, int m) {

	int test_array[size];
	int a = 0; //Counter variable

	//Making a copy of the unsorted array
	for (int i = 0; i < size; i++) {
		test_array[i] = numbers[i];
	}	
	
	//Bubble sort test_array
	int swap;

	for (int i = 0; i < size - 1; i++) {

		for (int j = 0; j < (size - i) - 1; j++) {

			if (test_array[j] > test_array[j + 1]) {
				
				swap = test_array[j];
				test_array[j] = test_array[j + 1];
				test_array[j + 1] = swap;		

			}

		}

	}

	//Calling testing_degree function
	testing_degree(numbers, size, m, test_array, a);

	return 0;

}

int testing_degree (int numbers[], int size, int m, int test_array[], int a) {
	
	int comparing; 

	comparing = binarySearch(test_array, size, numbers[a]);

	if ((comparing - a) > m) {
		printf("\nNot an imperfect sorted array of degree %d!\n", m);
		return 0;
	}
	
	else {

		if (a >= size) {
			printf("\nImperfect sorted array of degree %d!\n", m);
			return 1;
		}
		
		else {
			testing_degree(numbers, size, m, test_array, ++a);
		}
				
	}

	return 0;

}

//Q4. User-input Functions
void EnterArrayData (int size, int data[]) {
	
	printf("Enter the elements of the array: ");

	for (int i = 0; i < size; i++) {
		scanf("%d", &data[i]);
	}

}

void PrintArrayData (int size, int data[]) {
	
	printf("\nArray: \n"); 

	for (int x = 0; x < size; x++) {
		printf("%d\n", data[x]);
	}

}
