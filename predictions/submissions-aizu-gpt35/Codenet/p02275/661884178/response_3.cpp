#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int min_val = INT_MAX;
  int t, freq[10001] = {0};
  for (int i = 0; i < n; i++) {
    cin >> t;
    min_val = min(min_val, t);
    freq[t]++;
  }
  cout << min_val;
  freq[min_val]--;
  for (int i = min_val; i < 10001; i++) {
    for(int j = 0; j < freq[i]; j++){
        cout << ' ' << i;
    }
  }
  cout << endl;
  return 0;
}