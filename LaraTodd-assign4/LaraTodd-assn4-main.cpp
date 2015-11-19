//***************************************************************************
// PROGRAM FILENAME: LaraTodd-assn4-main.cpp
// DESCRIPTION:	This is the Main function file
//
// CLASS/TERM:	CS372
// DESIGNER:	Robbie Todd & Jose Lara
//
// CALLS TO:  Menu(), DisplayTimeResults(), DisplaySortResults(), ValidateArray()
//            MergeSort(), BubbleSort(), InsertionSort(), QuickSort()
//
//***************************************************************************

#include "Todd-assn4-funcs.h"
#include "Lara-assn4-funcs.h"
#include "LaraTodd-assn4-common.h"
#include <iostream>     // use for cout and cin
#include <iomanip>      // use for setw(), setpression().
#include <ctime>        // use for time()
#include <time.h>       // time
#include <cmath>
#include <string>       // string input
#include <stdlib.h>     // use for rand() and srand().

using namespace std;

int main(int argc, const char * argv[])
{
    
    //---------//
    //variables//
    //---------//
    char    choice1,                   // first choice for sorting
            choice2;                   // second sorting choice
    
    int long *arrayList = NULL;               // declares first array List
    int long *secondArrayList = NULL;         // declares second array List
    
    double *firstSort = NULL;                 // stores time for first choice array list
    double *secondSort = NULL;                // stores time for second choice array list
    
    
    string  nameOfFunc1,               // use to display name of first choice sorting method
            nameOfFunc2;               // use to display name of second choice sorting method
    
    bool validateArray = false;         // use to validates array
    
    //--------------------------//
    //function pointer variables//
    //--------------------------//
    void (*Insert_Function)(int long arrayList[], double firstSort[], int &timeNumFirstSort);
    void (*Bubble_Function)(int long arrayList[], double firstSort[], int &timeNumFirstSort);
    void (*Quick_Function)(int long arrayList[], int firstValue, int secondValue);
    int (*Merge_Function)(int long arrayList[]);
    
    // variables to call pointer functions
    Insert_Function = &InsertionSort;
    Bubble_Function = &BubbleSort;
    Quick_Function = &QuickSort;
    Merge_Function = &MergeSort;
    
    
    cout << endl; //space
    
    //------//
    //header//
    //------//
    cout << "This program is used to sort arrays that are stored with 100,000 random generated numbers between 1 and 30,000.  Then is clocks the time it takes to do each different sort and displays out the avgerages.  The sort types are Bubble, Merge, Quick and Insertion." << endl << endl;
    
    //-------------------------------//
    //call to srand for initialy seed//
    //the rand number generator      //
    //-------------------------------//
    srand(static_cast<double>(time(NULL)));
    
    
    do
    {
        
        int firstTimeTotal = 0,             // use to pass total time from the first sort choice
        secondTimeTotal = 0,            // use to pass total time from the second sort choice
        sortNum = 0,                    // user number of sorts to be perform
        timeNumFirstSort = 0,           // stores time it takes for first sort
        timeNumSecondSort = 0,          // stores time it takes for second sort
        firstDisplayNum = 0,            // use for array to store first choice time
        secondDisplayNum = 0;           // use for array to store sencond choice time
        
        // time varibales for quickSort
        int long quickFirstStartSortTime = 0,
        quickFirstEndSortTime = 0,
        quickFirstElapseTime = 0,
        quickFirstTimeNumFirstSort;
        
        int long quickSecondStartSortTime = 0,
        quickSecondEndSortTime = 0,
        quickSecondElapseTime = 0,
        quickSecondTimeNumFirstSort = 0;
        
        // time variables for MergeSort
        int long mergeFirstStartSortTime = 0,
        mergeFirstEndSortTime = 0,
        mergeFirstElapseTime = 0,
        mergeFirstTimeNumFirstSort;
        
        int long mergeSecondStartSortTime = 0,
        mergeSecondEndSortTime = 0,
        mergeSecondElapseTime = 0,
        mergeSecondTimeNumFirstSort = 0;
        
        double  firstAvgTime = 0,
                secondAvgTime = 0;
        
        //---------------------------//
        //dynamically allocate arrays//
        //to store time of each sort //
        //---------------------------//
        firstSort = new (nothrow) double[sortNum];
        secondSort = new (nothrow) double[sortNum];
        
        
        // Displays Menu to User
        Menu(choice1, choice2, sortNum);
        
        for(int num1 = 0; num1 < sortNum; num1++)
        {
            firstSort[num1] = 0;
            secondSort[num1] = 0;
        }
        
        // exit program
        if((choice1 == toupper('E')) && choice2 == toupper('E')){
            cout << "Exiting program" << endl;
            return 1;
        }
 
    
        for(int counter = 0; counter < sortNum; counter++){
            
            cout << "Starting sort # " << (counter + 1) << "..." << endl;
    
            //---------------------------//
            //dynamically allocate arrays//
            //for random numbers         //
            //---------------------------//
            arrayList = new int long[MAX_IDX_SIZE];
            secondArrayList = new int long[MAX_IDX_SIZE];
            
            //-----------------------------------------------------//
            //create 2 identical array with a max of 100,000 number//
            //list between 1 and 30,000 random numbers             //
            //-----------------------------------------------------//
            GenerateRandArray(arrayList, secondArrayList);
            
        switch (toupper(choice1)) {
                
            case 'B':
                nameOfFunc1 = "Bubble Sort";
                
                Bubble_Function(arrayList, firstSort, timeNumFirstSort);
                
                DisplayTimeResults(firstSort, firstDisplayNum, nameOfFunc1);
                
                break;
            case 'I':
                nameOfFunc1 = "Insertion Sort";
                
                Insert_Function(arrayList, firstSort, timeNumFirstSort);
                
                DisplayTimeResults(firstSort, firstDisplayNum, nameOfFunc1);
                
                break;
            case 'M':
                nameOfFunc1 = "Merge Sort";
   
                mergeFirstStartSortTime = clock();
                
                Merge_Function(arrayList);
                
                mergeFirstEndSortTime = clock();
                
                mergeFirstElapseTime = mergeFirstEndSortTime - mergeFirstStartSortTime;
                
                firstSort[mergeFirstTimeNumFirstSort] = static_cast<double>(mergeFirstElapseTime);
                
                DisplayTimeResults(firstSort, firstDisplayNum, nameOfFunc1);
                
                mergeFirstTimeNumFirstSort++;
                
                break;
                
            case 'Q':
                nameOfFunc1 = "Quick Sort";
                
                quickFirstStartSortTime = clock();
                
                Quick_Function(arrayList, 0, MAX_IDX_SIZE);
                
                quickFirstEndSortTime = clock();
                
                quickFirstElapseTime = quickFirstEndSortTime - quickFirstStartSortTime;
                
                firstSort[quickFirstTimeNumFirstSort] = quickFirstElapseTime;
                
                DisplayTimeResults(firstSort, firstDisplayNum, nameOfFunc1);
            
                quickFirstTimeNumFirstSort++;
                
                break;
                
            default:
                break;
        }
        
            
            switch (toupper(choice2)) {
                case 'B':
                    nameOfFunc2 = "Bubble Sort";
                    
                    Bubble_Function(secondArrayList, secondSort, timeNumSecondSort);
                    
                    DisplayTimeResults(secondSort, secondDisplayNum, nameOfFunc2);
                    
                    break;
                case 'I':
                    nameOfFunc2 = "Insertion Sort";
                    
                    Insert_Function(secondArrayList, secondSort, timeNumSecondSort);
                    
                    DisplayTimeResults(secondSort, secondDisplayNum, nameOfFunc2);
                    
                    break;
                case 'M':
                    nameOfFunc2 = "Merge Sort";
                    
                    mergeSecondStartSortTime = clock();
                    
                    Merge_Function(secondArrayList);
                    
                    mergeSecondEndSortTime = clock();
                    
                    mergeSecondElapseTime = mergeSecondEndSortTime - mergeSecondStartSortTime;
                    
                    secondSort[mergeSecondTimeNumFirstSort] = static_cast<double>(mergeSecondElapseTime);
                    
                    DisplayTimeResults(firstSort, firstDisplayNum, nameOfFunc2);
                    
                    mergeSecondTimeNumFirstSort++;
                    
                    break;
                case 'Q':
                    nameOfFunc2 = "Quick Sort";
                    
                    quickSecondStartSortTime = clock();
                    
                    Quick_Function(secondArrayList, 0, MAX_IDX_SIZE);
                    
                    quickSecondEndSortTime = clock();
                    
                    quickSecondElapseTime = quickSecondEndSortTime - quickSecondStartSortTime;
                    
                    secondSort[quickSecondTimeNumFirstSort] = quickSecondElapseTime;
                    
                    DisplayTimeResults(secondSort, secondDisplayNum, nameOfFunc2);
                    
                    quickSecondTimeNumFirstSort++;
                    
                    break;
                    
                default:
                    break;
            }
            
            if((validateArray = ValidateArray(arrayList)) == true)
            {
                if((validateArray = ValidateArray(secondArrayList)) == true)
                {
                    cout << setw(25) << "Sorts validated!!" << endl;
                }
                
                else
                {
                    cout << setw(25) << "Sorts not validated" << endl;
                }
            }
            
            else
            {
                cout << setw(25) << "Sorts not validated" << endl;
            }

            
            
            
            
            for(int num1 = 0; num1 < MAX_IDX_SIZE; num1++)
            {
                arrayList[num1] = 0;
                secondArrayList[num1] = 0;
            }
            
            delete [] arrayList;
            delete [] secondArrayList;
            
            
    }
        // stores total time for the first sorting choice
        for(int firstCounter = 0; firstCounter < sortNum; firstCounter++){
            
            firstTimeTotal = firstTimeTotal + static_cast<int>(firstSort[firstCounter]);
            
        }
        
        // stores total time for the second sorting choice
        for(int secondCounter = 0; secondCounter < sortNum; secondCounter++){
            
            secondTimeTotal = secondTimeTotal + static_cast<int>(secondSort[secondCounter]);
            
        }
        
        // get time average
        firstAvgTime = static_cast<double>(firstTimeTotal) / sortNum;
        secondAvgTime = static_cast<double>(secondTimeTotal) / sortNum;
        
        
        // deallocate memory use by the array
        delete [] firstSort;
        delete [] secondSort;
        
        DisplaySortResults(firstAvgTime, secondAvgTime, sortNum, nameOfFunc1, nameOfFunc2);
        
        
        
        // pauses the program after displaying results
        PauseF();
        

        
    } while((choice1 != toupper('E')) || (choice2 != toupper('E')));
    
    
    
    return 0;
}
