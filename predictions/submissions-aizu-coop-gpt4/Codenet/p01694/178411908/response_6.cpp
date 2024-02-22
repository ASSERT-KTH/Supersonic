#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Define the valid transitions
bool transitions[4][4] = {{false, true, false, false},
                          {true, false, false, false},
                          {false, false, false, true},
                          {false, false, true, false}};

int main() {
  // Map the strings to integers
  map<string, int> strToInt = {{"lu", 0}, {"ru", 1}, {"ld", 2}, {"rd", 3}};

  int n;
  while (cin >> n, n) {
    int ans = 0;
    string nowStr, nextStr;
    int now = -1, next;

    // Process each string
    for (int i = 0; i < n; ++i) {
      cin >> nextStr;
      next = strToInt[nextStr];

      // If now != -1, then we have a previous string to compare with
      if (now != -1 && transitions[now][next]) {
        ++ans;
      }

      now = next;
    }

    cout << ans << endl;
  }

  return 0;
}