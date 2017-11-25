#include "Heap.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <algorithm>
#include <fstream>
#include <cmath>

/* Isaiah Banta Allison Collier */

/* 
	A for loop runs our program multiple times, opens a text file,
	and inputs the size of our Data Set and the time it took, in milliseconds, for
	our heap sort and c++ sort() algorithm to be implemented. These values are 
	inputed in a CSV format so the data can then be imported into an Excel Spreadsheet
	for ease of analysis. 
*/
using namespace std;

int main() {
	
	//File management
 	ofstream sort1;
	ofstream sort2;
 	ofstream sort1log;
 	ofstream sort2log;
 	sort1.open("heapSort.txt");
 	sort2.open("c++Sort.txt");
 	sort1log.open("heapSortLog.txt");
 	sort2log.open("c++SortLog.txt");
	
	//Initialize our needed ints
 	int initial, end, elapsed, initial_2, end_2, elapsed_2;
	
	//Time value
	struct timeval tp;
	
	int dataSet = 0;
	
	//Run our sorting algorithm multiple times with multiple data sets
 	for(int test=10000;test<=250000;test+=10000) {
	dataSet = test;
	 
 	Heap heap(dataSet); 	// initialize Heap
 	int array[dataSet]; 	// allocate array memory
 	int array2[dataSet];
		
 	srand(time(0));		// seed our random number generator with current time
 	
 	for(int i=0;i<dataSet;i++) {
 		int p = rand() % 100;
  		array[i] = p;	//Array to be inserted and sorted with our Heap
		array2[i] = p;	//Array to be sorted with C++ sorting algorithm
}

// HEAP SORT BEGIN.. //
	gettimeofday(&tp,NULL);
  	initial = tp.tv_sec*1000+tp.tv_usec/1000;
  	
 	for(int h=0;h<dataSet;h++) {heap.insert(array[h]);}
 	for(int j=0;j<=dataSet;j++) {array[j] = heap.min();heap.removeMin();}
  	
 	gettimeofday(&tp,NULL);
  	end = tp.tv_sec*1000+tp.tv_usec/1000;
// HEAP SORT END. //
	
	elapsed = end - initial;	//Total elapsed time.

	cout << "Heap sort size: " << dataSet;
	cout << " time: " << elapsed << " milliseconds" << endl;

		
// C++ ALGORITHM SORT BEGIN.. //
	gettimeofday(&tp,NULL);
  	initial_2 = tp.tv_sec*1000+tp.tv_usec/1000;
  	
	sort(array2, array2 + dataSet);
	
	gettimeofday(&tp,NULL);
  	end_2 = tp.tv_sec*1000+tp.tv_usec/1000;
// C++ ALGORITHM SORT END. //
	
	elapsed_2 = end_2 - initial_2;	//Total elapsed time.

	cout << "sort() size:  " << dataSet;
	cout << " time: : " << elapsed_2 << " milliseconds" << endl;
	
	//Insert relevant data points into CSV txt files.
	sort1 << dataSet <<","<< elapsed<<endl;
        sort1log << log2(dataSet) << "," << log2(elapsed) <<endl; 
        sort2 << dataSet << "," << elapsed_2<<endl;
	sort2log << log2(dataSet) << "," << log2(elapsed_2) <<endl;

}
	//File management
 	sort1.close();
 	sort1log.close();
 	sort2.close();
 	sort2log.close();
	
//End of program
return 0;
}

