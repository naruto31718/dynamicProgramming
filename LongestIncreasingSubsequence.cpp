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

int maxe(int arr[], int n)
{
 int max = INT_MIN;
 for (int i = 0; i < n; i++)
 {
  if (arr[i] > max)
  {
   max = arr[i];
  }
  return max;
 }
}

// int LIS(int arr[], int n)
// {
//  int lis[n];
//  lis[0] = 1;
//  for (int i = 1; i < n; i++)
//  {
//   lis[i] = 1;
//   for (int j = 0; j < i; j++)
//   {
//    if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
//    {
//     lis[i] = lis[j] + 1;
//    }
//   }
//  }
//  return maxe(arr, n);
// }

int lis(int arr[], int n)
{
 int lis[n];

 lis[0] = 1;

 /* Compute optimized LIS values in
       bottom up manner */
 for (int i = 1; i < n; i++)
 {
  lis[i] = 1;
  for (int j = 0; j < i; j++)
   if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
    lis[i] = lis[j] + 1;
 }

 // Return maximum value in lis[]
 return *max_element(lis, lis + n);
}

int main()
{

 clock_t begin, end;
 double time_spent;

 begin = clock(); // Time before calculating Fib number

 //anycode goes here between begin and end
 int a[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};

 cout << lis(a, 9) << endl;

 end = clock(); // Time before calculating Fib number

 time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

 printf("\nTime Taken %lf ", time_spent);

 return 0;
}
