#include <iostream>
using namespace std;
int main() {
  bool data[30] = {false};
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data[n - 1] = true;
  }
  for (int i = 0; i < 30; i++) {
    if (!data[i])
      cout << i + 1 << endl;
  }
}