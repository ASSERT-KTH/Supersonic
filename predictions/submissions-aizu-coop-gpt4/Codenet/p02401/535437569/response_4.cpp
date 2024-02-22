#include <cstdio>
using namespace std;

int read_int() {
  int num = 0;
  char c = getchar_unlocked();
  while (c < '0' || c > '9') c = getchar_unlocked();
  while (c >= '0' && c <= '9') {
    num = (num << 3) + (num << 1) + c - '0';
    c = getchar_unlocked();
  }
  return num;
}

void print_int(int num) {
  if (num == 0) {
    putchar_unlocked('0');
    putchar_unlocked('\n');
    return;
  }
  char buf[11]; 
  buf[10] = '\n';
  int i = 9;
  while (num) {
    buf[i--] = num % 10 + '0';
    num /= 10;
  }
  while (buf[i] != '\n') putchar_unlocked(buf[++i]);
}

int main() {
  int x, y;
  char z;
  while (1) {
    x = read_int();
    z = getchar_unlocked();
    y = read_int();
    switch (z) {
    case '+':
      print_int(x + y);
      break;
    case '-':
      print_int(x - y);
      break;
    case '/':
      print_int(x / y);
      break;
    case '*':
      print_int(x * y);
      break;
    case '?':
      return 0;
    default:
      break;
    }
  }
  return 0;
}