/*
Emilee Mason
ID#2321064
emmason@chapman.edu
CPSC 350-01
Assignment 6: Sorting
*/
#include "InsertSort.h"

class MergeSort : public BasicOps{
  public:
    MergeSort();
    MergeSort(string userInput);
    ~MergeSort();

    void RunMergeSort();

  private:
    //method that gets called recursively in RunMergeSort()
    void MergeArray(double* numbers, int starting, int mid, int ending);
    void SplitArray(double* numbers, int starting, int ending);

};
