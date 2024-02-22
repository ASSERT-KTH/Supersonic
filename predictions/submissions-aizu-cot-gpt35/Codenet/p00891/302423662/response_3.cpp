#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

#define N 3

int main() {
  map<char, int> D;
  for (int i = 'A'; i <= 'Z'; i++)
    D[i] = i - 'A';
  for (int i = 'a'; i <= 'z'; i++)
    D[i] = i - 'a' + 26;
  for (int i = '0'; i <= '9'; i++)
    D[i] = i - '0' + 52;
  D['+'] = 62, D['/'] = 63;

  int w, h, p;
  while (cin >> w >> h >> p, w) {
    string s;

    vector<vector<bool>> im(h, vector<bool>(w * 6));
    for (int i = 0; i < h; i++) {
      cin >> s;
      for (int j = 0; j < s.size(); j++) {
        int t = D[s[j]];
        for (int a = 0; a < 6; a++)
          im[i][j * 6 + a] = (t >> (5 - a)) & 1;
      }
    }

    unordered_set<unsigned long long> used;
    int ans = 0;
    for (int r = 0; r < 4; r++) {
      vector<vector<unsigned long long>> roll(h, vector<unsigned long long>(w));
      for (int j = 0; j < h; j++) {
        unsigned long long b = 0, g = 1;
        for (int i = 0; i < p; i++)
          b = b * N + im[j][i], g *= N;
        roll[j][p - 1] = b;
        for (int i = p; i < w; i++) {
          b = b * N + im[j][i] - im[j][i - p] * g;
          roll[j][i] = b;
        }
      }

      for (int j = p - 1; j < w; j++) {
        unsigned long long b = 0, g = 1, n = 1;
        for (int i = 0; i < p; i++)
          n *= N;
        for (int i = 0; i < p; i++)
          b = b * n + roll[i][j], g *= n;
        if (used.count(b))
          ans++;
        for (int i = p; i < h; i++) {
          b = b * n + roll[i][j] - roll[i - p][j] * g;
          if (used.count(b))
            ans++;
        }
      }

      // Transform pattern
      for (int i = 0; i < p; i++) {
        for (int j = 0; j < p / 2; j++) {
          swap(im[i][j], im[i][p - j - 1]);
          swap(im[j][i], im[p - j - 1][i]);
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}