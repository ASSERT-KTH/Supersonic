#include <iostream>
using namespace std;

const int M = 10;

int k, ans;
int diff[12];

int rotate(int val, int rot) {
  val += rot;
  if (val >= M)
    val -= M;
  return val;
}

void rec(int d, int p) {
  if (p == k) {
    ans = d;
    return;
  }
  if (d >= ans)
    return;
  
  int rot = diff[p];
  if (rot == 0) {
    rec(d, p + 1);
    return;
  }

  int temp = diff[p];
  for (int i = p; i < k; i++) {
    diff[i] = rotate(diff[i], -temp);
    rec(d + 1, p + 1);
    diff[i] = rotate(diff[i], temp);
  }
}

int main() {
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    
    for (int i = 0; i < k; i++) {
      diff[i] = (t[i] - s[i] + M) % M;
    }
    
    ans = k;
    rec(0, 0);
    cout << ans << endl;
  }
}