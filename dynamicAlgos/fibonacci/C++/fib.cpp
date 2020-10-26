
#include <iostream>
#include <stdlib.h>     /* atoi */

int fib(int n, int fib_ar[]) {
  if(n == 0) return 0;
  else if(n == 1) return 1;
  else {
     //stops from recursively solving the same fib number over and over
    if(fib_ar[n] == 0) {
      fib_ar[n] = fib(n-1, fib_ar) + fib(n-2, fib_ar);
    }
  }
  return fib_ar[n]; //return the overall fib number from list
}



//driver function
//uses command line argument for what fib number it finds
int main(int argc, char **argv) {
  char *len = argv[1];
  int n = atoi(len);
  int size = n + 2;
  int memo[size];
  for(int i = 0; i < size; i++) memo[i] = 0;
  std::cout << fib(n, memo);

  return 0;
}
