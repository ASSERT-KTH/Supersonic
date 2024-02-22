#include <iostream>
using namespace std;
int main() {
  int w;
  scanf("%d", &w);
  int n;
  scanf("%d", &n);
  int StartingPoint[1000000];
  for (int i = 0; i < w; i++) {
    StartingPoint[i] = i + 1;
  }
  int swaps[1000000][2];
  for (int i = 0; i < n; i++) {
    int left, right;
    char Dummy;
    scanf("%d %c %d", &left, &Dummy, &right);
    swaps[i][0] = left - 1;
    swaps[i][1] = right - 1;
  }
  for (int i = 0; i < n; i++) {
    swap(StartingPoint[swaps[i][0]], StartingPoint[swaps[i][1]]);
  }
  for (int i = 0; i < w; i++) {
    printf("%d\n", StartingPoint[i]);
  }
  return 0;
}