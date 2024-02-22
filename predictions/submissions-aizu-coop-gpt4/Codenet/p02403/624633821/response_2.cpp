#include <iostream>
#include <string>
using namespace std;

int main() {
  int h, w;
  while (1) {
    cin >> h >> w;
    if (h == 0 && w == 0)
      break;

    // Create a string of '#'s of the required length and print it
    string line(w, '#');
    for (int i = 0; i < h; ++i) {
      cout << line << "\n";
    }
    cout << "\n";
  }

  return 0;
}