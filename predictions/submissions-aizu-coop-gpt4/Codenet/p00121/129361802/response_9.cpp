#include <algorithm>
#include <bitset>
#include <functional>
#include <unordered_set>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

int ddd[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
unordered_set<int> vis;
queue<int> states;
int bfs(int start) {
  int goal = 1234567;
  int kkk[4] = {-1, 1, -4, 4};
  vis.clear();
  while (!states.empty()) states.pop();
  states.push(start);
  vis.insert(start);
  int steps = 0;
  while (!states.empty()) {
    int size = states.size();
    for (int i = 0; i < size; i++) {
      int curr = states.front(); states.pop();
      if (curr == goal) return steps;
      int zeroPos = to_string(curr).find('0');
      for (int j = 0; j < 4; j++) {
        int nextZeroPos = zeroPos + kkk[j];
        if (nextZeroPos < 0 || nextZeroPos > 7 || (zeroPos == 3 && nextZeroPos == 4) || (zeroPos == 4 && nextZeroPos == 3)) continue;
        int next = curr + (curr / ddd[zeroPos] % 10 - curr / ddd[nextZeroPos] % 10) * (ddd[zeroPos] - ddd[nextZeroPos]);
        if (!vis.count(next)) {
          states.push(next);
          vis.insert(next);
        }
      }
    }
    steps++;
  }
  return -1;
}

int main() {
  std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
  char bj[8];
  while (scanf("%c", &bj[0]) != EOF) {
    scanf("%*c");
    for (int i = 1; i <= 6; i++) {
      scanf("%c%*c", &bj[i]);
    }
    scanf("%c", &bj[7]);
    int start = 0;
    for (int i = 0; i < 8; i++) {
      start = start * 10 + (bj[i] - '0');
    }
    int result = bfs(start);
    printf("%d\n", result);
    while (getchar() != '\n');
  }
  return 0;
}