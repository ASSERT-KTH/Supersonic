//...rest of the code

int main() {
  int H, W;
  cin >> H >> W;

  // Dynamic allocation
  int*** memo2 = new int**[H+2];
  for(int i = 0; i < H+2; ++i) {
    memo2[i] = new int*[W+2];
    for(int j = 0; j < W+2; ++j)
      memo2[i][j] = new int[4];
  }

  //...rest of the code

  // Calculate fx, fy, gx, gy once and store them in variables
  int fx = fkx + dx2[fway];
  int fy = fky + dy2[fway];
  int gx = fkx + dx2[tway];
  int gy = fky + dy2[tway];

  //...rest of the code

  // Break the search loop in getdis function early when a better path is found
  for (int i = 0; i < 4; ++i) {
    const int nextx = atop.x + dx[i];
    const int nexty = atop.y + dy[i];
    if (!field[nexty][nextx]) {
      if (atop.turn + 1 < memo[nexty][nextx]) {
        memo[nexty][nextx] = atop.turn + 1;
        que.push(aa{nextx, nexty, atop.turn + 1});
        if (nextx == gx && nexty == gy) {
          ans = atop.turn + 1;
          break;
        }
      }
    }
  }

  //...rest of the code

  // Deallocate memory
  for(int i = 0; i < H+2; ++i) {
    for(int j = 0; j < W+2; ++j)
      delete [] memo2[i][j];
    delete [] memo2[i];
  }
  delete [] memo2;

  return 0;
}