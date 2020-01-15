/*
 * Student Name: Edxio Kraudy Mora
 * Student Number: 110006224
 * Section Number: 51
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int rows = 0;

    //Do while loop will repeat if user enters a row value that is less than or equal to 2
    do {

        printf("Please enter the number of rows: ");
        scanf("%d", &rows);
   
    } while (rows > 10 || rows < 2); //minimum of two rows, maximum or ten rows

    printf("Printing a half pyramid of %d rows", rows);
    printf("\n");

    //Made the second portion of the for loop <= rather than just <
    for (int i = 1; i <= rows; i++) {

        //Changed j <= rows to j <= i 
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
	
	//Added print statement signifying starting a new row
	printf("\n");	

    }

    printf("\n");

    //Pyramid with numbers portion of the code 
    for (int i = 1; i <= rows; i++) {

	int x = 0; 

        for (int j = 1; j <= i; j++) {
        	x = x + i;
		printf("%d ", x);
        }	

	printf("\n");	

    }

    return 0;

}

/*

	Q1] These were the following problems with the code originally: 
		> Only one row would appear because there was no use of \n in the first for loop
		> Needed to change the clause in the first for loop such that it is <= NOT just <
		< Needed to change the clause in the second for loop such that j <= i NOT j <= rows

	Q2] The above code was fixed to display a proper half pyramid pattern with a 
	    minimum of two rows and a maximum of ten rows.

	Q3] Pyramid with numbers is reflected in the above code. 

*/
