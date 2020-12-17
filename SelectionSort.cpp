/*
Emilee Mason
ID#2321064
emmason@chapman.edu
CPSC 350-01
Assignment 6: Sorting
*/
#include "SelectionSort.h"

//default constructor
SelectionSort :: SelectionSort(){
  myFiles = new FileProcessor();
  myArray = new double[128];
  arrayNumber = 128;
}

//overloaded constructor
SelectionSort :: SelectionSort(string userInput){
  myFiles = new FileProcessor();
  try{
    int totalNumber = stoi(userInput);
    cout<<"Creating new array for SelectionSort with "<<userInput<<" elements..."<<endl;
    SetUpRandomArray(totalNumber);
  } catch (std::exception other){
    cout<<"Opening file..."<<endl;
    SetUpArray(userInput);
  }
  cout<<"Finished!\n"<<endl;
}

//destructor
SelectionSort :: ~SelectionSort(){
  delete myFiles;
//  delete[] myArray;
}

//runs the selection sort process and prints out times
void SelectionSort :: RunSelectionSort(){
  SetStartTime();
  int i,j;
  int smallestIndex;
  double tempNum;
  for(i=0; i<arrayNumber-1; ++i){
    smallestIndex=i;
    for(j=i+1; j<arrayNumber; ++j){
      if(myArray[j] < myArray[smallestIndex]){
        //new smallest index!
        smallestIndex = j;
      }
    }
    //swapping the numbers around
    tempNum = myArray[i];
    myArray[i] = myArray[smallestIndex];
    myArray[smallestIndex] = tempNum;
  }
  SetFinishTime();
}
