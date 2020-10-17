/**
 * @file linkedlist.h
 * 
 *  Doubly linked list implementation
 *  methods:
      displays: print, reverse print
      adding: add to front, add to rear
      removal: remove head, remove tail, remove first occurence, remove last occurence
 * 
 */



#include <iostream>



template <typename T>
class LinkedList {
  public:
  LinkedList();
  ~LinkedList();
  const void display();
  const void reverseDisplay();
  void push(const T data);
  void append(const T data);
  void pop();
  void removeLast();
  void removeFirstOccurence(const T data);
  void removeLastOccurence(const T data);


private:
  struct Node {
    Node(const T data): data(data), next(NULL), prev(NULL) {}

    T data;
    Node* next;
    Node* prev;
  };

  Node* head;
  Node* tail;
};

template <typename T>
LinkedList<T>::LinkedList() {
  head = NULL;
  tail = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList() {
  Node* dptr;
  while(head != NULL){
    dptr = head;
    head = head -> next;
    delete dptr;
  }
}

template <typename T>
const void LinkedList<T>::display() {
  Node* cursor = head;
  while(cursor != NULL){
    std::cout << cursor->data << " ";
    cursor = cursor -> next;
  }
  std::cout << std::endl;
}

template <typename T>
const void LinkedList<T>::reverseDisplay() {
  Node* cursor = tail;
  while(cursor != NULL) {
    std::cout << cursor->data << " ";
    cursor = cursor->prev;
  }
  std::cout << std::endl;
}

template <typename T>
void LinkedList<T>::push(const T data) {
  Node* insert = new Node(data);
  //if theres a head link new node to it
  if(head != NULL) {
    insert -> next = head;
    head -> prev = insert;
  } else tail = insert; //else assign tail to insert as well

  //reassign head
  head = insert;
  }

  template <typename T>
  void LinkedList<T>::append(const T data) {
    //check if list is empty:
    Node* insert = new Node(data);
    if(!tail) {
      head = tail = insert;
    }
    else {
      tail->next = insert;
      insert->prev = tail;
      tail = tail->next;
    }
  }

template <typename T>
void LinkedList<T>::pop() {
  if(head == NULL) return;
  else {
    // if head and tail pointed to same node
    if(head == tail) {
      Node* dptr = head;  //point to node to delete
      head = tail = NULL; //reassign head and tail to NULL
      delete dptr;        //Delete node containing value
    }
    else{
      Node* dptr = head;   //point to head
      head = dptr -> next; //move head forward
      head -> prev = NULL; //changing prev pointer to null
      delete dptr;         //delete old head
    }
  }
}

template <typename T>
void LinkedList<T>::removeLast() {
  if(tail == NULL) return;
  else {
    if(head == tail) {
      Node* dptr = tail;
      head = tail = NULL;
      delete dptr;
    }
    else {
      Node* dptr = tail;    //assign delete pointer to tail
      tail = dptr -> prev;  //move tail pointer one back
      tail -> next = NULL;  //assigning next link of new tail to null
      delete dptr;         //delete old tail
    }
  }
}

template <typename T>
void LinkedList<T>::removeFirstOccurence(const T data){
  Node* cursor = head;
  while(cursor != NULL && cursor->data != data) {
    cursor = cursor -> next;
  }
  if(cursor == NULL) return;
  else if(cursor == head) this->pop();
  else if(cursor == tail) this->removeLast();
  else {
    // [prev node] [cursor] [next node ]
    //link node previous to target node to the node ahead of target node
    cursor -> prev -> next = cursor -> next;
    cursor -> next -> prev = cursor -> prev;

    delete cursor;
  }
}


template <typename T>
void LinkedList<T>::removeLastOccurence(const T data) {
  Node* cursor = tail;
  while(cursor != NULL && cursor -> data != data) {
    cursor = cursor -> prev;
  }
  if(cursor == NULL) return;
  else if(cursor == head) this->pop();
  else if(cursor == tail) this -> removeLast();
  else {
    cursor -> prev -> next = cursor -> next;
    cursor -> next -> prev = cursor -> prev;
    delete cursor;
  }
}
