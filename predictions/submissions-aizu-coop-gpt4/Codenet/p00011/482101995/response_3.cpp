#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int w;
  cin >> w;
  int n;
  cin >> n;

  vector<int> array(w);
  for (int i = 0; i < w; i++) {
    array[i] = i + 1;
  }

  for (int i = 0; i < n; i++) {
    int left, right;
    char dummy;
    cin >> left >> dummy >> right;
    swap(array[left - 1], array[right - 1]);
  }

  for (int i = 0; i < w; i++) {
    cout << array[i] << endl;
  }

  return 0;
}