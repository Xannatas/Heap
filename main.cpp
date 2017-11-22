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
ABOVE AND BEYOND: 
	Impleneted a for loop that runs our program multiple times, opens a text file,
	and inputs the size of our Data Set and the time it took, in milliseconds, for
	our heap sort and c++ sort() algorithm to be implemented. These values are 
	inputed in a CSV format so the data can then be imported into an Excel Spreadsheet
	for ease of analysis. 
*/
using namespace std;

int main() {
 	ofstream sort1;
	ofstream sort2;
 	ofstream sort1log;
 	ofstream sort2log;
 	sort1.open("heapSort.txt");
 	sort2.open("c++Sort.txt");
 	sort1log.open("heapSortLog.txt");
 	sort2log.open("c++SortLog.txt");
 	int initial, end, elapsed, initial_2, end_2, elapsed_2;
	struct timeval tp;
	int dataSet = 0;
 	for(int test=10000;test<=250000;test+=10000) {
	dataSet = test;
	 
 	Heap heap(dataSet); 	// initialize Heap
 	int array[dataSet]; 	// allocate array memory
 	int array2[dataSet];
 	srand(time(0));			// seed our random number generator 
 	
 	for(int i=0;i<dataSet;i++) {
 		int p = rand() % 100;
  		array[i] = p;
		array2[i] = p;
}

// HEAP SORT BEGIN.. //
	gettimeofday(&tp,NULL);
  	initial = tp.tv_sec*1000+tp.tv_usec/1000;
  	
 	for(int h=0;h<dataSet;h++) {heap.insert(array[h]);}
 	for(int j=0;j<=dataSet;j++) {array[j] = heap.min();heap.removeMin();}
  	
 	gettimeofday(&tp,NULL);
  	end = tp.tv_sec*1000+tp.tv_usec/1000;
// HEAP SORT END. //
	
	elapsed = end - initial;
	
    //for(int b=0;b<dataSet;b++) {cout<<array[b]<<endl;}

	cout << "Heap sort size: " << dataSet;
	cout << " time: " << elapsed << " milliseconds" << endl;

// C++ ALGORITHM SORT BEGIN.. //
	gettimeofday(&tp,NULL);
  	initial_2 = tp.tv_sec*1000+tp.tv_usec/1000;
  	
	sort(array2, array2 + dataSet);
	
	gettimeofday(&tp,NULL);
  	end_2 = tp.tv_sec*1000+tp.tv_usec/1000;
// C++ ALGORITHM SORT END. //
	
	elapsed_2 = end_2 - initial_2;

	cout << "sort() size:  " << dataSet;
	cout << " time: : " << elapsed_2 << " milliseconds" << endl;
	
	sort1 << dataSet <<","<< elapsed<<endl;
        sort1log << log2(dataSet) << "," << log2(elapsed) <<endl; 
        sort2 << dataSet << "," << elapsed_2<<endl;
	sort2log << log2(dataSet) << "," << log2(elapsed_2) <<endl;

}
 	sort1.close();
 	sort1log.close();
 	sort2.close();
 	sort2log.close();
return 0;
}

