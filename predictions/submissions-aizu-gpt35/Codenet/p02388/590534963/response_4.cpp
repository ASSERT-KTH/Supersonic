#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); // disable synchronization between C and C++ standard streams
  cin.tie(NULL); // untie cin from cout
  int n;
  scanf("%d", &n); // use scanf instead of cin for faster input
  printf("%d\n", n * n * n); // use printf instead of cout for faster output
  return 0;
}