/**
 * @file linkedList.h
 * @author Alex Shelton
 * @date 2020-10-15
 */

// #include <iostream>

//Implementation of Node class
class Node {
  public:
    int value;
    Node* next;
};


class LinkedList {
  public:
  LinkedList();
  void remove(int target);
  void insert(int value);
  const void display();
  private:
    Node* head;
};

//linked list constructor
LinkedList::LinkedList() {
  head = NULL;
}

void LinkedList::insert(int value) {
  //if the head is empty, list is empty.
  //set head value to value and point to null
  if(head == NULL) {
    head = new Node;
    head -> value = value;
    head -> next = NULL;
  }
  //else traverse list till end of list
  else {
    Node *cursor = head;
    while(cursor -> next != NULL) {
      cursor = cursor -> next;
    }
    cursor -> next = new Node;
    cursor = cursor -> next;
    cursor -> value = value;
    cursor -> next = NULL;
  }
}

void LinkedList::remove(int target) {
  //if the head of the value is node set to null
  if(head -> value == target) {
    Node* dptr = head;
    head = head -> next;
    delete dptr;

    }
  else {
    Node *trail;
    Node *cursor = head;
    //loop till cursor is on value or if cursor has reached the end of the list(NULL)
    while(cursor != NULL && cursor -> value != target) {
      trail = cursor;
      cursor = cursor -> next;
    }
    //if cursor reaches NULL, the target value was never reached
    if(cursor == NULL) { return; }
    //else unlink node pointed to by cursor
    else{
      trail -> next = cursor -> next; //link the trail to the node in front of the node to delete
      delete cursor;
    }
 
  }

}

const void LinkedList::display()  {
  Node* cursor = head;
  while(cursor != NULL) {
    std::cout << cursor -> value << " ";
    cursor = cursor -> next;  //iterate pointer
  }
  std::cout << '\n';
}


int main() {
  LinkedList list;

  for(int i = 0; i < 10; i++) {
    list.insert(i);
  }
  list.display();
  list.remove(0);
  list.display();
  list.remove(9);
  list.display();
  list.remove(4);
  list.display();

  return 0;
}