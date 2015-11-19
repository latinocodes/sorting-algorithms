//***************************************************************************
// PROGRAM FILENAME: Todd-assn4-funcs.h
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
//***************************************************************************

#ifndef __LaraTodd_assn4__Todd_assn4_funcs__
#define __LaraTodd_assn4__Todd_assn4_funcs__

#include "LaraTodd-assn4-common.h"
#include "Lara-assn4-funcs.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <ctime>


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
void PauseF();

//----------------------------------------------------------------------
// FUNCTION: InsertationSort
// DESCRIPTION: Sort Array using Insertion Method
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int long arrayList[], firstSort[], timeNumFirstSort
//    OUTPUT: none.
//
// CALLS TO: none.
//----------------------------------------------------------------------
void InsertionSort(int long arrayList[], double firstSort[], int &timeNumFirstSort);

//----------------------------------------------------------------------
// FUNCTION: GenerateRandArray
// DESCRIPTION: Generates 2 identical arrays filled with random numbers
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int long arrayList[], int long secondArrayList[]
//    OUTPUT: none.
//
// CALLS TO: GetRandNumber()
//----------------------------------------------------------------------
void GenerateRandArray(int long arrayList[], int long secondArrayList[]);

//----------------------------------------------------------------------
// FUNCTION: MergeListTogether
// DESCRIPTION: put the list back together for MergeSort
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int *arrayList, int left, int right, int *tempArray
//    OUTPUT: none.
//
// CALLS TO: MergeListTogether().
//----------------------------------------------------------------------
void MergeListTogether(int long *arrayList, int left, int right, int long *tempArray);

//----------------------------------------------------------------------------------------------
// FUNCTION: MergeSort
// DESCRIPTION: Sort Array using Merge Method
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int long arrayList[]
//    OUTPUT: none.
//
// CALLS TO: MergeListTogether()
//-----------------------------------------------------------------------------------------------
int MergeSort(int long arrayList[]);

//----------------------------------------------------------------------
// FUNCTION: GetRandNumber
// DESCRIPTION: uses rand() to get random number from system
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT:  none
//    OUTPUT: returns a random integer.
//
// CALLS TO: none.
//----------------------------------------------------------------------
int GetRandNumber();

//----------------------------------------------------------------------
// FUNCTION: getMax
// DESCRIPTION: get Max number
// IMPLEMENTED BY: Robbie Todd II
// Parameters:
//    INPUT: int long xNum, int long yNum
//    OUTPUT: none.
//
// CALLS TO: none.
//----------------------------------------------------------------------
int long getMax(int long xNum, int long yNum);

#endif /* defined(__LaraTodd_assn4__Todd_assn4_funcs__) */
