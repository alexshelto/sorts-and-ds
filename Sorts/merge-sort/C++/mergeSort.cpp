/**
 * @file mergeSort.cpp
 * @author Alex Shelton
 * @brief implementation of merge sort 
 */

#include <iostream>
#include <cstdlib>       /* random */
#include <stdlib.h>     /* atoi */




//filling array of len n, with random values from 0-100
void fillArray(int arr[], int n)
{
  for(int i = 0; i < n; i++) { arr[i] = rand() % 100 + 1; }
}

//Helper function to print array
void print(int arr[], int n)
{
  for(int i = 0; i < n; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << '\n';
}



void merge(int arr[], int l, int q, int r) {
  int leftLen = q - l + 1;  //calculate the length of the left subarray
  int rightLen = r - q;     //calculate thhe length of the right array
  //create temp arrays: 
  int left[leftLen];
  int right[rightLen];

  //copy data into left and right subarrays
  for(int i = 0; i < leftLen; i++) { left[i] = arr[l + i]; }        //left array = original array [left + i]
  for(int j = 0; j < rightLen; j++) { right[j] = arr[q + 1 + j]; }  //right array = original array [midpoint + 1 + j]


  //create begining index of left and right subarray
  int i = 0; //left array index
  int j = 0; //right array index
  int k = l; //index of original array

  //looping through both sub arrays, compare values place smaller values into array
  while(i < leftLen && j < rightLen) {
    if(left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    }
    else {
      arr[k] = right[j];
      j++;
    }
    k++; //itterate value of origianl array always
  }

  //copy remaining values of left and right sub array if any
  //loops will either never be used or only one subarray will be traversed
  while(i < leftLen) {
    arr[k] = left[i];
    i++;
    k++;
  }
  while(j < rightLen) {
    arr[k] = right[j];
    j++;
    k++;
  }


}




void mergeSort(int arr[], int l, int r) {
  if(l < r) {
    int q = l + (r - l) / 2; //calculating len/2 safely without overflow
    //recursively calling merge sort on left & right subarray
    mergeSort(arr, l, q);     
    mergeSort(arr, q + 1, r);
    merge(arr, l, q, r); //merge
  }
}


int main(int argc, char **argv)
{
  //taking user input for length of array then fillng array of length with random numbers
  char *len = argv[1];
  int n = atoi(len);
  int arr[n];
  fillArray(arr, n);

  print(arr, n);      //showing array before sort
  std::cout << "\n";
  mergeSort(arr, 0, n-1);
  print(arr, n);     //showing array after sort

  return 0;
}