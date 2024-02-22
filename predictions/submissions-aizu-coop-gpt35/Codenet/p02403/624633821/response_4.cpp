#include <iostream>
#include <utility>

using namespace std;

int main() {
  int a = 0;
  pair<int, int> dimensions[100];

  while (1) {
    cin >> dimensions[a].first >> dimensions[a].second;
    if (dimensions[a].first == 0 && dimensions[a].second == 0)
      break;
    a++;
  }

  for (int b = 0; b < a; b++) {
    for (int i = 0; i < dimensions[b].first; i++) {
      for (int j = 0; j < dimensions[b].second; j++) {
        cout << "#";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}