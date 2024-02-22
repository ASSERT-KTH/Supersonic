#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m, n) {
    vector<string> words(n);
    vector<int> wordLengths(n);
    vector<int> hashPrefixes(m + 1);
    vector<vector<bool>> vis(250, vector<bool>(1 << n));
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      cin >> words[i];
      wordLengths[i] = words[i].size();
    }

    hashPrefixes[0] = 1;
    for (int i = 0; i < m; ++i) {
      hashPrefixes[i + 1] = hashPrefixes[i] * 31;
    }

    string text;
    for (int i = 0; i < m; ++i) {
      string word;
      cin >> word;
      text.append(word);
    }

    for (int j = 0; j < text.size(); ++j) {
      int cur = j % 250;
      fill(vis[cur].begin(), vis[cur].end(), false);
      vis[cur][0] = true;

      for (int i = 0; i < (1 << n); ++i) {
        if (!vis[cur][i]) {
          continue;
        }

        for (int k = 0; k < n; ++k) {
          if ((~i & (1 << k)) && wordLengths[k] + j <= text.size()) {
            int len = wordLengths[k];
            int start = j;
            int end = j + len;
            int hashPrefix = hashPrefixes[len];
            int hashText = 0;

            for (int p = start; p < end; ++p) {
              hashText = hashText * 31 + text[p];
            }

            if (hashText == hashPrefix * words[k][0]) {
              vis[(j + len) % 250][i | (1 << k)] = true;
            }
          }
        }
      }

      ans += vis[cur][(1 << n) - 1];
    }
    
    cout << ans << endl;
  }

  return 0;
}