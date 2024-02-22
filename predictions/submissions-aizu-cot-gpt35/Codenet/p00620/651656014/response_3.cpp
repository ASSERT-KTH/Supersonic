#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  while (true) {
    cin >> n;
    if (n == 0) break;

    vector<int> starts;
    vector<int> used(n * n, false);
    int sum = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int a;
        cin >> a;
        sum += a;
        if (a < 0) {
          a *= -1;
          used[i * n + j] = true;
          starts.emplace_back(a);
        }
      }
    }

    if (sum != 0) {
      cout << "NO" << endl;
      continue;
    }

    bool ret = false;
    if (starts.size() == 1) {
      ret = true;
    } else {
      sort(starts.rbegin(), starts.rend());
      int cur = 0;
      int x = starts[cur] % n;
      int y = starts[cur] / n;

      while (true) {
        if (starts[cur] == 0) {
          cur++;
          if (cur >= starts.size()) {
            ret = true;
            break;
          }
          x = starts[cur] % n;
          y = starts[cur] / n;
        } else if (starts[cur] < 0) {
          ret = false;
          break;
        }

        bool found = false;
        for (int i = 0; i < 4; i++) {
          int nx = x + dx[i];
          int ny = y + dy[i];
          if (0 <= nx && nx < n && 0 <= ny && ny < n && !used[ny * n + nx]) {
            used[ny * n + nx] = true;
            starts[cur] += mat[ny * n + nx];
            x = nx;
            y = ny;
            found = true;
            break;
          }
        }

        if (!found) {
          starts[cur] *= -1;
          cur--;
          if (cur < 0) {
            ret = false;
            break;
          }
          x = starts[cur] % n;
          y = starts[cur] / n;
        }
      }
    }

    cout << (ret ? "YES" : "NO") << endl;
  }

  return 0;
}