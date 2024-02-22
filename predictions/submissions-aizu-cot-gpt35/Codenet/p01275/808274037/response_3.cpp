#include <iostream>
using namespace std;

int minRotations(string s, string t) {
  int k = s.length();
  int ans = k;
  int M = 10;

  for (int rot = 0; rot < M; rot++) {
    int rotations = 0;
    for (int i = 0; i < k; i++) {
      if ((t[i] - s[i] + M) % M != rot) {
        rotations++;
      }
    }
    ans = min(ans, rotations);
  }
  
  return ans;
}

int main() {
  int k;
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    cout << minRotations(s, t) << endl;
  }
}