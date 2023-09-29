#include <iostream>
#include <vector>
using namespace std;
struct THorizonalLine {
  int Left;
  int Right;
};
int main() {
  ios_base::sync_with_stdio(false); // disables synchronization between C and C++ standard streams
  cin.tie(NULL); // unties cin from cout, avoids flushing buffer on every input operation
  int w, n;
  cin >> w >> n;
  vector<int> StartingPoint(w);
  for (int i = 0; i < w; ++i) {
    StartingPoint[i] = i + 1;
  }
  for (int i = 0; i < n; ++i) {
    THorizonalLine HorizonalLine;
    char Dummy;
    cin >> HorizonalLine.Left >> Dummy >> HorizonalLine.Right;
    swap(StartingPoint[HorizonalLine.Left - 1], StartingPoint[HorizonalLine.Right - 1]);
  }
  for (int i = 0; i < w; ++i) {
    cout << StartingPoint[i] << '\n'; // '\n' is faster than endl, and we don't need to flush the buffer here
  }
  return 0;
}