# CPSC350_Assignment6
Assignment 6 - Sorting Algorithms 

1. IDENTIFYING INFORMATION
a. Full Name: Emilee Mason	
b. Student ID: 2321064
c. Chapman Email: emmason@chapman.edu
d. Course Number and Section: CPSC 350-01
e. Assignment or Excercise Number: Assignment 6: Sorting

2. A LIST OF ALL SOURCE FILED SUBMITTED FOR THIS ASSIGNMENT
BasicOps.cpp		//the base class for all the sorting algorithms
BasicOps.h		
BubbleSort.cpp		//the bubble sort class derived from the BasicOps class
BubbleSort.h
FileProcessor.cpp	//processes text files, reading, writing, and appending 
FileProcessor.h
InsertSort.cpp		//the insertion sort class derived from the BasicOps class
InsertSort.h
main.cpp		//the main method file that runs the program 
Makefile		//allows easy compiling for the user
MergeSort.cpp		//the merge sort class derived from the BasicOps class
MergeSort.h
QuickSort.cpp		//the quick sort class derived from the BasicOps class
QuickSort.h
README			//this :>
SelectionSort.cpp	//the selection sort class derived from the BasicOps class
SelectionSort.h


3. A DESCRIPTION OF ANY KNOWN COMPILE OR RUNTIME ERRORS, CODE LIMITATIONS, OR DEVATIONS FROM ASSIGNMENT SPECIFICATIONS (IF APPLICABLE)
For some reason I keep getting these weird memory trace back errors
when I'm trying to delete the arrays of doubles. I've tried to 
dynamically delete them and they still show up? The code still runs
fine with the memory errors, but the lines of errors make it 
very distracting to see the time stamps of all the sorting algorithms
so I decided to just comment out the problem areas.

If you type a file that doesn't exist, the program will still run.
So make sure if you are typing in a file name, don't forget to put
the file into the project folder and also put the .txt extention 
at the end of it in the command line. :)

4. A LIST OF ALL REFERENCES USED TO COMPLETE THE ASSIGNMENT, INCLUDING PEERS (IF APPLICABLE)
https://www.cplusplus.com/reference/ctime/localtime/
This is how i got the time to show up in the code, I think it's showing UTC time?

Zybook helped me get the right algorithms for the sorts!

5. INSTRUCTIONS FOR RUNNING THE ASSIGNMENT
	1) Unzip the project folder
	2) place the folder in an area that can be accessed by docker
	3) Through docker, go into the project folder
	4) type "./Assignment6.exe [fileName.txt OR #]"
		Where # is the amount of values you want to appear in the array!
	5) the program will print out the sorting algorithm it's on as well as the times it
		starts and finishes sorting through the values. 
	6) to clean the project folder of all the exe files, type "make realclean"
