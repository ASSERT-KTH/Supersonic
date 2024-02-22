#include <iostream>
using namespace std;

const int M = 10;

int k;

int rec(int d, int p, string& s, string& t) {
  if (p == k) {
    return d;
  }
  
  int rot = ((int)(t[p] - s[p]) + M) % M;
  
  int ans = k;
  
  // No rotation
  ans = min(ans, rec(d, p + 1, s, t));
  
  // Perform rotations
  for (int i = p; i < k; i++) {
    t[i] = (t[i] - rot + M) % M;
    ans = min(ans, rec(d + 1, p + 1, s, t));
    t[i] = (t[i] + rot) % M;
  }
  
  return ans;
}

int main() {
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    
    int ans = rec(0, 0, s, t);
    
    cout << ans << endl;
  }
}