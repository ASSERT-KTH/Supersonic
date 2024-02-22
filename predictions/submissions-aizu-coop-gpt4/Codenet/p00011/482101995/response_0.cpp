#include <iostream>
#include <vector>
using namespace std;
struct THorizonalLine {
  int Left;
  int Right;
};
int main() {
  ios_base::sync_with_stdio(false); //Fast IO
  cin.tie(NULL);
  int w;
  cin >> w;
  int n;
  cin >> n;
  vector<int> NewPosition(w+1, 0);
  for (int i = 1; i <= w; i++) {
    NewPosition[i] = i;
  }
  for (int i = 0; i < n; i++) {
    THorizonalLine HorizonalLine;
    char Dummy;
    cin >> HorizonalLine.Left >> Dummy >> HorizonalLine.Right;
    swap(NewPosition[HorizonalLine.Left], NewPosition[HorizonalLine.Right]);
  }
  for (int i = 1; i <= w; i++) {
    cout << NewPosition[i] << "\n";
  }
  return 0;
}