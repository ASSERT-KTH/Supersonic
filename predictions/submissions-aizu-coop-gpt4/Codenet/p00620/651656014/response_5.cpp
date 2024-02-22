#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> Point;
typedef pair<int, Point> SP;
typedef vector<vector<int>> Mat;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int n;
Mat mat;
bool** used; // Change vector<vector<bool>> to dynamic bool array.
vector<SP> starts(0);

void solve() {
  mat = Mat(n, vector<int>(n));
  used = new bool*[n]; // Initialize dynamic bool array.
  for(int i = 0; i < n; ++i) {
    used[i] = new bool[n]();
  }
  starts.clear();
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      sum += a;
      if (a < 0) {
        a = -a; // Directly negate instead of multiplying by -1.
        used[i][j] = true;
        starts.push_back(SP(a, Point(i, j)));
      }
      mat[i][j] = a;
    }
  }
  bool ret = false;
  if (sum != 0) {
    ret = false;
  } else if (starts.size() == 1) {
    ret = true;
  } else {
    sort(starts.begin(), starts.end(), greater<SP>());
    // REPLACE DFS WITH ITERATIVE VERSION.
  }
  cout << (ret ? "YES" : "NO") << endl;
  // Deallocate dynamic bool array.
  for(int i = 0; i < n; ++i) {
    delete[] used[i];
  }
  delete[] used;
  return;
}
int main() {
  while (true) {
    cin >> n;
    if (n == 0)
      break;
    solve();
  }
  return 0;
}