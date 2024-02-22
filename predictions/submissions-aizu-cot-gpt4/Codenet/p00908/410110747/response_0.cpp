#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define dx {-1, 0, 1, 0}
#define dy {0, 1, 0, -1}
#define dx2 {-1, 0, 2, 1}
#define dy2 {0, 2, 1, -1}
#define MAX 999999

using namespace std;

struct aa {
  int x;
  int y;
  int turn;
};

struct bb {
  int kx;
  int ky;
  int opway;
  int turn;
};

class Compare {
public:
  bool operator()(const bb &l, const bb &r) { return l.turn > r.turn; }
};

int memo2[60][60][4];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(memo2, MAX, sizeof(memo2));

  while (scanf("%d %d", &H, &W) != EOF) {
    if (!H && !W)
      break;

    vector<vector<int>> field(H + 2, vector<int>(W + 2, true));
    priority_queue<bb, vector<bb>, Compare> que;

    int kx = 99, ky = 99;
    int ox[2];
    int oy[2];
    int num = 0;
    string st;
    for (int i = 0; i < H; ++i) {
      cin >> st;
      for (int j = 0; j < W; ++j) {
        if (st[j] == 'X') {
          kx = min(kx, j + 1);
          ky = min(ky, i + 1);
          field[i + 1][j + 1] = false;
        } else if (st[j] == 'o') {
          field[i + 1][j + 1] = false;
        } else if (st[j] == '.') {
          field[i + 1][j + 1] = false;
          ox[num] = j + 1;
          oy[num] = i + 1;
          num++;
        }
      }
    }

    if (kx == 1 && ky == 1) {
      cout << 0 << '\n';
      continue;
    }

    // Remaining code

    printf("%d\n", ans);
  }
  return 0;
}