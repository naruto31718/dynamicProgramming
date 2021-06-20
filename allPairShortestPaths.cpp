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
#define INF 1000
#define N 4

using namespace std;

//Vertex are starting from 1
void allpairshortPath(int graph[N][N])
{
 int sp[N][N];
 for (int i = 0; i < N; i++)
 {
  for (int j = 0; j < N; j++)
  {
   sp[i][j] = graph[i][j];
  }
 }
 for (int k = 0; k < N; k++)
 {
  for (int i = 0; i < N; i++)
  {
   for (int j = 0; j < N; j++)
   {
    if ((sp[i][j] > (sp[i][k] + sp[k][j])) && (sp[i][k] != INF && sp[k][j] != INF))
    {
     sp[i][j] = sp[i][k] + sp[k][j];
    }
   }
  }
 }
 for (int i = 0; i < N; i++)
 {
  for (int j = 0; j < N; j++)
  {
   if (sp[i][j] == INF)
   {
    cout << "INF"
         << " ";
   }
   else
   {
    cout << sp[i][j] << " ";
   }
  }
  cout << endl;
 }
}

int main()
{
 int graph[N][N] = {
     {0, 3, INF, 7},
     {8, 0, 2, INF},
     {5, INF, 0, 1},
     {2, INF, INF, 0}};
 allpairshortPath(graph);
}