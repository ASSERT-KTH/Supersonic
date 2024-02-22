#include <iostream>
#include <vector>
using namespace std;

int main() {
  int w;
  cin >> w;
  int n;
  cin >> n;
  vector<int> StartingPoint(w, 0);
  for (int i = 0; i < n; i++) {
    int Left, Right;
    char Dummy;
    cin >> Left >> Dummy >> Right;
    swap(StartingPoint[Left - 1], StartingPoint[Right - 1]);
  }
  for (int i = 0; i < w; i++) {
    cout << StartingPoint[i] << '\n';
  }
  return 0;
}