  //... (unchanged code)

struct state {
  char x, y, cx[3], cy[3], Sc;
  state(char _x, char _y, char _cx[], char _cy[], char _Sc) {
    x = _x, y = _y, Sc = _Sc;
    cx[0] = _cx[0], cx[1] = _cx[1], cx[2] = _cx[2];
    cy[0] = _cy[0], cy[1] = _cy[1], cy[2] = _cy[2];
  }
  //... (unchanged code)
};

//... (unchanged code)

void BFS(char nx, char ny, char ncx[], char ncy[], char Sc) {
  int i, j, k;
  memset(bfscost, -1, sizeof(bfscost));
  bfscost[ny][nx] = 0;
  
  // Change to store pointers to pairs instead of copying them
  queue<pair<int, int>*> q;
  pair<int, int>* p = new pair<int, int>(nx, ny);
  q.push(p);
  
  //... (unchanged code)
}

//... (unchanged code)

int main() {
  int i, j, k;
  while (scanf("%d%d", &H, &W), H | W) {
    csize = wsize = 0;
    memset(DP, -1, sizeof(DP));
    rep(i, 3) cx[i] = cy[i] = 0;
    input();
    int res = INT_MAX;
    
    // Change to store pointers to states instead of copying them
    priority_queue<pair<int, state*>, vector<pair<int, state*>>,
                   greater<pair<int, state*>>>
        q;
    state* s = new state(sx, sy, cx, cy, 0);
    q.push(make_pair(0, s));
    DP[cx[0]][cy[0]][cx[1]][cy[1]][cx[2]][cy[2]][sx][sy] = 0;

    //... (unchanged code)
  }
  return 0;
}