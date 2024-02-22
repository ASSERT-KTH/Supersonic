#include <iostream>
#include <vector>
using namespace std;

struct THorizonalLine {
  int Left;
  int Right;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int w;
  cin >> w;
  int n;
  cin >> n;
  
  vector<int> StartingPoint;
  for (int i = 1; i <= w; i++) {
    StartingPoint.push_back(i);
  }
  
  for (int i = 0; i < n; i++) {
    THorizonalLine HorizonalLine;
    char Dummy;
    cin >> HorizonalLine.Left >> Dummy >> HorizonalLine.Right;
    swap(StartingPoint[HorizonalLine.Left - 1], StartingPoint[HorizonalLine.Right - 1]);
  }
  
  for (vector<int>::iterator it = StartingPoint.begin(); it != StartingPoint.end(); ++it) {
    cout << *it << "\n";
  }

  return 0;
}