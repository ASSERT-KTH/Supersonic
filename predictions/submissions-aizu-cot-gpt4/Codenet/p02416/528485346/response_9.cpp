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
    int length = strlen(num);
    for (int i = 0; i < length; i++) {
      sum += num[i] - '0';
    }
    cout << sum << "\n";
  }
  return 0;
}