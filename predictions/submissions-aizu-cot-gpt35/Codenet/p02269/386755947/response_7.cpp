#include <cstdio>
using namespace std;

bool *d;
char k[128];

int c(char str[12]) {
  int ans = str[0], i = 0;
  for (i; str[i+1] != '\0'; i++) {
    ans <<= 2;
    ans += k[str[i+1]];
  }
  return ans;
}

int main() {
  k['A'] = 0;
  k['C'] = 1;
  k['G'] = 2;
  k['T'] = 3;
  int n;
  scanf("%d", &n);
  char s[7], str[12];
  
  int max_index = 0;
  while (n--) {
    scanf("%s %s", s, str);
    int index = c(str);
    if (index > max_index) {
      bool *new_d = new bool[index+1];
      for (int i = 0; i <= max_index; i++) {
        new_d[i] = d[i];
      }
      delete[] d;
      d = new_d;
      max_index = index;
    }
    if (s[0] == 'i')
      d[index] = true;
    else
      puts(index <= max_index && d[index] ? "yes" : "no");
  }

  delete[] d;
  return 0;
}