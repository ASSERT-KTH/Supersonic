#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  int minVal = INT_MAX;
  vector<int> freq(10001, 0);

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    minVal = min(minVal, t);
    freq[t]++;
  }

  freq[minVal]--;

  cout << minVal;
  for (int i = minVal; i < 10001; i++) {
    for (int j = 0; j < freq[i]; j++) {
      cout << ' ' << i;
    }
  }
  cout << endl;

  return 0;
}