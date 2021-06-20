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
#define INF INT_MAX
#define N 8

using namespace std;

int shortest_path(int graph[N][N], int n)
{
 int cost[n];
 cost[n - 1] = 0;
 for (int i = n - 2; i >= 0; i--)
 {
  cost[i] = INF;

  for (int j = i + 1; j < n; j++)
  {
   if (graph[i][j] != INF)
   {
    cost[i] = min(cost[i], graph[i][j] + cost[j]);
   }
  }
 }
 return cost[0];
}

int main()
{
 // Graph stored in the form of an
 // adjacency Matrix
 int graph[N][N] =
     {{INF, 1, 2, 5, INF, INF, INF, INF},
      {INF, INF, INF, INF, 4, 11, INF, INF},
      {INF, INF, INF, INF, 9, 5, 16, INF},
      {INF, INF, INF, INF, INF, INF, 2, INF},
      {INF, INF, INF, INF, INF, INF, INF, 18},
      {INF, INF, INF, INF, INF, INF, INF, 13},
      {INF, INF, INF, INF, INF, INF, INF, 2},
      {INF, INF, INF, INF, INF, INF, INF, INF}};

 cout << shortest_path(graph, N);
 return 0;
}