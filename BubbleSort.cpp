/*
Emilee Mason
ID#2321064
emmason@chapman.edu
CPSC 350-01
Assignment 6: Sorting
*/
#include "BubbleSort.h"

BubbleSort :: BubbleSort(){
  myFiles = new FileProcessor();
  myArray = new double[128];
  arrayNumber = 128;
}

BubbleSort :: BubbleSort(string userInput){
  myFiles = new FileProcessor();
  try{
    int totalNumber = stoi(userInput);
    cout<<"Creating new array for BubbleSort with "<<userInput<<" elements..."<<endl;
    SetUpRandomArray(totalNumber);
  } catch (std::exception other){
    cout<<"Opening file..."<<endl;
    SetUpArray(userInput);
  }
  cout<<"Finished!\n"<<endl;
}

BubbleSort :: ~BubbleSort(){
  delete myFiles;
//  delete[] myArray;
}

void BubbleSort :: RunBubbleSort(){
//to iterate through the array once
  SetStartTime();
  //to iterate through the entire array
  for(int i=0; i<arrayNumber-1; ++i){
    double tempNum = 0.0;
    //to iterate with the first number through the list
    for(int j=0; j<arrayNumber-1; ++j){
      //check if the curent number is bigger than the next number,
      //then switch the two numbers
      if(myArray[j] > myArray[j+1]){
        tempNum = myArray[j+1];
        myArray[j+1] = myArray[j];
        myArray[j] = tempNum;
      }
    }
  }
  SetFinishTime();
}
