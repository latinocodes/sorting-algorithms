//----------------------------------------------------------------------
// PROGRAM FILENAME: Todd-assn4-funcs.cpp
// DESCRIPTION:	This for the functions implemented Robbie Todd II
//
// CLASS/TERM:	CS372
// DESIGNER:	Robbie Todd
//
// FUNCTIONS:   PauseF - This Function is used to pause the screen
//              InsertationSort - Sort Array using Insertion Method
//              GenerateRandArray - Generates 2 identical arrays filled with random numbers
//              MergeListTogether - put the list back together for MergeSort
//              MergeSort - Sort Array using Merge Method
//              GetRandNumber - uses rand() to get random number from system
//              getMax - get Max number
//
//----------------------------------------------------------------------

#include "Todd-assn4-funcs.h"
#include "LaraTodd-assn4-common.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>     // srand, rand
#include <time.h>       // time

using namespace std;

//----------------------------------------------------------------------
// FUNCTION: PauseF
// DESCRIPTION: This Function is used to pause the screen
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: none.
//    OUTPUT: none.
//
// CALLS TO: none
//----------------------------------------------------------------------
void PauseF()
{
    cout << "Press enter to continue!";
    cin.ignore();
    cin.get();
}

//----------------------------------------------------------------------
// FUNCTION: GetRandNumber
// DESCRIPTION: uses rand() to get random number from system
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int arrayList
//    OUTPUT: returns a random integer.
//
// CALLS TO: none.
//----------------------------------------------------------------------
int GetRandNumber()
{
    int randNum = 0; //sets randNum to 0
    
    randNum = (rand() % Max_SIZE) + MIN_SIZE;
    
    return randNum;
}

//----------------------------------------------------------------------
// FUNCTION: GenerateRandArray
// DESCRIPTION: Generates 2 identical arrays filled with random numbers
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int arrayList[]
//    OUTPUT: none.
//
// CALLS TO: GetRandNumber()
//----------------------------------------------------------------------
void GenerateRandArray(int long arrayList[], int long secondArrayList[])
{
    for(int arrayNum = 0; arrayNum < MAX_IDX_SIZE; arrayNum++)
    {
        arrayList[arrayNum] = GetRandNumber();
        secondArrayList[arrayNum] = arrayList[arrayNum];
    }
}

//----------------------------------------------------------------------------------------------
// FUNCTION: MergeSort
// DESCRIPTION: Sort Array using Merge Method
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int arrayList[], double firstSort[], int &timeNumFirstSort, int lowNum, int highNum
//    OUTPUT: none.
//
// CALLS TO: MergeListTogether()
//-----------------------------------------------------------------------------------------------
int MergeSort(int long arrayList[])
{

    static int long *tempArray = new (nothrow) int long[MAX_IDX_SIZE];
    
    if(tempArray != NULL)
    {
        MergeListTogether(arrayList, 0, MAX_IDX_SIZE, tempArray);
        return 1;
    }
    else
    {
        return 0;
    }
}

//----------------------------------------------------------------------
// FUNCTION: MergeListTogether
// DESCRIPTION: Sort Array using Merge Method
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int arrayList[], int lowNum, int highNum, int pivot
//    OUTPUT: none.
//
// CALLS TO: MergeListTogether().
//----------------------------------------------------------------------
void MergeListTogether(int long *arrayList, int left, int right, int long *tempArray)
{
    //---------------------------------//
    //if statement used for one element//
    //---------------------------------//
    if(right == left + 1)
    {
        return;
    }
    
    //---------------------------------------------//
    //else statement used for more that one element//
    //---------------------------------------------//
    else
    {
        int tempNum = 0;
        int length = right - left;
        int midpoint_distance = length/2;
        
        //-----------------------------------------//
        //leftNum and rightNum are to the positions//
        //in the left and right subarrays          //
        //-----------------------------------------//
        int leftNum = left;
        int rightNum = left + midpoint_distance;
        
        //------------------//
        //sort each subarray//
        //------------------//
        MergeListTogether(arrayList, left, left + midpoint_distance, tempArray);
        MergeListTogether(arrayList, left + midpoint_distance, right, tempArray);
        
        //--------------------------------//
        //merge the arrays together using //
        //tempArraay for temporary storage//
        //--------------------------------//
        for(tempNum = 0; tempNum < length; tempNum++)
        {
            //-------------------------------------------------------//
            //check to see if any elements remain in the left array  //
            //if so check if there are any elements left in the right//
            //array if so then compare them.  else the merge must use//
            //take the element from the left array                   //
            //-------------------------------------------------------//
            if(leftNum < left + midpoint_distance &&
               (rightNum == right || getMax(arrayList[leftNum], arrayList[rightNum]) == arrayList[leftNum]))
            {
                tempArray[tempNum] = arrayList[leftNum];
                leftNum++;
            }
            
            else
            {
                tempArray[tempNum] = arrayList[rightNum];
                rightNum++;
            }
        }
        
        //----------------------------------------------//
        //copy the sorted subarray back to the arrayList//
        //----------------------------------------------//
        for(tempNum = left; tempNum < right; tempNum++)
        {
            arrayList[tempNum] = tempArray[tempNum - left];
        }
    }
}

//----------------------------------------------------------------------
// FUNCTION: getMax
// DESCRIPTION: get Max number
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int xNum, int yNum
//    OUTPUT: none.
//
// CALLS TO: none.
//----------------------------------------------------------------------
int long getMax(int long xNum, int long yNum)
{
    if(xNum > yNum)
    {
        return xNum;
    }
    
    else
    {
        return yNum;
    }
}

//----------------------------------------------------------------------
// FUNCTION: InsertationSort
// DESCRIPTION: Sort Array using Insertion Method
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int arrayList[], firstSort[], timeNumFirstSort
//    OUTPUT: none.
//
// CALLS TO: none.
//----------------------------------------------------------------------
void InsertionSort(int long arrayList[], double firstSort[], int &timeNumFirstSort)
{
    int long key = 0;

    int long startSortTime = 0,
             endSortTime = 0,
             elapseTime = 0;
    
    startSortTime = clock();
    
    for(int sortNum = 1; sortNum < MAX_IDX_SIZE; sortNum++)
    {
        for(int sortNum2 = sortNum; sortNum2 >= 1; sortNum2--)
        {
            if(arrayList[sortNum2] < arrayList[sortNum2 - 1])
            {
                key = arrayList[sortNum2];
                arrayList[sortNum2] = arrayList[sortNum2 - 1];
                arrayList[sortNum2 - 1] = key;
            }
            else
            {
                break;
            }
        }
    }
 
    endSortTime = clock();
    
    elapseTime = endSortTime - startSortTime;
    
    firstSort[timeNumFirstSort] = elapseTime;
    
    timeNumFirstSort++;
    
}
