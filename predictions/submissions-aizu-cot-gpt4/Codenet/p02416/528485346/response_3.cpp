#include <iostream>
using namespace std;
int main() {
  char num;
  while (1) {
    cin >> num;
    if (num == '0')
      break;
    int sum = 0;
    for (int i = 0; num[i] != '\0'; i++) {
      sum += num[i] - '0';
    }
    cout << sum << endl;
  }
  return 0;
}