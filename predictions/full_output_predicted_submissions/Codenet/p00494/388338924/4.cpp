#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
char x[1000005];
int a = 0, b = 0, c = 0, d = 0, e, f, i, j, k, maxi = 0;
int main() {
  fill(x, x + 1000005, 'A');
  scanf("%s", x);
  int leng = strlen(x);
  while (1) {
    if (a == leng) {
      break;
    }
    if (x[a] != 'J') {
      a++;
    } else {
      while (1) {
        if (x[a] == 'J') {
          b++;
          a++;
        } else {
          break;
        }
      }
      while (1) {
        if (x[a] == 'O') {
          c++;
          a++;
        } else {
          break;
        }
      }
      while (1) {
        if (x[a] == 'I') {
          d++;
          a++;
        } else {
          break;
        }
      }
      if (b >= c && c <= d) {
        maxi = max(maxi, c);
      }
      b