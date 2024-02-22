#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int a = 0, H[100], W[100];
  while (true) {
    cin >> H[a] >> W[a];
    if (H[a] == 0 && W[a] == 0)
      break;
    a++;
  }
  
  for(int b = 0; b < a; b++) {
    string line(W[b], '#');
    for (int i = 0; i < H[b]; i++) {
      cout << line << '\n';
    }
    cout << '\n';
  }

  return 0;
}