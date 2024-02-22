#include <iostream>
#include <vector>
using namespace std;

struct THorizonalLine {
  int Left;
  int Right;
};

int main() {
  int w;
  cin >> w;

  int n;
  cin >> n;

  int startingPoint[w];
  for (int i = 0; i < w; i++) {
    startingPoint[i] = i + 1;
  }

  vector<THorizonalLine> horizontalLines(n);
  for (int i = 0; i < n; i++) {
    THorizonalLine horizonalLine;
    char Dummy;
    cin >> horizonalLine.Left >> Dummy >> horizonalLine.Right;
    horizontalLines[i] = horizonalLine;
  }

  for (int i = 0; i < n; i++) {
    int temp = startingPoint[horizontalLines[i].Left - 1];
    startingPoint[horizontalLines[i].Left - 1] = startingPoint[horizontalLines[i].Right - 1];
    startingPoint[horizontalLines[i].Right - 1] = temp;
  }

  for (int i = 0; i < w; i++) {
    cout << startingPoint[i] << endl;
  }

  return 0;
}