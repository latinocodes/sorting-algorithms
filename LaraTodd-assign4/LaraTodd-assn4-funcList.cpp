#include <String>

using namespace std;

//*********************************************************************
// FUNCTION: Menu
// DESCRIPTION: Displays the a list of sorting choices to user
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: choice1 and choice2 for sorting selection
//    OUTPUT: none.
//
// CALLS TO: none
// **********************************************************************

void Menu(char &choice1, char &choice2, int &sortNum);

//*********************************************************************
// FUNCTION: PauseF
// DESCRIPTION: This Function is used to pause the screen
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: none.
//    OUTPUT: none.
//
// CALLS TO: none
// **********************************************************************

void PauseF();

//*********************************************************************
// FUNCTION: InsertationSort
// DESCRIPTION: Sort Array using Insertion Method
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int arrayList[]
//    OUTPUT: none.
//
// CALLS TO: ValidateArray(), DisplayResults()
// **********************************************************************

void InsertationSort(int long arrayList[]);

//*********************************************************************
// FUNCTION: MergeSort
// DESCRIPTION: Sort Array using Merge Method
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int arrayList[]
//    OUTPUT: none.
//
// CALLS TO: ValidateArray(), DisplayResults()
// **********************************************************************

void MergeSort(int long arrayList[]);

//----------------------------------------------------------------------
// FUNCTION: getMax
// DESCRIPTION: Sort Array using Merge Method
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int xNum, int yNum
//    OUTPUT: none.
//
// CALLS TO: none.
//----------------------------------------------------------------------

int long getMax(int long xNum, int long yNum);

//----------------------------------------------------------------------
// FUNCTION: MergeListTogether
// DESCRIPTION: Sort Array using Merge Method
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int *arrayList, int left, int right, int *tempArray
//    OUTPUT: none.
//
// CALLS TO: none.
//----------------------------------------------------------------------

void MergeListTogether(int long *arrayList, int left, int right, int long *tempArray);

//*********************************************************************
// FUNCTION: BubbleSort
// DESCRIPTION: Sort Array using Bubble Method
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: int arrayList[]
//    OUTPUT: none.
//
// CALLS TO: ValidateArray(), DisplayResults()
// **********************************************************************

void BubbleSort(int long arrayList[]);

//*********************************************************************
// FUNCTION: QuickSort
// DESCRIPTION: Sort Array using Quick Method
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: int arrayList[]
//    OUTPUT: none.
//
// CALLS TO: ValidateArray(), DisplayResults()
// **********************************************************************

void QuickSort(int long arrayList[]);

//*********************************************************************
// FUNCTION: DisplayResults
// DESCRIPTION: Display function used to print out Sorting Results
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: int time, string typeOfSort
//    OUTPUT: none.
//
// CALLS TO: ValidateArray(), DisplayResults()
// **********************************************************************

void DisplayResults(int time, string typeOfSort);

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

//*********************************************************************
// FUNCTION: DisplayTimeResults
// DESCRIPTION: Display function used to print out Sorting Results
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: double firstSort[], int &firstDisplayNum, string typeOfSort
//    OUTPUT: none.
//
// CALLS TO: ValidateArray(), DisplayResults()
// **********************************************************************

void DisplayTimeResults(double firstSort[], int &firstDisplayNum, string typeOfSort);

//*********************************************************************
// FUNCTION: GenerateRandArray
// DESCRIPTION: Generates the array for the of random numbers
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int arrayList[]
//    OUTPUT: none.
//
// CALLS TO: GetRandNumber()
// **********************************************************************

void GenerateRandArray(int long arrayList[]);

//*********************************************************************
// FUNCTION: ValidateArray
// DESCRIPTION: validates that arrays are in order
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: int arrayList[], int secondArray[], int arraySize
//    OUTPUT: none.
//
// CALLS TO: none.
// **********************************************************************

bool ValidateArray(int long arrayList[]);

//*********************************************************************
// FUNCTION: GetRandNumber
// DESCRIPTION: uses rand() to get random number from system
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int arrayList
//    OUTPUT: returns a random integer.
//
// CALLS TO: none.
// **********************************************************************

int GetRandNumber();

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
// FUNCTION: ChangeELements
// DESCRIPTION: swaps elements
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: int *firstNum, int *secondNum
//    OUTPUT: none.
//
// CALLS TO: none.
// **********************************************************************

void ChangeELements(int long *firstNum, int long *secondNum);
