#include <iostream>
#include <vector>
using namespace std;
struct THorizonalLine {
  int Left;
  int Right;
};
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int w;
  cin >> w;
  int n;
  cin >> n;
  vector<int> StartingPoint(w);
  THorizonalLine HorizonalLine;
  for (int i = 0; i < n; i++) {
    char Dummy;
    cin >> HorizonalLine.Left >> Dummy >> HorizonalLine.Right;
    swap(StartingPoint[HorizonalLine.Left - 1],
         StartingPoint[HorizonalLine.Right - 1]);
  }
  for (int i = 0; i < w; i++) {
    cout << i + StartingPoint[i] + 1 << '\n';
  }
  return 0;
}