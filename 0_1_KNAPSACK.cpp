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
#include <stdio.h>
#include <time.h>

#define ll long long

using namespace std;

ll knapsack(ll w[], ll p[], ll n, ll cap)
{
 ll table[n + 1][cap + 1];
 for (ll i = 0; i <= n; i++)
 {
  for (ll j = 0; j <= cap; j++)
  {
   if (i == 0 || j == 0)
   {
    table[i][j] = 0;
   }
   else if (j >= w[i])
   {
    table[i][j] = max(p[i] + table[i - 1][j - w[i]], table[i - 1][j]);
   }
   else
   {
    table[i][j] = table[i - 1][j];
   }
  }
 }
 ll i = n, j = cap;
 while (i > 0 && j > 0)
 {
  if (table[i][j] == table[i - 1][j])
  {
   cout << i << " not included" << endl;
   i--;
  }
  else
  {
   cout << i << " included" << endl;
   i--;
   j = j - p[i];
  }
 }
 return table[n][cap];
}

int main()
{

 clock_t begin, end;
 double time_spent;

 begin = clock(); // Time before calculating Fib number

 //anycode goes here between begin and end
 ll w[] = {0, 2, 3, 4, 5};
 ll p[] = {0, 1, 2, 5, 6};
 ll n = 4;
 ll cap = 8;
 cout << knapsack(w, p, n, cap) << endl;

 end = clock(); // Time before calculating Fib number

 time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

 printf("\nTime Taken %lf ", time_spent);

 return 0;
}
