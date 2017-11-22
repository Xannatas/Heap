/* Isaiah Banta && Allison Collier */

#include "Heap.h"
#include <math.h>

using namespace std;

Heap::Heap(int n) {
 Size = 0;
 int height;
 height = floor(log2(n))+1;
 int elements;
 elements = pow(2, height) - 1; // Make full tree
 a = new int[elements];
}

Heap::~Heap(){
  delete [] a;
}

int Heap::size() const {
 return Size;
}

bool Heap::empty() const {return size() == 0;}

void Heap::insert(int e) {
	Size+=1;
	int parent = Size/2;
	int tracker = Size;
	if(size()==1){a[Size]=e;}
	if(e>=a[parent]){a[Size]=e;}
	else{
		while(e<a[parent] and parent>0){
			a[0]=a[parent];
			a[parent]=e;
			a[(parent*2)+tracker%2]=a[0];
			parent/=2;
			tracker/=2;
		}
	}
}

int Heap::min() const {return a[1];}

void Heap::removeMin() {
	int child1=2, child2=3;
  	a[1]=a[Size];
  	Size-=1;
  	int x = a[1];
  	while((x>a[child1] and child1<=Size) or (x>a[child2] and child2<=Size)) {
  		if(x>a[child1]){
  			a[child1/2]=a[child1];
  			a[child1]=x;
  			child1=child1*2;
  			child2+=1;
  		}
		if((x>a[child2])){
			a[child2/2]=a[child2];
			a[child2]=x;
			child1=child2*2;
			child2+=1;
		}
	}
}

