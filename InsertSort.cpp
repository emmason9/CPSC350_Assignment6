/*
Emilee Mason
ID#2321064
emmason@chapman.edu
CPSC 350-01
Assignment 6: Sorting
*/
#include "InsertSort.h"

//default constructor
InsertSort :: InsertSort(){
  myFiles = new FileProcessor();
  myArray = new double[128];
  arrayNumber = 128;
}

//overloaded constructor
InsertSort :: InsertSort(string userInput){
  myFiles = new FileProcessor();
  try{
    int totalNumber = stoi(userInput);
    cout<<"Creating new array for InsertionSort with "<<userInput<<" elements..."<<endl;
    SetUpRandomArray(totalNumber);
  } catch (std::exception other){
    cout<<"Opening file..."<<endl;
    SetUpArray(userInput);
  }
  cout<<"Finished!\n"<<endl;
}

//destructor
InsertSort :: ~InsertSort(){
  delete myFiles;
//  delete[] myArray;
}

//runs the insertion sort process and prints out times
void InsertSort :: RunInsertSort(){
  SetStartTime();
  int i,j;
  double tempNum;
  //iterate through the array
  for(i = 1; i < arrayNumber; ++i){
    j = i;
    //starting at i, compare until the current j is at the correct spot
    while( j > 0 && myArray[j] < myArray[j-1]){
      //swap!
      tempNum = myArray[j];
      myArray[j] = myArray[j-1];
      myArray[j-1] = tempNum;
      j--;
    }
  }
  SetFinishTime();
}
