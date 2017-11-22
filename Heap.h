/* Isaiah Banta && Allison Collier */

#include <iostream>

class Heap {

 public:
  
  Heap(int n);
  ~Heap();
  int size() const;
  bool empty() const;
  void insert(int e);
  int min() const;
  void removeMin();
  
 private: 
 
  int Size;
  int* a;
};

