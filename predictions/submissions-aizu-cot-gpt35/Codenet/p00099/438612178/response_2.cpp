#include <cstdio>
#include <iostream>
using namespace std;

const int MAX = 1000001;
int S[MAX];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int maxScore = 0;
  int maxNumber = 0;

  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);

    S[a] += b;
    if (S[a] > maxScore || (S[a] == maxScore && a < maxNumber)) {
      maxScore = S[a];
      maxNumber = a;
    }

    cout << maxNumber << " " << maxScore << endl;
  }

  return 0;
}