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

#include "Lara-assn4-funcs.h"
#include "Todd-assn4-funcs.h"
#include "LaraTodd-assn4-common.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

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
void Menu(char &choice1, char &choice2, int &sortNum){
    
    cout << endl;
    cout << "Choose two sorts you wish to compare:" << endl;
    cout << setw(24) << " B = Bubble sort" << endl;
    cout << setw(27) << " I = Insertion sort" << endl;
    cout << setw(23) << " M = Merge sort" << endl;
    cout << setw(23) << " Q = Quick sort" << endl;
    cout << setw(25) << " E = Exit program" << endl << endl;
    cout << "Enter two letter choices (or EE to exit): ";
    
    cin >> choice1 >> choice2;
    
    choice1 = toupper(choice1);
    choice2 = toupper(choice2);
    
    if(choice1 != 'E' && choice2 != 'E'){
    
        cout << "Enter the number of times to repeat each sort (1 or more): ";
        cin >> sortNum;
    
        while(sortNum == 0) {
        cout << "Invalid input -- Enter the number of times to repeat each sort (1 or more): ";
        cin >> sortNum;
        }
        cout << endl;
    }
} // end of Menu


//*********************************************************************
// FUNCTION: BubbleSort
// DESCRIPTION: Sort Array using Bubble Method
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: int long arrayList[], double firstSort[], int &timeNumFirstSort
//    OUTPUT: none.
//
// CALLS TO: ChangeElements()
// **********************************************************************
void BubbleSort(int long arrayList[], double firstSort[], int &timeNumFirstSort){


    int long startSortTime = 0,
             endSortTime = 0,
             elapseTime = 0;
    
    startSortTime = clock();
    
    for(int firstLoop = 0; firstLoop < MAX_IDX_SIZE; firstLoop++){
        //enter second loop
        for(int secondLoop = 0; secondLoop < MAX_IDX_SIZE; secondLoop++){
            if(arrayList[firstLoop] > arrayList[secondLoop]){
                    
                ChangeELements(&arrayList[firstLoop], &arrayList[secondLoop]);
                
            }   // end of if
        
        } // end of second for

    }   // end of first for
    
    endSortTime = clock();
    
    elapseTime = endSortTime - startSortTime;
    
    firstSort[timeNumFirstSort] = elapseTime;
    
    timeNumFirstSort++;
    
} // end of BubbleSort

//*********************************************************************
// FUNCTION: QuickSort
// DESCRIPTION: Sort Array using Quick Method
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: int long arrayList[], int firstValue, int secondValue
//    OUTPUT: none.
//
// CALLS TO: QuickSort()
// **********************************************************************

void QuickSort(int long arrayList[], int firstValue, int secondValue){
    
    int tempList;
    
    if (firstValue < secondValue)
    {
        tempList = DivideList(arrayList, firstValue, secondValue);
        QuickSort(arrayList, firstValue, tempList);
        QuickSort(arrayList, tempList + 1, secondValue);
    }
    
    
    
} // end of QuickSort

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

int DivideList(int long arrayList[], int firstValue, int secondValue){
    
    int long tempList = arrayList[firstValue];
    int tempNumber = firstValue;
    
    for (int counter = firstValue + 1; counter < secondValue; counter++)
    {
        if (arrayList[counter] <= tempList)
        {
            tempNumber += 1;
            ChangeELements(&arrayList[tempNumber], &arrayList[counter]);
        }
        
    }
    
    ChangeELements(&arrayList[tempNumber], &arrayList[firstValue]);
    
    return tempNumber;
    
}  // end of DivideList

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

void ChangeELements(int long *firstNum, int long *secondNum){
    
    int long temp;
    
    temp = *firstNum;
    *firstNum = *secondNum;
    *secondNum = temp;
} // end of ChangeELements

//*********************************************************************
// FUNCTION: DisplayTimeResults
// DESCRIPTION: Display function used to print out Sorting Results
// IMPLEMENTED BY: Jose Lara
// Parameters:
//    INPUT: double firstSort[], int &firstDisplayNum, string typeOfSort
//    OUTPUT: none.
//
// CALLS TO: none.
// **********************************************************************

void DisplayTimeResults(double firstSort[], int &firstDisplayNum, string typeOfSort){
    
    int testNum = 0;
    testNum = static_cast<int>(firstSort[firstDisplayNum]);
    cout << setw(18) << typeOfSort << " time " << testNum <<"..."<< endl;
    firstDisplayNum++;
    
} // end of DisplayResults

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

bool ValidateArray(int long arrayList[]){
    
    bool flag = false;  // test for array to be in order
    
    // check for list in assending order
    for (int tempNum1 = 0; tempNum1 < (MAX_IDX_SIZE - 1); tempNum1++){
        if (arrayList[tempNum1] > arrayList[tempNum1 + 1]){
        
            return flag;
        }
        
        else
        {
            flag = true;
        }
        
    } // end of first loop

    
    flag = true;
    return flag;
    
    
} // end of ValidateArray

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

void DisplaySortResults(double firstAvgTime, double secondAvgTime, int numOfRep, string sortType1, string sortType2){
    
    cout << fixed << setprecision(1);
    cout << endl << endl;
    cout << "SORTING RESULTS" << endl;
    cout << "---------------" << endl;
    cout << setw(18) << sortType1 << "\t" << firstAvgTime << " clock ticks on average" << endl;
    cout << setw(18) << sortType2 << "\t" <<  secondAvgTime << " clock ticks on average" << endl << endl;
    
    
} // end of DisplaySortResults

