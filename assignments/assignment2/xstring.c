#include <stdio.h>

int FindFirstOccurrence(char c , char *pStr ) {

	int index = 0;

	while (*pStr) {
		
		if (*pStr++ == c) {
			return index;
		}

		index++;

	}

	return -1;

}

int FindLastOccurrence(char c, char *pStr ) {

	//Determining the length of the string
	int size = 0;

	while (*(pStr + size) != '\0') {
		size++;
	}

	int index = size - 1;

	//Searching from end to beginning
	while (index >= 0) {

		if (pStr[index] == c) {
			return index;
		}

		index--;
		
	}

	return -1;

}

int GetStringWeight (char *pStr ) {

	int i = 0;
	int sum = 0;

	while (pStr[i] != '\0') {

		sum = sum + pStr[i];
		i++;

	}

	return sum;

}

void ReplaceCharacter(char x, char c , char *pStr ) {

	int i = 0;

	while (pStr[i] != '\0') {

		if (pStr[i] == x) {
			pStr[i] = c;
		}
		
		i++;
	
	}

}

// You could use (call) this function to help you implement the RemoveCharacter function
// Make sure that DeleteCharAt keep the char array a valid C String ends with '\0'

void DeleteCharAt(int index, int size, char array[]) {

	if (index < 0 || index > size - 1)
        	return;

	for (int i = index; i < size - 1; i++) {
        	array[i] = array[i + 1];
	}

}

void RemoveCharacter(char c, char str [] ) {

	int size = 0;
	int index = 0;

	//Determine string length
	while (str[size] != '\0') {
		size++;
	}

	while (index < size) {

		if (str[index] == c) {
			DeleteCharAt(index, size, str);
			size--;
			index = 0;
		}
		
		else {
			index++;	
		}	
		
	}

	str[size] = '\0';

}

void ReverseString(char *pStr) {

	//Variable used for swap logic
	char *beginning, *ending;
	char swap;

	beginning = pStr; 
	ending = pStr;

	//Determining the length of the string
	int size = 0;

	while (pStr[size] != '\0') {
		size++;
	}

	//Reversing process
	for (int i = 0; i < size - 1; i++) { 
		ending++;
	}

	for (int i = 0; i < size / 2; i++) {

		//Swap logic
		swap = *ending;
		*ending = *beginning;
		*beginning = swap;

		beginning++;
		ending--;

	}

}

void ToUpperCase(char *pStr) {

	int i = 0;

	while (pStr[i] != '\0') {

		if (pStr[i] >= 'a' && pStr[i] <= 'z') {
			
			pStr[i] = pStr[i] - 32;
		
		}

		i++;

	}

}

void ToLowerCase(char *pStr) {

	int i = 0;

	while (pStr[i] != '\0') {

		if (pStr[i] >= 'A' && pStr[i] <= 'Z') {
			
			pStr[i] = pStr[i] + 32;
		
		}

		i++;

	}

}
