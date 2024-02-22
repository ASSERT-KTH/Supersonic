#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string s;
  int inp;
  vector<int> elements;

  for (;;) {
    cin >> s;
    if (s == "end") {
      break;
    } else if (s == "insert") {
      scanf("%d", &inp);
      elements.push_back(inp);
      // Sort the vector in descending order after each insertion
      sort(elements.begin(), elements.end(), greater<int>());
    } else {
      printf("%d\n", elements.back());
      elements.pop_back();
    }
  }

  return 0;
}