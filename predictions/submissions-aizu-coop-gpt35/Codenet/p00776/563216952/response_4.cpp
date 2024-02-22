#include <iostream>
#include <bitset>

#define rep(i, a, n) for (int i = a; i < n; i++)

using namespace std;

int countPermutations(string& s) {
  int n = s.size();
  int ans = 1;

  bitset<26> d;

  rep(i, 0, n) {
    ans *= (i + 1); // Multiply ans by (i+1) to get the factorial of n
    d[s[i] - 'a'] = 1; // Set the corresponding bit for the character
  }

  rep(i, 0, n) {
    ans /= (i + 1); // Divide ans by (i+1) to get the number of permutations
    ans *= (i + 1 - d.count()); // Multiply ans by (i+1 - number of characters already present)
    d[s[i] - 'a'] = 0; // Reset the bit for the character
  }

  return ans;
}

void dfs(string& t, int now, int& count) {
  int n = t.size();

  if (now == n) {
    count++;
    return;
  }

  bitset<2> adjacent;
  adjacent[0] = (t[now] != 'a' && t[now - 1] + 1 == t[now]);
  adjacent[1] = (t[now] != 'z' && t[now + 1] - 1 == t[now]);

  if (adjacent.all() && (now == 0 || t[now - 1] != t[now + 1])) {
    dfs(t, now + 1, count);
  }

  dfs(t, now + 1, count);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;

  while (1) {
    cin >> s;

    if (s == "#")
      break;

    int count = 0;
    dfs(s, 0, count);
    int ans = countPermutations(s);

    cout << ans << endl;

    if (ans <= 10) {
      rep(i, 0, ans) {
        cout << s << endl;
        next_permutation(s.begin(), s.end());
      }
    } else {
      rep(i, 0, 5) {
        cout << s << endl;
        next_permutation(s.begin(), s.end());
      }

      reverse(s.begin(), s.end());

      rep(i, 0, 5) {
        cout << s << endl;
        next_permutation(s.begin(), s.end());
      }
    }
  }

  return 0;
}