#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const double PI = 3.14159265358979323846;

template <typename T> void printA(vector<T> &printArray, char between = ' ') {
  int paSize = printArray.size();
  for (int i = 0; i < paSize; i++) {
    cerr << printArray[i] << between;
  }
  if (between != '\n') {
    cerr << endl;
  }
}

int main() {
  int n, W;
  cin >> n >> W;
  vector<int> weight(n), value(n);
  for (int i = 0; i < n; ++i)
    cin >> value[i] >> weight[i];
  
  vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
  
  for (int i = 0; i < n; ++i) {
    for (int w = 0; w <= W; ++w) {
      if (w >= weight[i]) {
        dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
      } else {
        dp[i + 1][w] = dp[i][w];
      }
    }
  }
  cout << dp[n][W] << endl;
  return 0;
}