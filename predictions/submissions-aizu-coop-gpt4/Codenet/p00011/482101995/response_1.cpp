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

  int w, n;
  scanf("%d %d", &w, &n);

  vector<int> StartingPoint(w);
  
  for (int i = 0; i < w; i++) {
    StartingPoint[i] = i + 1;
    if (i < n) {
      THorizonalLine HorizonalLine;
      char Dummy;
      scanf("%d %c %d", &HorizonalLine.Left, &Dummy, &HorizonalLine.Right);
      swap(StartingPoint[HorizonalLine.Left - 1], StartingPoint[HorizonalLine.Right - 1]);
    }
  }

  for (int i = 0; i < w; i++) {
    printf("%d\n", StartingPoint[i]);
  }
  
  return 0;
}