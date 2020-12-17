/*
Emilee Mason
ID#2321064
emmason@chapman.edu
CPSC 350-01
Assignment 6: Sorting
*/
#include "MergeSort.h"

//default constructor
MergeSort :: MergeSort(){
  myFiles = new FileProcessor();
  myArray = new double[128];
  arrayNumber = 128;
}

//overloaded constructor
MergeSort :: MergeSort(string userInput){
  myFiles = new FileProcessor();
  try{
    int totalNumber = stoi(userInput);
    cout<<"Creating new array for MergeSort with "<<userInput<<" elements..."<<endl;
    SetUpRandomArray(totalNumber);
  } catch (std::exception other){
    cout<<"Opening file..."<<endl;
    SetUpArray(userInput);
  }
  cout<<"Finished!\n"<<endl;
}

//destructor
MergeSort :: ~MergeSort(){
  delete myFiles;
//  delete[] myArray;
}

//runs/starts the merge sorting process and prints out times afterwards
void MergeSort :: RunMergeSort(){
  //temp array to remerge all numbers
  SetStartTime();
  double *mergedNumbers = new double[arrayNumber];
  // i = starting position
  // j = midpoint
  // k = end position
  int j = 0;
  int i = 0;
  int k = arrayNumber-1;

  if(i < k){
    j = (i+k)/2; //midpoint of the array
    //recursively sort left and right
    SplitArray(myArray, i, j);
    SplitArray(myArray, j+1, k);

    //merge left and right in sorted order
    MergeArray(myArray, i, j, k);
  }
  SetFinishTime();
}

//merges the divided arrays together into a single temp array
void MergeSort :: MergeArray(double* numbers, int i, int j, int k){
  // i = starting position
  // j = midpoint
  // k = end position
  int mergedSize = k - i + 1;
  int mergePosition = 0;
  int leftPosition = i;
  int rightPosition = j+1;
  double *mergedNumbers = new double[mergedSize];

//adding smallest elements from left/right parts into temp array
  while(leftPosition <= j && rightPosition <= k){
    if(numbers[leftPosition] <= numbers[rightPosition]){
      mergedNumbers[mergePosition] = numbers[leftPosition];
      ++leftPosition;
    } else {
      mergedNumbers[mergePosition] = numbers[rightPosition];
      ++rightPosition;
    }
    ++mergePosition;
  }

//if left side is not empty, add the last elements
  while(leftPosition <= j){
    mergedNumbers[mergePosition] = numbers[leftPosition];
    ++leftPosition;
    ++mergePosition;
  }

//if right side not empty, add the last elements
  while(rightPosition <= k){
    mergedNumbers[mergePosition] = numbers[rightPosition];
    ++rightPosition;
    ++mergePosition;
  }

  //copy merge number back to numbers
  for(int a = 0; a < mergedSize; ++a){
    numbers[i+a] = mergedNumbers[a];
  }

}

//splits the main array until it gets to single element arrays
void MergeSort :: SplitArray(double* numbers, int startingPosition, int endingPosition){
  int j = 0;

  if (startingPosition < endingPosition){
    j = (startingPosition + endingPosition)/2; //midpoint

    SplitArray(numbers, startingPosition, j);
    SplitArray(numbers, j+1, endingPosition);

    //merge left and right in sorted order

    MergeArray(numbers, startingPosition, j, endingPosition);
  }
}
