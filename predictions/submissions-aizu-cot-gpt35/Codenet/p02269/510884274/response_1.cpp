#include <cstdio>
#include <string>
#include <cmath>

const int MAX_SIZE = 244140624;
bool chk[MAX_SIZE];
int n;
std::string ins, s;

int h(const std::string& s) {
  int ret = 0;
  int size = s.size();
  for (int i = 0; i < size; ++i) {
    ret += pow(5, size - i - 1) * (
      (s[i] == 'A') ? 1 :
      (s[i] == 'C') ? 2 :
      (s[i] == 'G') ? 3 :
      (s[i] == 'T') ? 4 : 0
    );
  }
  return ret;
}

int main() {
  std::scanf("%d", &n);
  while (n--) {
    std::scanf("%s", &ins[0]);
    std::scanf("%s", &s[0]);
    if (ins[0] == 'i') {
      chk[h(s)] = true;
    } else {
      std::printf("%s\n", (chk[h(s)] ? "yes" : "no"));
    }
  }
  return 0;
}