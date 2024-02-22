#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
  string x;
  x.reserve(1000005); // Reserve memory for the input string

  fill(x.begin(), x.end(), 'A');
  scanf("%s", x.data()); // Use the data() function to get the underlying character array

  int a = 0, b = 0, c = 0, d = 0, maxi = 0;
  int leng = strlen(x.c_str()); // Get the length of the input string

  while (a < leng) {
    if (x[a] != 'J') {
      a++;
    } else {
      b = c = d = 0; // Reset counters for each group of consecutive characters

      while (x[a] == 'J') {
        b++;
        a++;
      }
      while (x[a] == 'O') {
        c++;
        a++;
      }
      while (x[a] == 'I') {
        d++;
        a++;
      }
      if (b >= c && c <= d) {
        maxi = max(maxi, c);
      }
    }
  }

  printf("%d\n", maxi);
  scanf("%d", &a);
  return 0;
}