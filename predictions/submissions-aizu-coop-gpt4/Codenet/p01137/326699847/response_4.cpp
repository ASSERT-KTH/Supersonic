#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

const int MAXN = 100;

int main(void) {
  int e;
  int cube[MAXN+1], square[MAXN+1];

  // Precompute cubes and squares
  for (int i = 0; i <= MAXN; ++i) {
    cube[i] = i * i * i;
    square[i] = i * i;
  }

  while (cin >> e, e) {
    priority_queue<pair<int, pair<int, int>>> pq;

    // Initialize priority queue
    for (int z = 1; z <= MAXN && cube[z] <= e; ++z)
      pq.push(make_pair(-(e - cube[z] + z), make_pair(z, 0)));

    int m = e;
    while (!pq.empty()) {
      int val = -pq.top().first;
      int z = pq.top().second.first;
      int y = pq.top().second.second;
      pq.pop();

      m = min(m, val);

      // Add next candidate
      if (y + 1 <= z && cube[z] + square[y+1] <= e)
        pq.push(make_pair(-(e - (cube[z] + square[y+1]) + y + 1 + z), make_pair(z, y+1)));
    }

    cout << m << endl;
  }

  return 0;
}