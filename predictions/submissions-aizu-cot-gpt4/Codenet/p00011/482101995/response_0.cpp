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
  THorizonalLine HorizonalLine;

  for (int i = 0; i < n; i++) {
    char Dummy;
    cin >> HorizonalLine.Left >> Dummy >> HorizonalLine.Right;
    swap(HorizonalLine.Left, HorizonalLine.Right);
  }

  for (int i = 0; i < w; i++) {
    cout << i+1 << endl;
  }

  return 0;
}