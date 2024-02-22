#include <iostream>
#include <bitset>
using namespace std;

int main() {
  bitset<30> data;
  int n;
  for (int i = 0; i < 28; i++) {
    scanf("%d", &n);
    data.set(n - 1);
  }
  for (int i = 0; i < 30; i++) {
    if (!data[i])
      printf("%d\n", i + 1);
  }
}