#include <algorithm>
#include <iostream>
using namespace std;
int tb[1112], ans[1112], N;
int nr(int a) {
  int ret = 1;
  for (int i = 2; i < 1112; i++) {
    if (tb[i] > a)
      break;
    ret = i;
  }
  return tb[ret];
}
void precalc() {
  for (int i = 1; i < 1112; i++)
    tb[i] = i * i * i;
  for (int i = 1; i < 1112; i++)
    ans[i] = tb[i] + tb[1]; // instead of calling function calc() for each value
}
int main() {
  precalc();
  while (cin >> N, N)
    cout << ans[N] - tb[1] << endl; // subtracting tb[1] to get the correct value
}