#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_POINTS = 10000;
const int MAX_COORDINATE = 10000;
const int MAX_RADIUS = 10000;

typedef pair<int, int> pii;

int v[MAX_COORDINATE][MAX_POINTS];
int prefixSums[MAX_COORDINATE][MAX_POINTS];

// Radix sort implementation
void radixSort(vector<int>& arr) {
  const int base = 10;
  int maxElement = *max_element(arr.begin(), arr.end());

  for (int exp = 1; maxElement / exp > 0; exp *= base) {
    vector<int> count(base, 0);
    vector<int> output(arr.size());

    for (int i = 0; i < arr.size(); i++)
      count[(arr[i] / exp) % base]++;

    for (int i = 1; i < base; i++)
      count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
      output[count[(arr[i] / exp) % base] - 1] = arr[i];
      count[(arr[i] / exp) % base]--;
    }

    for (int i = 0; i < arr.size(); i++)
      arr[i] = output[i];
  }
}

int main() {
  int aN, bN, R;

  while (cin >> aN >> bN >> R, aN) {
    // Clear 2D array
    for (int i = 0; i < MAX_COORDINATE; i++)
      fill(v[i], v[i] + MAX_POINTS, 0);

    // Read points and populate 2D array
    for (int i = 0; i < aN; i++) {
      int x, y;
      cin >> x >> y;
      v[y][i] = x;
    }

    // Sort each row using radix sort
    for (int i = 0; i < MAX_COORDINATE; i++) {
      vector<int> row(v[i], v[i] + MAX_POINTS);
      radixSort(row);
      copy(row.begin(), row.end(), v[i]);
    }

    int D = 4 * R;
    int ans = 0;

    for (int i = 0; i < bN; i++) {
      int x, y;
      cin >> x >> y;

      int m = sqrt((D - 0) * (D + 0));

      for (int p = -D; p <= D; p++) {
        if (y + p < 0 || y + p >= MAX_COORDINATE)
          continue;

        int left = lower_bound(v[y + p], v[y + p] + MAX_POINTS, x - m) - v[y + p];
        int right = upper_bound(v[y + p], v[y + p] + MAX_POINTS, x + m) - v[y + p];

        ans += right - left;
      }
    }

    cout << ans << endl;
  }

  return 0;
}