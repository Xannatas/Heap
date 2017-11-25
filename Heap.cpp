/* Isaiah Banta && Allison Collier */

#include "Heap.h"
#include <math.h>

using namespace std;

//Constructor.
//Initializing full tree with an array, Heap, with appropriate height and elements.
Heap::Heap(int n) {
 Size = 0;
 int height;
 height = floor(log2(n))+1;
 int elements;
 elements = pow(2, height) - 1; // Make full tree
 a = new int[elements];
}

//Destructor.
//Delete all elements of the array.
Heap::~Heap(){
  delete [] a;
}

//Returns the size of the Heap.
int Heap::size() const {
 return Size;
}

//Returns true if the size is 0.
bool Heap::empty() const {return size() == 0;}

//Inserts the item into the Heap, takes an int arg.
void Heap::insert(int e) {
	Size+=1;	//Increments size by 1
	int parent = Size/2;  //Location of parent
	int tracker = Size;
	if(size()==1){a[Size]=e;}  //If it is the first element added, insert
	if(e>=a[parent]){a[Size]=e;} //If it is greater than it's parent, insert
	else{
		while(e<a[parent] and parent>0){ //continue to Heap up until it is greater than it's parent
			a[0]=a[parent];
			a[parent]=e;
			a[(parent*2)+tracker%2]=a[0];
			parent/=2;
			tracker/=2;
		}
	}
}

//Returns the top of the tree
int Heap::min() const {return a[1];}

//Removes the top element of the Heap then checks that the Heap is still a properly implemented tree
void Heap::removeMin() {
	int child1 = 2, child2 = 3;  //Children of the top node of the tree
  	a[1]=a[Size];
  	Size-=1;	//Size decreases by 1
  	int x = a[1];
  	while((x>a[child1] and child1<=Size) or (x>a[child2] and child2<=Size)) { //If the new parent is greater than its' children
  		if(x>a[child1]){		//Heap down child1
  			a[child1/2]=a[child1];
  			a[child1]=x;
  			child1=child1*2;
  			child2+=1;
  		}
		if((x>a[child2])){		//Heap down child2
			a[child2/2]=a[child2];
			a[child2]=x;
			child1=child2*2;
			child2+=1;
		}
	}
}

