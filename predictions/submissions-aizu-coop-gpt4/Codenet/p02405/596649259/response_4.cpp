#include <iostream>
#include <string>
using namespace std;
int main() {
  int H, W;
  cin >> H >> W;
  // Creating pattern strings
  string pattern1 = ".#.#.#.#.#.#.#.#.#.#";
  string pattern2 = "#.#.#.#.#.#.#.#.#.#.";
  while (H != 0 && W != 0) {
    for (int i = 1; i <= H; i++) {
      // Using pattern strings to create rows
      if (i % 2 == 1) {
        cout << pattern1.substr(0, W) << endl;
      } else {
        cout << pattern2.substr(0, W) << endl;
      }
    }
    cout << endl;
    cin >> H >> W;
  }
  return 0;
}