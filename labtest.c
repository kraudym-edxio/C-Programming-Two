#include <stdio.h>
#define MAXSIZE 20

void ReadArrayData (int size, int data[]) {

	for (int index = 0; index < size; index++) {
		printf("Enter the value of data[%d]: ", index);
		scanf("%d", &data[index]);
	}

}

int GetMax (int size, int data[]) {
	
	//Provide the Implementation
	int maximum = data[0];

	for (int i = 0; i < size - 1; i++) {

		if (data[i] < data[i + 1]) {
			maximum = data[i + 1];
		}

	}
	
	return maximum;

}

void DrawBarChart (int size, int data[]) {
	
	//Provide the Implementation
	for (int i = 0; i < size; i++) {

		for (int x = 1; x <= data[i]; x++) {
			printf("*\n");
		}

		printf("%d\n \n", data[i]);

	}


	printf("The maximum value is: %d\n", GetMax(size, data));

/*	
	static int i = 0;

	if (i < size) {
		
		for (int x = 1; x <= data[i]; x++) {
			printf("*\n");
		} 
		
		printf("\t");
		
		i++;
		DrawBarChart(size, data);

	}	
*/

}

int main(void) {

	printf("\n \n");
	
	int data[MAXSIZE];
	int size;
	
	printf("Please enter the size of the array: ");
	scanf("%d", &size);

	ReadArrayData(size, data);
	DrawBarChart(size, data);

	printf("\n \n");
	
	return 0;

}
