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
  int StartingPoint[w];
  for (int i = 0; i < n; i++) {
    THorizonalLine HorizonalLine;
    char Dummy;
    cin >> HorizonalLine.Left >> Dummy >> HorizonalLine.Right;
    StartingPoint[HorizonalLine.Left - 1] = HorizonalLine.Right;
    StartingPoint[HorizonalLine.Right - 1] = HorizonalLine.Left;
  }
  for (int i = 0; i < w; i++) {
    if (StartingPoint[i] == 0) {
      cout << i + 1 << endl;
    } else {
      cout << StartingPoint[i] << endl;
    }
  }
  return 0;
}