/*
  Program takes 1 argument: length of array to build
  Fills array of that length with random numbers then preforms radix sort
*/
#include <iostream>
#include <cstdlib>       /* random */
#include <stdlib.h>     /* atoi */




/**
 * @brief prints the contents of array
 * 
 * @param ar 
 * @param n 
 */
void print(int ar[], int n)
{
  for(int i = 0; i < n; i++)
  {
    std::cout << ar[i] << " ";
  }
  std::cout << '\n';
}


/**
 * @brief returns the largest number in the array
 * 
 * @param arr 
 * @param n 
 * @return int 
 */
int largestNumber(int arr[], int n)
{
  int largest = arr[0];
  for(int i = 1; i < n; i++)
  {
    if(arr[i] > largest) { largest = arr[i]; }
  }
  return largest;
}


/**
 * @brief linear counting sort implementation. sorts elements
 * 
 * @param arr 
 * @param n 
 * @param k 
 */
void countingSort(int arr[], int n, int k) {
  //creating output array
  int count[n];
  int b[n];

  //initialize count array:
  for(int i = 0; i < n; i++) { count[i] = 0; }

  //counting the occurences of each digit into array
  //arr[i] / k * 10 gets the digit of the current place value. ones, tens, hundreds, etc
  for(int i = 0; i < n; i++) {
    count[(arr[i] / k) % 10]++;
  }

  //modifying count so that it contains actual position of values
  //create a running sum
  for(int i = 1; i < n; i++) {
    count[i] += count[i - 1];
  }

  //build the b array
  for(int i = n - 1; i >= 0; i--) {
    b[count[(arr[i] / k) % 10] - 1] = arr[i];
    count[(arr[i] / k) % 10]--;
  }

  //assigning input array to values of output array
  for(int i = 0; i < n; i++) { arr[i] = b[i]; }
}

/**
 * @brief implementation of radix sort, calls stable sort on each number from 1-k
 * 
 * @param arr 
 */
void radixSort(int arr[], int n)
{
  //find the max number in the array to find the max number of digits
  int largest = largestNumber(arr, n);

  //do a stable counting sort on each of the digits
  //exp is the current exponent, this is how we find ones, tens, hundreds, etc
  //calls stable sort on array with each place value
  for (int exp = 1; largest / exp > 0; exp *= 10)
  {
    countingSort(arr, n, exp);
  }
}




/**
 * @brief fills array of size n with random number range(0, n)
 * 
 * @param arr 
 * @param n 
 */
void fillArray(int arr[], int n)
{
  for(int i = 0; i < n; i++) { arr[i] = rand() % n + 1; }
}





/**
 * @brief driver code for radix sort implementation
 * 
 * @return int 
 */
int main(int argc, char **argv)
{

  //taking user input for length of array then fillng array of length with random numbers
  char *len = argv[1];
  int n = atoi(len);
  int arr[n];
  fillArray(arr, n);
  print(arr, n);      //showing array before sort
  radixSort(arr, n);  //implement radix sort
  std::cout << "\n\n";
  print(arr, n);      //showing array after sort
  return 0;
}