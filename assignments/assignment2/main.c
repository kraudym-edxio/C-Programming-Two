#include <stdio.h>
#include "xstring.h"

int main() {

    char test [150];
    char test2 [150];
    char c;
    char x;

    printf("Please enter a string of characters: ");
    scanf("%[^\n]s", test);

    for (int i = 0; i < 150; i++) {
    	test2[i] = test[i];
    }

    printf("\nPlease enter a character to test the function Find First Occurrence: ");
    scanf(" %c", &c);

    printf("The first occurrence of %c in %s is at index = %d \n\n", c, test, FindFirstOccurrence(c, test));

    printf("Please enter a character to test the function Find Last Occurrence: ");
    scanf(" %c", &c);

    printf("The last occurrence of %c in %s is at index = %d \n\n", c, test, FindLastOccurrence(c, test));

    printf("The weight of the C String %s is = %d \n\n", test, GetStringWeight(test));

    ToUpperCase(test);
    printf("The uppercase version is = %s \n\n", test);

    ToLowerCase(test);
    printf("The lowercase version is = %s \n\n", test);

    ReverseString(test2);
    printf("The reversed version is = %s \n\n", test2);

    ReverseString(test2);
 
    printf("Please enter the character you want to replace for the function Replace Character: ");
    scanf(" %c", &x);

    printf("Please enter the new character you want insert for the function Replace Character: ");
    scanf(" %c", &c);

    ReplaceCharacter(x, c, test2);
    printf("\nThe new C String after deleting %c is %s \n\n", x, test2);

    printf("Please enter the character you want to remove to test the function Remove Character: ");
    scanf(" %c", &c);

    RemoveCharacter(c, test2);
    printf("%s \n", test2);

    return 0;

}
