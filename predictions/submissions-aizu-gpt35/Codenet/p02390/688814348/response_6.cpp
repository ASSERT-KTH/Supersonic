#include <iostream>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int S;
  cin >> S;
  int hours = S / 3600;
  int minutes = (S % 3600) / 60;
  int seconds = (S % 3600) % 60;
  printf("%d:%02d:%02d\n", hours, minutes, seconds);
  return 0;
}