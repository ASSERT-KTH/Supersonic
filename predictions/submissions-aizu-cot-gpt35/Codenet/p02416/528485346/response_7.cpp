#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  string num;
  while (cin >> num) {
    if (num[0] == '0')
      break;
    int sum = 0;
    int len = num.length();
    for (int i = 0; i < len; i++) {
      sum += num[i] - '0';
    }
    cout << sum << endl;
  }
  return 0;
}