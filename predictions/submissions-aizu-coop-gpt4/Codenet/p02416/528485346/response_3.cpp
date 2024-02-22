#include <iostream>
#include <string>
using namespace std;

int main() {
  string num;
  while (1) {
    cin >> num;
    if (num[0] == '0')
      break;
    int sum = 0;
    int len = num.length(); //Calculate the length of the string once
    for (int i = 0; i < len; i++) { //Replace strlen() call with len
      sum += num[i] - '0';
    }
    cout << sum << "\n";
  }
  return 0;
}