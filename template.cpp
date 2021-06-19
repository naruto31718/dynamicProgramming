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

int main()
{

 clock_t begin, end;
 double time_spent;

 begin = clock(); // Time before calculating Fib number

 //anycode goes here between begin and end

 end = clock(); // Time before calculating Fib number

 time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

 printf("\nTime Taken %lf ", time_spent);

 return 0;
}
