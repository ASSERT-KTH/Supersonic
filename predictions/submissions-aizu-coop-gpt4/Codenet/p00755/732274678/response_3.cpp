// Convert calc() to an iterative function
void calc(int y, int x) {
  stack<C> s;
  s.push(make_pair(y, x));

  while (!s.empty()) {
    C now = s.top();
    s.pop();
    int y = now.first, x = now.second;

    if (y < 0 || x < 0 || x >= w || y >= h || temp[y][x] != Col)
      continue;

    tres++;
    temp[y][x] = 0;

    for (int r = 0; r < 4; r++)
      s.push(make_pair(y + dy[r], x + dx[r]));
  }
}

// Use a deque instead of a queue in on()
deque<C> Q;

// Use a one-dimensional boolean array
bool used[64];
memset(used, false, sizeof(used));