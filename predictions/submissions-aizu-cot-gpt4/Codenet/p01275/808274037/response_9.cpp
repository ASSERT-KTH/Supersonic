#include <iostream>
using namespace std;
int k, ans;
int dif[12];
const int M = 10;
void rec(int d, int p) {
  if (p == k) {
    ans = d;
    return;
  }
  if (d >= ans)
    return;
  int rot = dif[p];
  if (rot == 0) {
    rec(d, p + 1);
    return;
  }
  rec(d + 1, p + 1);
  int i = p;
  while(i < k) {
    dif[i] -= rot;
    i += 2;
  }
  rec(d + 1, p + 1);
  i = p;
  while(i < k) {
    dif[i] += rot;
    if(dif[i] < 0) dif[i] += M; 
    i += 2;
  }
}
int main() {
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < k; i++) {
      dif[i] = t[i] - s[i];
      if(dif[i] < 0) dif[i] += M; 
    }
    ans = k;
    rec(0, 0);
    cout << ans << endl;
  }
}