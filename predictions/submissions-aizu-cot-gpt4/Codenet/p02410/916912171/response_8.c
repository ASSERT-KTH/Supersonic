#include <stdio.h>
#define gc getchar_unlocked
#define pc putchar_unlocked

void scanint(int &x){
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}
}

void printint(int n){
    if(n == 0) {pc('0'); pc('\n'); return;}
    char buf[11]; buf[10] = '\n';
    int i = 9;
    while(n) {buf[i--] = n % 10 + '0'; n /= 10;}
    while(buf[i] != '\n') pc(buf[++i]);
}

int main() {
  int inact[100][100];
  int act[100];
  int ans[100];
  int row, col;
  int i, j;
  scanint(row); scanint(col);
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      scanint(inact[i][j]);
    }
    ans[i] = 0;
  }
  for (i = 0; i < col; i++) {
    scanint(act[i]);
  }
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      int k = act[j];
      while(k--) ans[i] += inact[i][j];
    }
  }
  for (i = 0; i < row; i++) {
    printint(ans[i]);
  }
  return 0;
}