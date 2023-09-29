#include <iostream>
#include <vector>
using namespace std;
struct THorizonalLine {
  int Left;
  int Right;
};
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int w;
  cin >> w;
  int n;
  cin >> n;
  vector<int> StartingPoint(w);
  for (int i = 0; i < w; i++) {
    StartingPoint[i] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    THorizonalLine HorizonalLine;
    cin >> HorizonalLine.Left >> HorizonalLine.Right;
    swap(StartingPoint[HorizonalLine.Left - 1],
         StartingPoint[HorizonalLine.Right - 1]);
  }
  for (int i = 0; i < w; i++) {
    cout << StartingPoint[i] << '\n';
  }
  return 0;
}