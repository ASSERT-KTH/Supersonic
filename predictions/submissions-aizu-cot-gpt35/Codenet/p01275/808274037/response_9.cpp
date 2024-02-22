#include <iostream>
using namespace std;

const int M = 10;

int main() {
  int k;
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    
    int ans = k;
    int dif[12];
    for (int i = 0; i < k; i++) {
      dif[i] = ((int)(t[i] - s[i]) + M) % M;
    }
    
    int d = 0;
    int p = 0;
    while (p < k) {
      if (d >= ans)
        break;
      
      int rot = dif[p];
      if (rot == 0) {
        p++;
        continue;
      }
      
      d++;
      p++;
      
      int new_rot = (rot + M) % M;
      for (int i = p; i < k; i++) {
        dif[i] = (dif[i] - rot) % M;
        d++;
      }
      for (int i = p; i < k; i++) {
        dif[i] = (dif[i] + new_rot) % M;
      }
    }
    
    cout << d << endl;
  }
}