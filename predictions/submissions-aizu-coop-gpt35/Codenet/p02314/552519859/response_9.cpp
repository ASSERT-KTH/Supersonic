#include <iostream>
#include <cmath>
using namespace std;

const int INF = 2000000000;

int main() {
  int n, m;
  cin >> n >> m;
  
  int* c = new int[m+1]; // Dynamically allocate c array
  int* mini = new int[n+1]; // Dynamically allocate mini array

  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }

  for (int i = 1; i <= n; i++) {
    mini[i] = INF;
  }

  for (int i = 1; i <= m; i++) {
    for (int j = c[i]; j <= n; j++) { // Update loop start from c[i]
      mini[j] = min(mini[j], mini[j - c[i]] + 1);
    }
  }

  cout << mini[n] << endl;

  delete[] c; // Deallocate c array
  delete[] mini; // Deallocate mini array

  return 0;
}