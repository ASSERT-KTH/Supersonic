#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  int w;
  cin >> w;

  int n;
  cin >> n;

  int StartingPoint[w];
  for (int i = 0; i < w; i++) {
    StartingPoint[i] = i + 1;
  }

  int Left[n];
  int Right[n];
  for (int i = 0; i < n; i++) {
    cin >> Left[i];
    char Dummy;
    cin >> Dummy;
    cin >> Right[i];
  }

  int Result[w];
  for (int i = 0; i < w; i++) {
    Result[i] = StartingPoint[i];
  }

  for (int i = 0; i < n; i++) {
    int leftIndex = Left[i] - 1;
    int rightIndex = Right[i] - 1;
    Result[leftIndex] = StartingPoint[rightIndex];
    Result[rightIndex] = StartingPoint[leftIndex];
  }

  for (int i = 0; i < w; i++) {
    printf("%d\n", Result[i]);
  }

  return 0;
}