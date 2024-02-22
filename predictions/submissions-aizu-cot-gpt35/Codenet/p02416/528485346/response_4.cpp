#include <cstdio>
#include <cstring>

int main() {
  char num[1000];
  while (1) {
    scanf("%s", num);
    if (num[0] == '0')
      break;
    int sum = 0;
    int length = strlen(num);
    for (int i = 0; i < length; i++) {
      sum += num[i] - '0';
    }
    puts(std::to_string(sum).c_str());
  }
  return 0;
}