#include <algorithm>
#include <unordered_set>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

const int GOAL = 1234567;
const int MAX_DIGITS = 8;
const int MAX_STATES = 1 << 16;
const int DIRECTIONS[4] = {-1, 1, -4, 4};

struct State {
  int number;
  int zeroPos;
  int steps;
};

int bfs(char* initial) {
  unordered_set<int> visited;
  queue<State> statesQueue;

  int initialNumber = 0;
  for (int i = 0; i < MAX_DIGITS; ++i) {
    initialNumber = initialNumber * 10 + (initial[i] - '0');
  }

  State initialState = {initialNumber, strchr(initial, '0') - initial, 0};
  statesQueue.push(initialState);
  visited.insert(initialNumber);

  while (!statesQueue.empty()) {
    State state = statesQueue.front();
    statesQueue.pop();

    if (state.number == GOAL) {
      return state.steps;
    }

    for (int direction : DIRECTIONS) {
      State nextState = state;
      nextState.zeroPos += direction;

      if ((state.zeroPos == 3 && nextState.zeroPos == 4) || (state.zeroPos == 4 && nextState.zeroPos == 3)) {
        continue;
      }

      if (nextState.zeroPos >= 0 && nextState.zeroPos < MAX_DIGITS) {
        int digitPos = MAX_DIGITS - 1 - nextState.zeroPos;
        int mask = 1 << digitPos;
        nextState.number = (state.number & ~mask) | ((state.number >> 1) & mask);
        if (!visited.count(nextState.number)) {
          nextState.steps++;
          statesQueue.push(nextState);
          visited.insert(nextState.number);
        }
      }
    }
  }

  return -1;
}

int main() {
  char initial[MAX_DIGITS];
  while (scanf("%c", &initial[0]) != EOF) {
    scanf("%*c");
    for (int i = 1; i < MAX_DIGITS - 1; ++i) {
      scanf("%c%*c", &initial[i]);
    }
    scanf("%c", &initial[MAX_DIGITS - 1]);

    int steps = bfs(initial);
    printf("%d\n", steps);

    while (getchar() != '\n');
  }
  
  return 0;
}