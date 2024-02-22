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
  THorizonalLine HorizonalLine[n];
  for (int i = 0; i < n; i++) {
    char Dummy;
    cin >> HorizonalLine[i].Left >> Dummy >> HorizonalLine[i].Right;
  }
  for(int i = 0; i < n; i++) {
    swap(StartingPoint[HorizonalLine[i].Left - 1],
         StartingPoint[HorizonalLine[i].Right - 1]);
  }
  for (int i = 0; i < w; i++) {
    cout << StartingPoint[i] << "\n";
  }
  return 0;
}