#include <cstdio>
#include <cstring>

const int MAX_LENGTH = 1000005;

int main() {
  char x[MAX_LENGTH];
  scanf("%s", x);

  int leng = strlen(x);
  int maxi = 0;
  int count = 0;
  int counts[3] = {0};  // counts[0] for 'J', counts[1] for 'O', counts[2] for 'I'

  for (int a = 0; a < leng; a++) {
    if (x[a] == 'J') {
      counts[0]++;
    } else if (x[a] == 'O') {
      counts[1]++;
    } else if (x[a] == 'I') {
      counts[2]++;
    }

    // Check if a valid "JOI" pattern is found
    if (counts[0] >= counts[1] && counts[1] <= counts[2]) {
      count = counts[1];
      maxi = (count > maxi) ? count : maxi;
    }
  }

  printf("%d\n", maxi);
  return 0;
}