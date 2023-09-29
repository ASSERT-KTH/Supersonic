#include <bits/stdc++.h>
using namespace std;
int main() {
  bool data[31] = {false};
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data[n] = true;
  }
  for (int i = 1; i <= 30; i++) {
    if (!data[i])
      cout << i << endl;
  }
}