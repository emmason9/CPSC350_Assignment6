/*
Emilee Mason
ID#2321064
emmason@chapman.edu
CPSC 350-01
Assignment 6: Sorting
*/
#include "MergeSort.h"

class QuickSort : public BasicOps{
  public:
    QuickSort();
    QuickSort(string userInput);
    ~QuickSort();

    void RunQuickSort();

  private:
    //both called by RunQuickSort()
    int DivideArray(int low, int high);
    int SortArray(int low, int high);
};
