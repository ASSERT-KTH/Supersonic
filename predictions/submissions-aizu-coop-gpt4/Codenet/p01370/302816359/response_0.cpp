#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define rep(i, b) for (int i = 0; i < b; i++)
#define MAX 60
#define MAX_FIELD_SIZE (3 * MAX * (MAX + 1) + 1)
#define ZERO (MAX_FIELD_SIZE / 2)

int dx[6] = {0, 1, -1, 1, -1, 0};
int dy[6] = {1, 1, 0, 0, -1, -1};
vector<int> field(MAX_FIELD_SIZE);
int t, n;

// Function to calculate index
inline int calculate_index(int x, int y) {
    return y * (MAX * 2 + MAX * 2 + 1 - abs(y)) / 2 + x;
}

int main() {
  while (cin >> t >> n, t) {
    fill(field.begin(), field.end(), 1);
    int x, y;
    rep(i, n) {
      cin >> x >> y;
      field[ZERO + calculate_index(x, y)] = 0;
    }
    int start_x, start_y;
    cin >> start_x >> start_y;
    field[ZERO + calculate_index(start_x, start_y)] = 0;
    int count = 0;
    queue<pair<int, int>> rt; // Only store coordinates
    rt.push({start_x, start_y});
    while (!rt.empty()) {
      count++;
      auto [current_x, current_y] = rt.front();
      rt.pop();
      if (count < t) {
        rep(i, 6) {
          int next_x = current_x + dx[i];
          int next_y = current_y + dy[i];
          int index = calculate_index(next_x, next_y);
          if (field[ZERO + index]) {
            field[ZERO + index] = 0;
            rt.push({next_x, next_y});
          }
        }
      }
    }
    cout << count << endl;
  }
}