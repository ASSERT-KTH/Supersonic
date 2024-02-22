#include <iostream>
using namespace std;

void rec(int d, int p, int k, int ans, int dif[]) {
  const int M = 10;
  
  if (p == k) {
    ans = d;
    return;
  }
  
  if (d >= ans)
    return;
  
  int rot = dif[p];
  
  if (rot == 0) {
    rec(d, p + 1, k, ans, dif);
    return;
  }
  
  rec(d + 1, p + 1, k, ans, dif);
  
  int temp_d = d + 1;
  int temp_p = p + 1;
  
  for (int i = p; i < k; i++) {
    int temp_dif = (dif[i] - rot) % M;
    dif[i] = temp_dif;
    rec(temp_d, temp_p, k, ans, dif);
    dif[i] = (temp_dif + rot + M) % M;
  }
}

int main() {
  int k;
  
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    
    int dif[12];
    
    for (int i = 0; i < k; i++) {
      dif[i] = ((int)(t[i] - s[i]) + 10) % 10;
    }
    
    int ans = k;
    
    rec(0, 0, k, ans, dif);
    
    cout << ans << endl;
  }
  
  return 0;
}