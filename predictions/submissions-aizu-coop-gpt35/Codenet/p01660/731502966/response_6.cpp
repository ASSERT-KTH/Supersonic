#include <iostream>
using namespace std;

const int MAX_T = 3000;
const int MAX_M = 300;

int M, start, goal, dice[6], *N;
int path[MAX_M] = {};
int cachedPaths[MAX_M] = {};

bool isPositionValid(int p) {
  return 0 <= p && p < M;
}

int* MakePath(int from) {
  if (path[from] != 0) {
    return &path[from];
  }

  bool visit[MAX_M] = {};
  visit[from] = true;

  for (int m = 0; m < M; m++) {
    path[m] = MAX_T + 1;
  }

  path[from] = 0;

  int bestpath = MAX_T;
  int queue[MAX_M] = {};
  int front = 0, rear = 0;
  queue[rear++] = from;

  while (front < rear) {
    int current = queue[front++];
    int currentPosition = current + N[current];
    int currentPath = path[current] + 1;

    if (isPositionValid(currentPosition) && !visit[currentPosition]) {
      visit[currentPosition] = true;
      path[currentPosition] = currentPath;
      queue[rear++] = currentPosition;
      bestpath = min(bestpath, currentPath);
    }

    currentPosition = current - N[current];

    if (isPositionValid(currentPosition) && !visit[currentPosition]) {
      visit[currentPosition] = true;
      path[currentPosition] = currentPath;
      queue[rear++] = currentPosition;
      bestpath = min(bestpath, currentPath);
    }
  }

  return &path[from];
}

int main() {
  cin >> M;

  for (int r = 0; r < 6; r++) {
    cin >> dice[r];
  }

  cin >> start >> goal;
  start--, goal--;

  N = new int[M];

  for (int m = 0; m < M; m++) {
    cin >> N[m];
  }

  int* path = MakePath(start);
  int position = start;

  for (int t = 0; t < MAX_T; t++) {
    if (position == goal) {
      break;
    }

    int r;
    cin >> r;
    int d = dice[r - 1];

    int output;

    if (isPositionValid(position + d) && path[position] > path[position + N[position]]) {
      position = position + N[position];
      output = 1;
    } else if (isPositionValid(position - d) && path[position] > path[position - N[position]]) {
      position = position - N[position];
      output = -1;
    } else {
      output = 0;
    }

    cout << output << endl;
  }

  delete[] N;
  return 0;
}