#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(NULL); 
  int t = 0;
  int a, b, c;
  cin >> a >> b >> c;
  const int min_bc = min(b, c);
  for (int s = a; s <= min_bc; s++) {
    if (c % s == 0) {
      t++;
    }
  }
  cout << t << endl;
  return 0;
}