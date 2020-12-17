/*
Emilee Mason
ID#2321064
emmason@chapman.edu
CPSC 350-01
Assignment 6: Sorting
*/
#include "BasicOps.h"
#include <string> //for string to int (stoi())

//default constructor
BasicOps :: BasicOps(){
  myFiles = new FileProcessor();
  myArray = new double[128];
  arrayNumber = 128;
}

//overloaded constructor
BasicOps :: BasicOps(string userInput){
  myFiles = new FileProcessor();
  try{
    int totalNumber = stoi(userInput);
    cout<<"Creating new array with "<<userInput<<" elements..."<<endl;
    SetUpRandomArray(totalNumber);
  } catch (std::exception other){
    cout<<"Opening file..."<<endl;
    SetUpArray(userInput);
  }
  cout<<"Finished!\n"<<endl;
}

//destructor
BasicOps :: ~BasicOps(){
  delete myFiles;
//  delete[] myArray;
}

//sets up array given a file name input
void BasicOps :: SetUpArray(string FileName){
  bool readerBool = myFiles->OpenReaderFile(FileName);
  if(readerBool){
    //file is open, can proceed
    //the file MUST only be made of numbers, therefore we shouldn't need to check if
    //the "user" input a string instead of numbers/integers
    string firstLineString;
    getline(myFiles->Reader, firstLineString);
    int firstLineInt = stoi(firstLineString);
    arrayNumber = firstLineInt;
    myArray = new double[arrayNumber];
    //while loop to input all doubles into the array
    string currentLine;
    double currentDouble;
    int currentIndex = 0;
    while(getline(myFiles->Reader, currentLine)){
      currentDouble = stod(currentLine);
      myArray[currentIndex] = currentDouble;
      currentIndex++;
    }
    myFiles->Reader.close();
  } else {
    cout<<"File did not open properly.\nDouble check if the file name is spelled correctly with the .txt extension!"<<endl;
  }
}

//sets up array given a number input for the total number of elements in the array
void BasicOps :: SetUpRandomArray(int totalNumber){
  myArray = new double[totalNumber];
  arrayNumber = totalNumber;
  srand(time(0));
  double randomNum;
  //creates given number of doubles between 0 and 1
  for(int i=0; i<arrayNumber; ++i){
    randomNum = rand()/(RAND_MAX + 1.0);
    myArray[i] = randomNum;
  }
}

//sets and prints out  start time of current sort
void BasicOps :: SetStartTime(){
  time_t timer;
  struct tm * timeinfo;
  time(&timer);
  timeinfo = localtime(&timer);
  rawStartTimeInfo = timeinfo;
  cout<<"Start Time:"<<endl;
  cout<<asctime(rawStartTimeInfo)<<endl;
}
//sets and prints out finish time of current sort
void BasicOps :: SetFinishTime(){
  time_t timer;
  struct tm * timeinfo;
  time(&timer);
  timeinfo = localtime(&timer);
  rawFinishTimeInfo = timeinfo;
  cout<<"Finish Time:"<<endl;
  cout<<asctime(rawFinishTimeInfo)<<endl;
}

//prints out entire array
void BasicOps :: PrintArray(){
  for(int i=0; i<arrayNumber; ++i){
    cout<<"["<<myArray[i]<<"] ";
  }
  cout<<endl;
}
