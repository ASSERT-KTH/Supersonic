#include <iostream>
#include <string>
using namespace std;
#define MAX 100000
#define INF 1000000000
struct edge {
  int s, t, d;
};
edge edges[MAX];
char ans[MAX * 12]; // Assuming maximum length of each number is 12
int d[MAX];

char* itostr(int n) {
  static char buf[12]; // Maximum length of each number is 12
  int i = 10;
  buf[11] = '\0';
  if (n == 0) {
    buf[i--] = '0';
  } else {
    while (n > 0) {
      buf[i--] = '0' + n % 10;
      n /= 10;
    }
  }
  return &buf[i+1];
}

int BellmanFord(int startVertex, int vNum, int eNum) {
  fill(d, d + MAX, INF);
  d[startVertex] = 0;
  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      edge e = edges[j];
      if (d[e.s] != INF && d[e.t] > d[e.s] + e.d) {
        d[e.t] = d[e.s] + e.d;
        update = true;
        if (i == vNum - 1) {
          cout << "NEGATIVE CYCLE" << endl;
          return -1;
        }
      }
    }
    if (!update)
      break;
  }
  int idx = startVertex * 12;
  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      ans[idx++] = ' ';
    if (d[i] == INF) {
      ans[idx++] = 'I';
      ans[idx++] = 'N';
      ans[idx++] = 'F';
    } else {
      char* num = itostr(d[i]);
      int len = 0;
      while (num[len] != '\0') {
        ans[idx++] = num[len++];
      }
    }
  }
  ans[idx++] = '\0';
  return 0;
}

int main() {
  int vNum, eNum;
  cin >> vNum >> eNum;
  int s, t, w;
  for (int i = 0; i < eNum; ++i) {
    cin >> s >> t >> w;
    edges[i] = {s, t, w};
  }
  for (int i = 0; i < vNum; ++i) {
    if (BellmanFord(i, vNum, eNum) == -1) {
      return 0;
    }
    cout << ans + i * 12 << endl;
  }
}