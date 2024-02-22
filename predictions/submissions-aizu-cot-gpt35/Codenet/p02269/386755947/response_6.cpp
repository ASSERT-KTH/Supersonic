#include <cstdio>
#include <bitset>
using namespace std;

bitset<33554432> d;
int k[128];

int c(char str[12]) {
  return (k[str[0]] << 20) | (k[str[1]] << 18) | (k[str[2]] << 16) |
         (k[str[3]] << 14) | (k[str[4]] << 12) | (k[str[5]] << 10) |
         (k[str[6]] << 8) | (k[str[7]] << 6) | (k[str[8]] << 4) |
         (k[str[9]] << 2) | k[str[10]];
}

int main() {
  k['A'] = 0;
  k['C'] = 1;
  k['G'] = 2;
  k['T'] = 3;
  
  int n;
  scanf("%d", &n);
  char str[12];
  
  while (n--) {
    scanf("%s", str);
    if (str[0] == 'i')
      d.set(c(str));
    else
      puts(d.test(c(str)) ? "yes" : "no");
  }
  
  return 0;
}