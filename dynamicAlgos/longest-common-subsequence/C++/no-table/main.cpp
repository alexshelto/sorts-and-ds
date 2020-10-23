
#include <iostream>




int max(const int num0, const int num1) {
  return (num0 > num1)? num0 : num1;
}

int LCS(char *X, char *Y, int m, int n) {
  if(m == 0 || n == 0) return 0;                        //base case
  if(X[m-1] == Y[n-1]) return 1 + LCS(X, Y, m-1, n-1); //if match recursively call adding 1 to sum
  else{
    return max(LCS(X,Y, m, n-1), LCS(X,Y, m-1, n));    //else call max on going either back 1 x or back 1 y
  }
}




//driver function
int main() {
    char X[] = "AGGTAB";  
    char Y[] = "GXTXAYB"; 

    int m = std::strlen(X);  
    int n = std::strlen(Y);

    std::cout << "Max substring length: " << LCS(X,Y, m, n) << std::endl;

  return 0;
}