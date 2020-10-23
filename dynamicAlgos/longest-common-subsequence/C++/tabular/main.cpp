

#include <iostream>



int max(const int num0, const int num1) {
  return (num0 > num1)? num0 : num1;
}


int lcs(char* X, char* Y, int m, int n) { 
	int S[m + 1][n + 1]; 
	int i, j; 
	for (i = 0; i <= m; i++) { 
		for (j = 0; j <= n; j++) { 
			if (i == 0 || j == 0) S[i][j] = 0; 
			else if (X[i - 1] == Y[j - 1]) S[i][j] = S[i - 1][j - 1] + 1; 
			else S[i][j] = max(S[i - 1][j], S[i][j - 1]); 
		} 
	} 
	return S[m][n]; 
} 


/* Driver program to test above function */
int main() 
{ 
	char X[] = "AGGTAB"; 
	char Y[] = "GXTXAYB"; 

	int m = strlen(X); 
	int n = strlen(Y); 

	printf("Length of LCS is %d\n", lcs(X, Y, m, n)); 

	return 0; 
} 
