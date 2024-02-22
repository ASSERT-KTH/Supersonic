#include <iostream>
#include <cstring>
using namespace std;

int main() {
  char num[1001];
  while (true) {
    cin >> num;
    if (num[0] == '0')
      break;

    int sum = 0;
    int len = strlen(num);  // Calculate string length once before loop
    for (int i = 0; i < len; i++) {
      sum += num[i] - '0';
    }

    cout << sum << "\n";  // Replace printf with cout
  }

  return 0;
}