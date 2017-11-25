/* Isaiah Banta && Allison Collier */

#include <iostream>

//Heap class, implementing a binary tree
class Heap {

 public:
  
  //Constructor.
  //Takes an int arg for the size of the binary tree
  Heap(int n);
 
  //Destructor.
  ~Heap();
 
  //Size of binary tree
  int size() const;
  
  //Returns true if the tree is empty, false otherwise
  bool empty() const;
  
  //Inserts an int into the tree
  void insert(int e);
 
  //Stores the location of the top of the tree, at [1] not [0]
  int min() const;
  
  //Removes the top element, min(), of the tree
  void removeMin();
  
 private: 
 
  //Size
  int Size;
 
  //The array used to implement our binary tree
  int* a;
};

