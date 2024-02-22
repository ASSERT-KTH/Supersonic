#include <iostream>
using namespace std;

int main() {
  int n, m;
  int b[100];
  cin >> n >> m;

  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }

  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < m; j++) {
      int a;
      cin >> a;
      c += a * b[j];
    }
    cout << c << endl;
  }

  return 0;
}