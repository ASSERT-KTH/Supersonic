#include <cstdio>
#include <cstring>

inline int readInt() {
  int number = 0;
  char c = getchar_unlocked();
  while(c<'0') c=getchar_unlocked();
  while(c>='0' && c<='9') {
    number = number * 10 + c - '0';
    c=getchar_unlocked();
  }
  return number;
}

inline void writeInt(int number) {
  if(number==0) {
    putchar_unlocked('0');
    putchar_unlocked('\n');
  }
  char numStr[21];
  int i=0;
  while(number) {
    numStr[i++] = number%10+'0';
    number=number/10;
  }
  i--;
  while(i>=0) putchar_unlocked(numStr[i--]);
  putchar_unlocked('\n');
}

int main() {
  int a, b, n, t1, t2, way[289];
  while ((a = readInt()), (b = readInt()), a || b) {
    n = readInt();
    memset(way, 0, sizeof(way));
    for (int i = 0; i < n; i++)
      t1 = readInt(), t2 = readInt(), way[t2 * 17 + t1] = -1;
    for (int i = 1; i <= a; i++) {
      if (way[17 + i] == -1)
        break;
      way[17 + i] = 1;
    }
    for (int i = 1; i <= b; i++) {
      if (way[i * 17 + 1] == -1)
        break;
      way[i * 17 + 1] = 1;
    }
    for (int i = 2; i <= b; i++) {
      for (int j = 2; j <= a; j++) {
        if (way[i * 17 + j] != -1) {
          int w = (way[i * 17 + j - 1] != -1) ? way[i * 17 + j - 1] : 0;
          int h = (way[(i - 1) * 17 + j] != -1) ? way[(i - 1) * 17 + j] : 0;
          way[i * 17 + j] = w + h;
        }
      }
    }
    writeInt(way[b * 17 + a]);
  }
  return 0;
}