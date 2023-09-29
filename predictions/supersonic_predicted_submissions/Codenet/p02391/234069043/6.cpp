#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main() {
  double pai = 3.14159265358;
  int a, b;
  scanf("%d %d", &a, &b);
  if (a > b)
    printf("a > b\n");
  else if (a < b)
    printf("a < b\n");
  else
    printf("a == b\n");
  return 0;
}
