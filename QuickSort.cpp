/*
Emilee Mason
ID#2321064
emmason@chapman.edu
CPSC 350-01
Assignment 6: Sorting
*/
#include "QuickSort.h"

//default constructor
QuickSort :: QuickSort(){
  myFiles = new FileProcessor();
  myArray = new double[128];
  arrayNumber = 128;
}

//overloaded constructor
QuickSort :: QuickSort(string userInput){
  myFiles = new FileProcessor();
  try{
    int totalNumber = stoi(userInput);
    cout<<"Creating new array for QuickSort with "<<userInput<<" elements..."<<endl;
    SetUpRandomArray(totalNumber);
  } catch (std::exception other){
    cout<<"Opening file..."<<endl;
    SetUpArray(userInput);
  }
  cout<<"Finished!\n"<<endl;
}

//destructor
QuickSort :: ~QuickSort(){
  delete myFiles;
//  delete[] myArray;
}

//starts the SortArray() process with the 0 and arraynumber and prints out times
void QuickSort :: RunQuickSort(){
  //setiing up the quicksort high and low numbers
  SetStartTime();
  int lowIndex = 0;
  int highIndex = arrayNumber-1;

  SortArray(lowIndex, highIndex);
  SetFinishTime();
}

//sorts array given the low and high indexes
int QuickSort :: SortArray(int lowIndex, int highIndex){
  //base case: if the parition size is 1 or 0 elements, then it's sorted
  if(lowIndex >= highIndex){
    return -1;
  }
  //parition data within the array. lowEndIndex returned from paritioning is the index of the low part's last element
  int lowEndIndex = DivideArray(lowIndex, highIndex);
  //recursively sort lower and upper halds
  SortArray(lowIndex, lowEndIndex);
  SortArray(lowEndIndex+1, highIndex);
}

//paritions array given the low and high index and creates a pivot point
int QuickSort :: DivideArray(int lowIndex, int highIndex){
  //find midpoint and pivot
  int midpoint = (lowIndex+highIndex)/2;
  double pivot = myArray[midpoint];
  double tempDouble;

  bool done = false;
  while(!done){
    //add lowindex while value at low < pivot
    while(myArray[lowIndex] < pivot){
      lowIndex = lowIndex + 1;
    }

    //subtract high index while pivot < value at high
    while(myArray[highIndex] > pivot){
      highIndex = highIndex - 1;
    }

    //if 0/1 element ramin, then numbers are partioned! return
    if(lowIndex >= highIndex){
      done = true;
    } else {
      //swap low and high
      tempDouble = myArray[lowIndex];
      myArray[lowIndex] = myArray[highIndex];
      myArray[highIndex] = tempDouble;

      //update low and high
      lowIndex = lowIndex +1;
      highIndex = highIndex -1;
    }//end of else
  }//end of done while loop
  return highIndex;
}
