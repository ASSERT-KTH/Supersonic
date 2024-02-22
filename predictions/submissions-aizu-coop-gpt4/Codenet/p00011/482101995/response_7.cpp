#include <iostream>
#include <array>
using namespace std;
struct THorizonalLine {
  int Left;
  int Right;
};
int main() {
  ios::sync_with_stdio(false); // disable synchronization with C's stdio
  int w;
  cin >> w;
  int n;
  cin >> n;
  array<int, 10000> StartingPoint; // replace vector with array
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
    cout << StartingPoint[i] << '\n'; // replace endl with '\n'
  }
  return 0;
}