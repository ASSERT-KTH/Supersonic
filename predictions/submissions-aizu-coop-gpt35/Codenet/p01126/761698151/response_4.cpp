#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

int main() {
  int n, m, a;
  while (true) {
    string input;
    getline(cin, input);
    istringstream iss(input);
    iss >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    int** amida = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
      amida[i] = new int[m + 1];
      memset(amida[i], 0, (m + 1) * sizeof(int));
    }
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      getline(cin, input);
      istringstream iss(input);
      iss >> h >> p >> q;
      amida[p][h] = 1;
    }
    for (int j = 1000; j > 0; j--) {
      if (amida[a][j] == 1 || amida[a - 1][j] == 1)
        a += (amida[a][j] == 1) - (amida[a - 1][j] == 1);
    }
    cout << a << endl;
    for (int i = 0; i <= n; i++) {
      delete[] amida[i];
    }
    delete[] amida;
  }
  return 0;
}