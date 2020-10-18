/*
Min heap design and funcitons
File contains HeapNode as well 

*/


/*
  Min heap rules:
  ---------------------------------------------------------------------------
  all nodes have a parent in the tree
  all nodes are smaller then children
  all nodes left child can be found by taking 2*index + 1
  all right child nodes can be found by taking 2*index + 2
  all parent nodes from current index can be found doing floor (index-1)/2


*/

#include <algorithm> //swap
#include <vector>
#include <iostream>

template <typename T>
struct HeapNode {
  HeapNode(const T data): data(data) {}
  bool operator<(const HeapNode<T>& rhs) { return this->data < rhs.data; }
  bool operator <=(const HeapNode<T>& rhs) { return this->data <= rhs.data; }
  T data;
};


template <typename T>
class MinHeap {
public:
  // MinHeap() {}
  // ~MinHeap();
  bool isHeap()const;
  int size()const { return heap.size();} //returns the size of the vector, size()-1 = last node
  T peek()const;                       
  void insert(const T data);
  T extract_min();
  void heapify_up(const int node_index);
  void heapify_down(const int node_index);
private:
  //Node Index Retrieval functions
  int right_child_index(const int parent_index)const { return (2 * parent_index) + 2; }
  int left_child_index(const int parent_index)const { return (2 * parent_index) + 1; }
  int parent_index(const int node_index)const { return (node_index - 1) / 2; }
  std::vector <HeapNode<T> > heap;
};



//inserts new value into the min heap
template <typename T>
void MinHeap<T>::insert(const T data) {
  if (heap.empty()) { 
    heap.push_back(HeapNode<T>(data));
  }
  else { //if other elements, push to next bottom node, bubble up
    heap.push_back(HeapNode<T>(data));
    heapify_up(size() - 1); //bubble up on the current index 
  }
}



//extracts min(root) from heap and rebalances 
template <typename T>
T MinHeap<T>::extract_min() {
  if(heap.empty()) {
    std::cout << "Attempted to extract from empty heap, exiting" << std::endl;
    exit(1);
  }
  else if (heap.size() == 1) {
    T data = heap[0].data;
    heap.pop_back();
    return data;
  }
  else {
    T data = heap[0].data;
    std::swap(heap[0], heap[size() - 1]);
    heap.pop_back();
    heapify_down(0);
    return data;
  }
}

//rebalances heap from bottom up
template <typename T>
void MinHeap<T>::heapify_up(const int node_index) {
  if ( node_index != 0 && heap[parent_index(node_index)].data > heap[node_index].data ) {
    std::swap(heap[parent_index(node_index)], heap[node_index]); //swap the nodes
    heapify_up(parent_index(node_index)); //recursively call function with new index as parent
  }
}

//rebalances heap from top down 
template <typename T>
void MinHeap<T>::heapify_down(const int node_index) {
  int swap_index = node_index; //holds value of index to swap with, either left || right child
  int Lchild = left_child_index(node_index);
  int Rchild = right_child_index(node_index);

  //if left child is in heap size and is smaller than the current node
  if(Lchild < size() && heap[Lchild].data < heap[node_index].data) swap_index = Lchild;
  //if right child is in heap size and is smaller than the current node
  if(Rchild < size() && heap[Rchild].data < heap[node_index].data) swap_index = Rchild;
  //if r == l, swap with left
  if(Lchild < size() && Rchild < size() && heap[Lchild].data == heap[Rchild].data) swap_index = Lchild;

  //making the swap and recursively heapifying up
  if(heap[swap_index].data < heap[node_index].data) {
    std::swap(heap[swap_index], heap[node_index]);
    heapify_down(swap_index);
  }
}

//returns min(Root) from min heap without removing value
template <typename T>
T MinHeap<T>::peek()const {
  if(heap.empty()) {
    std::cout << "Attempted to peek an empty heap" << std::endl;
    exit(1);
  } else {
    return heap[0].data;
  }
}