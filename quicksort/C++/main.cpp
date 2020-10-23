

#include <iostream>
#include <cstdlib>       /* random */
#include <stdlib.h>     /* atoi */
#include <algorithm>




//helper function definitions

void fillArray(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    arr[i] = rand() % 100; //random number(0, 99)
  }
}

void swap(int* a, int* b) {  
    int t = *a;  
    *a = *b;  
    *b = t;  
} 

void displayList(const int arr[], int size) {
  for(int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}





//quicksort and partition implementation

int partition(int arr[], int low, int high) {
  int pivot = arr[high]; //pivot element last index
  int smaller = low - 1; // index of smaller element

  for(int i = low; i < high; i++) {
    //if curent element is smaller than pivot element
    if(arr[i] < pivot) {
      smaller += 1;  //increase index of smaller element
      swap(&arr[smaller], &arr[i]);
    }
  }
  //swapping high and seccond elements
  swap(&arr[smaller + 1],& arr[high]);
  return (smaller + 1);
}



void quickSort(int arr[], int low, int high) {
  if(low < high) {
    //partition index, quick sort around 
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}


// Driver function for quicksort implementation
// uses command line argument for size of array to quicksort
//
//
int main(int argc, char **argv) {
  //parsing command line argument (size)
  char *size = argv[1];
  int n = atoi(size);
  int arr[n];
  fillArray(arr, n);

  std::cout << "Original List" << std::endl;
  displayList(arr, n);

  std::cout << "\nSorted list" << std::endl;
  quickSort(arr, 0, n);
  displayList(arr,n);
  return 0;
}