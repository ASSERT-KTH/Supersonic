#include <iostream>
#include <vector>
using namespace std;

int main() {
  int a = 0;
  vector<pair<int, int>> rectangles;

  while (true) {
    int height, width;
    cin >> height;
    if (height == 0)
      break;

    cin >> width;
    rectangles.push_back(make_pair(height, width));
    a++;
  }

  for (int b = 0; b < a; b++) {
    int height = rectangles[b].first;
    int width = rectangles[b].second;

    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        cout << "#";
      }
      cout << endl;
    }

    cout << endl;
  }

  return 0;
}