#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>
#include <climits>
#include <string>
// #define INF 1000
// #define N 4

using namespace std;

int MatrixChainOrder(int p[], int n)
{

 /* For simplicity of the program, one
    extra row and one extra column are
    allocated in m[][]. 0th row and 0th
    column of m[][] are not used */
 int m[n][n];

 int i, j, k, L, q;

 /* m[i, j] = Minimum number of scalar
    multiplications needed to compute the
    matrix A[i]A[i+1]...A[j] = A[i..j] where
    dimension of A[i] is p[i-1] x p[i] */

 // cost is zero when multiplying
 // one matrix.
 for (i = 1; i < n; i++)
  m[i][i] = 0;

 // L is chain length.
 for (L = 2; L < n; L++)
 {
  for (i = 1; i < n - L + 1; i++)
  {
   j = i + L - 1;
   m[i][j] = INT_MAX;
   for (k = i; k <= j - 1; k++)
   {
    // q = cost/scalar multiplications
    q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
    if (q < m[i][j])
     m[i][j] = q;
   }
  }
 }

 return m[1][n - 1];
}

int main()
{
 int n;            //number of matrices
 int sizes[n + 1]; //for dimensions of matrices A-1 to A-n
 for (int i = 0; i <= n; i++)
 {
  cin >> sizes[i];
 }
 int multiplications[n][n] = {0}; //for storing number of multiplications of all the combinations possible
 int split[n][n] = {0};           //stores after which matrix parenthesis must be added

 int j, min, q;

 for (int d = 1; d < n - 1; d++)
 { //maintain i and j differance used for taking 1 to n-1 matrices at a time
  for (int i = 1; i < n - d; i++)
  { // traversing matrices
   j = i + d;
   min = INT_MAX;
   for (int k = 1; k < j; k++)
   {
    q = multiplications[i][k] + multiplications[k + 1][j] + sizes[i - 1] * sizes[k] * sizes[j];
    if (q < min)
    {
     min = q;
     split[i][j] = k;
    }
   }
   multiplications[i][j] = min;
  }
 }
 cout << multiplications[1][n - 1];
}