/*
Emilee Mason
ID#2321064
emmason@chapman.edu
CPSC 350-01
Assignment 6: Sorting
*/

//base class that will hold the times and the array of everything
//all other classes will derive from this one
#include "FileProcessor.h"
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

class BasicOps {
  public:
    BasicOps();
    BasicOps(string userInput);
    ~BasicOps();

    void PrintArray();

  protected:
    FileProcessor *myFiles;
    double* myArray;
    int arrayNumber;
    struct tm * rawStartTimeInfo;
    struct tm * rawFinishTimeInfo;

    void SetUpArray(string FileName);
    void SetUpRandomArray(int totalNum);

    void SetStartTime();
    void SetFinishTime();

};
