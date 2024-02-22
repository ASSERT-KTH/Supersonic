#include <cstdio>
#include <vector>
using namespace std;
int main() {
  int w;
  scanf("%d", &w);
  vector<int> StartingPoint;
  StartingPoint.reserve(w);
  for (int i = 0; i < w; i++) {
    StartingPoint[i] = i + 1;
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int left, right;
    scanf("%d,%d", &left, &right);
    swap(StartingPoint[left - 1], StartingPoint[right - 1]);
  }
  for (int i = 0; i < w; i++) {
    printf("%d\n", StartingPoint[i]);
  }
  return 0;
}