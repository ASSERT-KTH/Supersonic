#include <algorithm>
#include <bitset>
#include <functional>
#include <set>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
char puzzle[8] = {0, 1, 2, 3, 4, 5, 6, 7};
char input[8];
char visited[80000000 / 8];
#define check(x) (visited[(x) >> 3] & (1 << ((x)&7)))
#define setbit(x) (visited[(x) >> 3] |= (1 << ((x)&7)))
#define clearbit(x) (visited[(x) >> 3] &= ~(1 << ((x)&7)))
struct Point {
  int state;
  int zeroPos;
  int step;
};
int bfsSteps;
queue<Point> bfsQueue;
int found;
int divisor[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
void bfs() {
  while (!bfsQueue.empty()) {
    bfsQueue.pop();
  }
  found = 0;
  bfsSteps = 0;
  memset(visited, 0, sizeof(visited));
  int initState = atoi(input);
  setbit(initState);
  Point startPoint;
  startPoint.state = initState;
  startPoint.zeroPos = strchr(input, '0') - input;
  startPoint.step = 0;
  bfsQueue.push(startPoint);
  while (!bfsQueue.empty()) {
    Point currentPoint = bfsQueue.front();
    bfsQueue.pop();
    if (currentPoint.state == 1234567) {
      bfsSteps = currentPoint.step;
      found = 1;
      return;
    }
    Point nextPoint;
    int offset[4] = {-1, 1, -4, 4};
    for (int i = 0; i < 4; i++) {
      nextPoint.zeroPos = currentPoint.zeroPos + offset[i];
      if ((currentPoint.zeroPos == 3 && nextPoint.zeroPos == 4) || (currentPoint.zeroPos == 4 && nextPoint.zeroPos == 3)) continue;
      if (nextPoint.zeroPos >= 0 && nextPoint.zeroPos <= 7) {
        int a = currentPoint.state / divisor[currentPoint.zeroPos] % 10;
        int b = currentPoint.state / divisor[nextPoint.zeroPos] % 10;
        nextPoint.state = currentPoint.state + (b - a) * divisor[currentPoint.zeroPos] + (a - b) * divisor[nextPoint.zeroPos];
        if (!check(nextPoint.state)) {
          nextPoint.step = currentPoint.step + 1;
          setbit(nextPoint.state);
          bfsQueue.push(nextPoint);
        }
      }
    }
  }
}

int main() {
  while (1) {
    if (scanf("%c", &input[0]) == EOF) {
      return 0;
    }
    scanf("%*c");
    for (int i = 1; i <= 6; i++) {
      scanf("%c%*c", &input[i]);
    }
    scanf("%c", &input[7]);
    bfs();
    if (found) {
      printf("%d\n", bfsSteps);
    } else {
      printf("-1\n");
    }
    while (getchar() != '\n') {}
  }
  return 0;
}