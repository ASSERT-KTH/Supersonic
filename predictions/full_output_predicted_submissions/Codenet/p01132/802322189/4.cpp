#include <bits/stdc++.h>
using namespace std;
int payment(vector<int> p) {
  return 10 * p[0] + 50 * p[1] + 100 * p[2] + 500 * p[3];
}
vector<int> charge(int m) {
  vector<int> ans(4);
  ans[3] = m / 500;
  m -= (m / 500) * 500;
  ans[2] = m / 100;
  m -= (m / 100) * 100;
  ans[1] = m / 50;
  m -= (m / 50) * 50;
  ans[0] = m / 10;
  return ans;
}
vector<int> _minus(vector<int> a, vector<int> b) {
  vector<int> ans(4);
  for (int i = 0; i < 4; i++)
    ans[i] = a[i] - b[i];
  return ans;
}
vector<int> _plus(vector<int> a, vector<int> b) {
  vector<int> ans(4);
  for (int i = 0; i < 4; i++)
    ans[i] = a[i] + b[i];
  return ans;
}
bool judge(vector<int> &f, vector<int> &ch) {
  for (int i = 0; i < 4; i++)
    if (f[i] == 1 and ch[i] > 0)
      return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  while (1) {
    vector<int> c(4);
    int sum = 0;
    ;
    for (int i = 0; i < 4; i++) {
      cin >> c[i];
      sum += c[i];
    }