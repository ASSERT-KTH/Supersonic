#include <iostream>
#include <stack>
using namespace std;
int n, b[2][100100], f[2][100100];
bool v[100100];

int dfs(int s, int now, int maxi, int num) {
    stack<int> stack;
    stack.push(now);
    while (!stack.empty()) {
        now = stack.top();
        stack.pop();
        v[now] = true;
        for (int i = 0; i < 2; i++) {
            if (!v[b[i][now]]) {
                if (maxi < f[i][now]) {
                    maxi = f[i][now];
                    num = 1;
                } else if (maxi == f[i][now]) {
                    num++;
                }
                if (b[i][now] != s) {
                    stack.push(b[i][now]);
                }
            }
        }
    }
    if (maxi < f[1][s]) {
        return 1;
    } else if (maxi == f[1][s]) {
        return num + 1;
    } else {
        return num;
    }
}

int main() {
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
            v[i] = false;
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                ans = (ans * dfs(i, b[0][i], f[0][i], 1)) % 10007;
            }
        }
        cout << ans << endl;
    }
}