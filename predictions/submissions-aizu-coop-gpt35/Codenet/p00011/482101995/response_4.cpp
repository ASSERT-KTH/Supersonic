#include <iostream>
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

  int* StartingPoint = new int[w];
  for (int i = 0; i < w; i++) {
    StartingPoint[i] = i + 1;
  }

  for (int i = 0; i < n; i++) {
    THorizonalLine HorizonalLine;
    char Dummy;
    cin >> HorizonalLine.Left >> Dummy >> HorizonalLine.Right;
    swap(StartingPoint[HorizonalLine.Left - 1],
         StartingPoint[HorizonalLine.Right - 1]);
  }

  for (int i = 0; i < w; i++) {
    cout << StartingPoint[i] << endl;
  }

  delete[] StartingPoint;

  return 0;
}