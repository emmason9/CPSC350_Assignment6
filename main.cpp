/*
Emilee Mason
ID#2321064
emmason@chapman.edu
CPSC 350-01
Assignment 6: Sorting
*/
#include "QuickSort.h"

int main(int argc, char** argv) {
  string userInput = argv[1];//not 0, thats the call to run the program

  BubbleSort *bubble = new BubbleSort(userInput);
  cout<<"BubbleSort Times:"<<endl;
  bubble->RunBubbleSort();

  SelectionSort *selection = new SelectionSort(userInput);
  cout<<"SelectionSort Times:"<<endl;
  selection->RunSelectionSort();

  InsertSort *insertion = new InsertSort(userInput);
  cout<<"InsertionSort Times: "<<endl;
  insertion->RunInsertSort();

  MergeSort *merge = new MergeSort(userInput);
  cout<<"MergeSort Times:"<<endl;
  merge->RunMergeSort();

  QuickSort *quick = new QuickSort(userInput);
  cout<<"QuickSort Times:"<<endl;
  quick->RunQuickSort();

//I'm getting weird tracing errors when I try to delete these, I'm not sure why?
//the program still runs, but it just has a long list of memory tracing the computing that
//distracts from the times, so I took them out. 
/*  delete bubble;
  delete selection;
  delete insertion;
  delete merge;
  delete quick; */
  return 0;
}
