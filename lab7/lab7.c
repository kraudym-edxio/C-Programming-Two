#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

	Defines Point structure as a collection
	of integer x and y. Then it declares one
	variable Point of type Point.

*/

typedef struct Point {

    int x;
    int y;

} Point;


/*

	Defines Line structure as a collection
	of variable start (of type Point), variable
	end (of type Point), and character array colour.
	Then it declares one variable Line of type Line. 

*/

typedef struct Line {

    Point start;
    Point end;
    char color[15];

} Line;

/*

	Sets the x and y value of the coordinate (x, y)
	Parameter x is the x value of the coordinate
	Parameter y is the y value of the coordinate
	Returning value of p

*/

Point setPoint (int x, int y) {

    Point p;

    p.x = x;
    p.y = y;

    return p;

}

Line setLine (Point s, Point e, char lineColor[]) {

    Line l;

    l.start = s;

    l.end = e;

    strcpy(l.color, lineColor);

    return l;

}

/*

	Function will print the coordinate (x, y)
	Parameter p is from setPoint function

*/

void PrintPoint (Point p) {
    printf("(%d, %d)  \n", p.x, p.y);
}

/*

	Function will print the line
	Parameter is 1 (Line 1) 

*/

void PrintLine (Line l) {

    printf("start at: ");
    PrintPoint(l.start);
    printf("end at: ");
    PrintPoint(l.end);
    printf("color is: %s \n", l.color);

}

/*

	Function will ask the user to alter the (x, y) coordinate and color
	Parameter is *1 (Line *1)

*/

void EditLine (Line *l) {

    printf("Please enter the new start point (x, y): ");
    scanf("%d %d", &l->start.x, &l->start.y);

    printf("Please enter the new end point (x, y): ");
    scanf("%d %d", &l->end.x, &l->end.y);

    printf("Please enter the line color: ");
    scanf(" %[^\n]s", (*l).color);

}

/*

	Function will swap the start and end coordinates
	Parameter is *1 (Line *1)

*/

void ReverseLine (Line *l) {

    Point temp;

    temp.x = (*l).start.x;
    temp.y = (*l).start.y;

    (*l).start.x = (*l).end.x;
    (*l).start.y = (*l).end.y;

    (*l).end.x = temp.x;
    (*l).end.y = temp.y;

}

/*

	Function will create a points list
 	Parameter size is the size of the list
	Returning ptr

*/

Point *CreatePointList (int size) {

    Point *ptr = (Point *) malloc(size * sizeof(Point));
    return ptr;

}

/*

	Function will initialize the points list with values 
	Parameter list is the list
	Parameter size is the size of the list
 
*/

void InitializePointsList (Point *list, int size) {

    int x;

    int y;

    for (int i = 0; i < size; i++) {

        printf("enter data for point # %d: ", i);

        scanf("%d %d", &x, &y);


        *(list + i) = setPoint(x, y);

    }

}

/*

	Function will print the points stored in the list
	Parameter list is the list
	Parameter size is the size of the list 

*/

void PrintPointList (Point *list, int size) {

    printf("\nHere are the points stored in the list: \n");

    for (int i = 0; i < size; i++) {

        PrintPoint(*(list + i));

    }

}

void SortPointList (Point *list, int size) {

     Point temp;
     char selection

	printf("Would you like to sort the points based on X or Y?: ");
	scanf(" %c", &selection);

	if (selection == 'X') {

		//Sorting X-coordinate
		for (int i = 0; i < size - 1; i++) {
         
			for (int j = i + 1; j < size; j++) {

             			if( (*(list+i)).x  > (*(list+j)).x ) {

                			temp = setPoint((*(list+i)).x, (*(list+i)).y);

                			*(list+i) = setPoint((*(list+j)).x, (*(list+j)).y);

                			*(list+j) = setPoint(temp.x, temp.y);

             			}		

         		}

		}

	}

	else if (selection == 'Y') {	
	
		//Sorting Y-coordinate
		for (int i = 0; i < size - 1; i++) {
         
			for (int j = i + 1; j < size; j++) {

             			if( (*(list+i)).y  > (*(list+j)).y ) {

                			temp = setPoint((*(list+i)).y, (*(list+i)).x);

                			*(list+i) = setPoint((*(list+j)).y, (*(list+j)).x);

                			*(list+j) = setPoint(temp.y, temp.x);

             			}

			}	

		}

	}

}

int main () {

    // declare variable start of type Point and use the function setPoint(x,y) to set the x coordinate
    // and y coordinate of the point start
    Point start = setPoint(5, 7);

    // add description ........
    Point end = setPoint(3, 9);

    // declare variable aline of type line and use the function setLine(start, end, color) to set the start point , end
    // point, and the color of the line
    Line aline = setLine(start, end, "red");

    // call the function PrintLine(Line) that print the information of any variable of type Line
    printf("\nHere is the current Line data: \n");
    PrintLine(aline);

    // call the function EditLine(Line) which allow the user to change the information of any variable of type Line
    EditLine(aline);

    // call the function PrintLine(Line) that print the information of any variable of type Line
    // Note: after calling EditLine(aline) it is expected that PrintLine will display the new data of aLine
    printf("\nHere is the new Line data: \n");
    PrintLine(aline);

    // call the function ReverseLine(Line) this function will reverse the start and the end points on any given Line
    // variable (swap the start and end points)
    printf("\nAfter reversing the start and end points of the line: \n");
    ReverseLine(aline);

    // call the function PrintLine(Line) that print the information of any variable of type Line
    // Note: after calling EditLine(aline) it is expected that PrintLine will display the new data of aLine
    PrintLine(aline);

    int num;

    printf("\nPlease enter the total number of points you want to create: ");
    scanf("%d", &num);

    // Call the function CreatePointList(num) which allocate enough memory to store n number of points in an an array of
    // Point structures
    Point *pointlist = CreatePointList(num);

    // Call the function InitializePointsList(pointList, num) which allow the user to enter the data for each point in
    // the list of points
    InitializePointsList(pointlist, num);

    // Call the function PrintPointList(pointList,num) which will print all the points in the list.
    PrintPointList(pointlist, num);

    // Call SortPointList(pointList, num) that sort the list of points based on x or y
    SortPointList(pointlist, num);

    // Print the sorted point list
    PrintPointList(pointlist,num);

}
