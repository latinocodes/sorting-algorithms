//***************************************************************************
// PROGRAM FILENAME: Lara-assn4-funcs.cpp
// DESCRIPTION:	This for the functions implemented by Jose Lara
//
// CLASS/TERM:	CS372
// DESIGNER:	Jose Lara
//
// FUNCTIONS:   Menu - Displays the a list of sorting choices to user
//              BubbleSort - Sort Array using Bubble Method
//              QuickSort - Sort Array using Quick Method
//              ChangeELements - swaps the elements for quickSort
//              DivideList - divides array in two list for quicksort
//              DisplayResults - Display function used to print out Sorting Results
//              ValidateArray - validates that arrays are in order
//              DisplaySortResults - Displays the average time results
//***************************************************************************

#ifndef __LaraTodd_assn4__Lara_assn4_funcs__
#define __LaraTodd_assn4__Lara_assn4_funcs__

#include <string>
#include <stdio.h>

using namespace std;

//*********************************************************************
// FUNCTION: Menu
// DESCRIPTION: Displays the a list of sorting choices to user
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: choice1 and choice2 for sorting selection, sortNum for
//           number of times to sort
//    OUTPUT: none.
//
// CALLS TO: none
// **********************************************************************

void Menu(char &choice1, char &choice2, int &sortNum);

//*********************************************************************
// FUNCTION: BubbleSort
// DESCRIPTION: Sort Array using Bubble Method
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: int long arrayList[], double firstSort[], int &timeNumFirstSort
//    OUTPUT: sortType.
//
// CALLS TO: ChangeElements()
// **********************************************************************

void BubbleSort(int long arrayList[], double firstSort[], int &timeNumFirstSort);

//*********************************************************************
// FUNCTION: QuickSort
// DESCRIPTION: Sort Array using Quick Method
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: int long arrayList[], int firstValue, int secondValue
//    OUTPUT: sortType.
//
// CALLS TO: QuickSort()
// **********************************************************************

void QuickSort(int long arrayList[], int firstValue, int secondValue);

//*********************************************************************
// FUNCTION: ChangeELements
// DESCRIPTION: swaps the elements for quickSort
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: int long *firstNum, int long *secondNum to be swap
//    OUTPUT: none.
//
// CALLS TO: none.
// **********************************************************************

void ChangeELements(int long *firstNum, int long *secondNum);

//*********************************************************************
// FUNCTION: DivideList
// DESCRIPTION: divides array in two list for quicksort
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: int arrayList[], firstValue, secondValue from array
//    OUTPUT: sortType.
//
// CALLS TO: ChangeElements().
// **********************************************************************

int DivideList(int long arrayList[], int firstValue, int secondValue);

//*********************************************************************
// FUNCTION: DisplayResults
// DESCRIPTION: Display function used to print out Sorting Results
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: int arrayList[]
//    OUTPUT: none.
//
// CALLS TO: none.
// **********************************************************************

void DisplayTimeResults(double firstSort[], int &firstDisplayNum, string typeOfSort);

//*********************************************************************
// FUNCTION: ValidateArray
// DESCRIPTION: validates that arrays are in order
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: int long arrayList[]
//    OUTPUT: none.
//
// CALLS TO: none.
// **********************************************************************

bool ValidateArray(int long arrayList[]);

//*********************************************************************
// FUNCTION: DisplaySortResults
// DESCRIPTION: Displays the average time results
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: firstAvgTime, secondAvgTime, numOfRep, sortType1, sortType2
//    OUTPUT: average time sorting took and sort type.
//
// CALLS TO: none.
// **********************************************************************

void DisplaySortResults(double firstAvgTime, double secondAvgTime, int numOfRep, string sortType1, string sortType2);


#endif /* defined(__LaraTodd_assn4__Lara_assn4_funcs__) */


