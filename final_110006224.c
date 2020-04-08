/*
	Final Examination
	Coded by: Edxio Kraudy Mora (110006224)
	Date: Tuesday April 7, 2020
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void InitializeList (Node **head);
	
int main (void) {

	//Initializing a data structure
	struct ItemStruct {
		
		int ItemCode;
		int NumItems;
		float ItemPrice;
		float TotSales;
		char ItemName[17];

		struct ItemStruct * nextItem;

	};
	
	//Initialization of data file CategoryName.dat
	FILE *names = NULL;
	names = fopen("CategoryName.dat", "r");

	if (names == NULL) {
		printf("Error, you cannot read to file.\n");
		exit(1);
	}

	//Initialization of data file CodeNamePrice.dat
	FILE *price = NULL;
	price = fopen("CodeNamePrice.dat", "r");

	if (price == NULL) {
		printf("Error, you cannot read to file.\n");
		exit(1);
	}

	//Open input file handle for customer transactions
	FILE *transactions = NULL;
	transactions = fopen("DailyTransactions.dat", "r");

	//Structure created for singly linked list
	typedef struct Node {

		int data;
		struct Node *next;
	
	} Node;

	Node *head;

	InitializeList(&head); //Call to initializeList function

	//While more data exists, do the following:
	do {

		//Process each cusotmer list
		

		//Sort customer transaction data by item code


		//Calculating the total for each item ($)
		TotSales = ItemPrice * NumItems;
		
		//Update category and item code sales data totals



	} while (ItemCode != 000);

	//Close non-required file handles
	fclose(names);
	fclose(price);

	

}

void InitializeList(Node **head) {

	*head = NULL;
	
}

