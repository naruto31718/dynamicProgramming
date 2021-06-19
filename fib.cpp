#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;
#define ll long long

ll fib(int n)
{
 ll tab[n + 1];
 tab[0] = 1;
 tab[1] = 1;
 for (int i = 2; i < n + 1; i++)
 {
  tab[i] = tab[i - 1] + tab[i - 2];
 }
 return tab[n - 1];
}

int main()
{

 clock_t begin, end;
 double time_spent;

 begin = clock(); // Time before calculating Fib number

 //anycode goes here between begin and end
 cout << fib(40) << endl;

 end = clock(); // Time before calculating Fib number

 time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

 printf("\nTime Taken %lf ", time_spent);

 return 0;
}
