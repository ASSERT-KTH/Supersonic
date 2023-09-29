#include <iostream>
using namespace std;

int main() {
  int S;
  scanf("%d", &S);
  printf("%d:%02d:%02d\n", S/3600, (S%3600)/60, (S%60));
  return 0;
}