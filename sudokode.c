/*
Name: Tyler Gauntlett
Date: 08/26/2015
Course: CS1 Fall 2015
Version: 1.0 (Still needs 3x3 sort function)
*/


#include <stdio.h>
#include <stdlib.h>

// Defining length by the size of the cols and rows
#define LENGTH 9

//Initializing functions
int sortCompareArray(int unsortedArray[LENGTH]);
int checkArray(int sudoku[LENGTH][LENGTH]);
int createArray();



int main()
{
	createArray();
	
	return 0;
}


int createArray(){
	// Initialze variables.
	int i, j, k, numOfBoards, l, input;

	// Initializing the sudoku grid.
	int sudoku[LENGTH][LENGTH];

	// Takes in an int based on the number
	// of sudoku boards to be solved.
	scanf("%i", &numOfBoards);

	// Loops based on the number of sudoku boards to be solved.
	while (numOfBoards > 0){

		// Creates the rows of the 2d array.
		for (i = 0; i < LENGTH; i++){

			// Inputs the raw numbers into a 2d array.
			scanf("%i", &input);

			// Breaks up a single integer number
			// into seperate array indexes and fills
			// the columns of the 2d array.
			for (j = 8; j >= 0; j--) {
				sudoku[i][j] = input % 10;
				input = input / 10;
			}

		}
		
		// Sudoku puzzel fails when 1.
		if (checkArray(sudoku) == 1){
			printf("NO\n");
			
		}

		else {
		printf("YES\n");
		}
		
		//Decrement that ends the while loop.
		numOfBoards--;
	}

	return 0;
}


int checkArray(int sudoku[LENGTH][LENGTH]) {

	int row, cols, i, j, k, l, tempArray[LENGTH];

	// Inputs the rows of the 2d array into a reusable 1d array
	for (row = 0; row < LENGTH; row++){
		for (cols = 0; cols < LENGTH; cols++){
			tempArray[cols] = sudoku[row][cols];
		}

		// Checks if the temp array is a invalid answer.
		if (sortCompareArray(tempArray) == 1){
			return 1;
		}
		
	}

	// Inputs the cols of the 2d array into a reusable 1d array
	for (cols = 0; cols < LENGTH; cols++){
		for (row = 0; row < LENGTH; row++){
			tempArray[row] = sudoku[row][cols];
		}

		// Checks if the temp array is a invalid answer.
		if (sortCompareArray(tempArray) == 1){
			return 1;
		}
	}


	// Check if 3x3 boxes are valid solutions preposition.
	/*
	for (row = 1; row <= 3; row++){
		for (cols = 1; cols <= 3; cols++){
			for (i = 0; i < 3; i++){
				for (j = 0; j < 3; j++){
					tempArray[j] = sudoku[i][j];
					if (sortCompareArray(tempArray) == 1){
						
					}
				}
			}
		}
	}
	*/


	return 0;
}


int sortCompareArray(int unsortedArray[LENGTH]){

	// Control array.
	int perfectArray[LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// Defining variables
	int i, j, k, l, m, output = 0, temp;

	// Prints pre-sort
	for (k = 0; k < 9; k++){
		//printf("Before sort: %i\n", unsortedArray[k]);
	}

	// Sorts the incoming array in ascending order
	for (i = 0; i < LENGTH - 1; i++) {

		for (j = 0; j < LENGTH - 1; j++) {

			if (unsortedArray[j] > unsortedArray[j + 1]) {
				temp = unsortedArray[j + 1];
				unsortedArray[j + 1] = unsortedArray[j];
				unsortedArray[j] = temp;
			}

		}

	}


		/*
		// Prints the sorted array DEBUGGING USE
		for (j = 0; j < 9; j++){
			//printf("After sort: %i\n", unsortedArray[j]);
		}
		*/


	for (l = 0; l < LENGTH; l++){

		if (unsortedArray[l] == perfectArray[l]){
			//printf("Success in %i index\n", l);  DEBUGGING USE

		}

		else {
			output = 1;
			//printf("Failure in %i index\n", l);  DEBUGGING USE
		}

	}


	//Working solution if output = 1, otherwise invalid
	if (output == 0) {
		return 0;
	}

	else {
		return 1;
	}

	return 0;
}

bubbleSort() {

}