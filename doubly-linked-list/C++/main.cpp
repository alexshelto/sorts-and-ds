/**
 * @file main.cpp
 * Driver function for doubly linked list
 * 
 */




#include "linkedlist.h"




//driver function for linked list
int main() {
  LinkedList<int> list;

  for(int i = 5; i >= 0; i--){
    list.push(i);
    list.append(i);
  }
  list.display();


  std::cout << "popped head: " << std::endl;
  list.pop();
  list.display();


  std::cout << "removed last node: " << std::endl;
  list.removeLast();
  list.display();

  int k;
  std::cout << "enter number to remove first occurence: ";
  std::cin >> k;
  std::cout << "removed first " << k << std::endl;
  list.removeFirstOccurence(k);
  list.display();


  std::cout << "enter number to remove the last occurence of: ";
  std::cin >> k;
  std::cout << "removed last " << k << std::endl;
  list.removeLastOccurence(k);
  list.display();

  std::cout << "reverse display" << std::endl;
  list.reverseDisplay();


  
  return 0;
}


