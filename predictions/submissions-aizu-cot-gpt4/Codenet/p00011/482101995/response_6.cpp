#include <iostream>
#include <vector>
using namespace std;
struct THorizonalLine {
  int Left;
  int Right;
};
int main() {
  ios_base::sync_with_stdio(false);
  int w, n;
  cin >> w >> n;
  int left, right;
  for (int i = 0; i < n; i++) {
    THorizonalLine HorizonalLine;
    char Dummy;
    cin >> HorizonalLine.Left >> Dummy >> HorizonalLine.Right;
    if(i == 0) {
        left = HorizonalLine.Left;
        right = HorizonalLine.Right;
      } else {
        if(HorizonalLine.Left == left) left = HorizonalLine.Right;
        else if(HorizonalLine.Left == right) right = HorizonalLine.Left;
        else if(HorizonalLine.Right == left) left = HorizonalLine.Left;
        else if(HorizonalLine.Right == right) right = HorizonalLine.Right;
      }
  }
  cout << left << '\n' << right << '\n';
  return 0;
}