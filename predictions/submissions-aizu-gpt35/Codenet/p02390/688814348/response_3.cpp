#include <iostream>
using namespace std;
int main(void) {
  int S;
  cin >> S;
  int hours = S / 3600;
  int minutes = (S % 3600) / 60;
  int seconds = (S % 3600) % 60;
  printf("%02d:%02d:%02d\n", hours, minutes, seconds);
}