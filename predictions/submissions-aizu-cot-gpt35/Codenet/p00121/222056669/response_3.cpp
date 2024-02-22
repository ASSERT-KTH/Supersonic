#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_STATES = 1000000;
const int MAX_DIGITS = 8;
const int TARGET = 1234567;
const int MOVES[4] = {-1, 1, -4, 4};

bool vis[MAX_STATES];
int d[MAX_STATES];

int bfs(int start) {
  queue<int> q;
  q.push(start);
  vis[start] = true;
  d[start] = 0;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    if (curr == TARGET) {
      return d[curr];
    }

    int zeroPos = -1;
    for (int i = 0; i < MAX_DIGITS; i++) {
      if (curr % 10 == 0) {
        zeroPos = i;
        break;
      }
      curr /= 10;
    }

    for (int move : MOVES) {
      int newPos = zeroPos + move;
      if (newPos >= 0 && newPos < MAX_DIGITS && !(zeroPos == 3 && newPos == 4) && !(zeroPos == 4 && newPos == 3)) {
        int newNum = curr;
        int a = (curr / (int)pow(10, zeroPos)) % 10;
        int b = (curr / (int)pow(10, newPos)) % 10;
        newNum += (b - a) * (int)pow(10, zeroPos) + (a - b) * (int)pow(10, newPos);
        if (!vis[newNum]) {
          q.push(newNum);
          vis[newNum] = true;
          d[newNum] = d[curr] + 1;
        }
      }
    }
  }

  return -1;
}

int main() {
  char bj[MAX_DIGITS + 1];

  while (scanf("%s", bj) != EOF) {
    memset(vis, false, sizeof(vis));
    int start = atoi(bj);
    int steps = bfs(start);
    printf("%d\n", steps);
  }

  return 0;
}