
/*
Driver function for the min heap implementation


*/



#include "min_heap.h"
#include <iostream>



int main() {
  MinHeap<int> heap;
  heap.insert(10);
  heap.insert(3);
  heap.insert(11);
  heap.insert(4);
  heap.insert(2);
  heap.insert(1);

  std::cout << "The min element in heap is: " << heap.peek() << std::endl;


  while(heap.size() > 0) {
    std::cout << heap.extract_min() << ' ';
  } std::cout << std::endl;



  return 0;
}