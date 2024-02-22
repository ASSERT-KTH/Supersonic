#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  char input[20];
  fgets(input, sizeof(input), stdin);
  int S = atoi(input);

  int hours = S / 3600;
  int minutes = (S % 3600) / 60;
  int seconds = S % 60;

  printf("%02d:%02d:%02d\n", hours, minutes, seconds);

  return 0;
}