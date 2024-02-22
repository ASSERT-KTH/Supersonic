#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
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
  vector<int> StartingPoint(w);

  for (int i = 0; i < n; i++) {
    THorizonalLine HorizonalLine;
    char Dummy;
    cin >> HorizonalLine.Left >> Dummy >> HorizonalLine.Right;
    StartingPoint[HorizonalLine.Left - 1] = HorizonalLine.Left;
    StartingPoint[HorizonalLine.Right - 1] = HorizonalLine.Right;
  }

  copy(StartingPoint.begin(), StartingPoint.end(), ostream_iterator<int>(cout, "\n"));

  return 0;
}