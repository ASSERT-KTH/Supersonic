#include <iostream>
#include <vector>
#include <unordered_set>
#define N 3
using namespace std;

typedef unsigned long long ull;

void ppp(vector<vector<bool>>& im, vector<vector<bool>>& pa, int p, int& ans, unordered_set<ull>& used) {
    ull a = 0;
    ull roll[1001] = {};
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            a = a * N + pa[i][j];
        }
    }
    if (used.find(a) != used.end()) {
        return;
    }
    used.insert(a);
    int h = im.size();
    int w = im[0].size();
    for (int j = 0; j < h; j++) {
        ull b = 0;
        ull g = 1;
        for (int i = 0; i < p; i++) {
            b = b * N + im[j][i];
            g *= N;
        }
        roll[p - 1] = b;
        for (int i = p; i < w; i++) {
            b = b * N + im[j][i] - im[j][i - p] * g;
            roll[i] = b;
        }
    }
    int h_roll = h - p + 1;
    int w_roll = w - p + 1;
    ull g = 1;
    for (int i = 0; i < p; i++) {
        g *= N;
    }
    for (int j = p - 1; j < w; j++) {
        ull b = 0;
        for (int i = 0; i < p; i++) {
            b = b * g + roll[i * w_roll + j];
        }
        if (b == a) {
            ans++;
        }
        for (int i = p; i < h; i++) {
            b = b * g + roll[i * w_roll + j] - roll[(i - p) * w_roll + j] * g;
            if (b == a) {
                ans++;
            }
        }
    }
}

void ch(vector<vector<bool>>& pa, int p) {
    int n = p / 2;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            swap(pa[i][j], pa[i][p - j - 1]);
        }
    }
}

void ch1(vector<vector<bool>>& pa, int p) {
    int n = p / 2;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            swap(pa[i][j], pa[i][p - j - 1]);
        }
    }
}

int main() {
    int D[256];
    for (int i = 'A'; i <= 'Z'; i++) {
        D[i] = i - 'A';
    }
    for (int i = 'a'; i <= 'z'; i++) {
        D[i] = i - 'a' + 26;
    }
    for (int i = '0'; i <= '9'; i++) {
        D[i] = i - '0' + 52;
    }
    D['+'] = 62;
    D['/'] = 63;
    int w, h, p;
    while (cin >> w >> h >> p, w) {
        vector<vector<bool>> im(h, vector<bool>(w));
        vector<vector<bool>> pa(p, vector<bool>(p));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char c;
                cin >> c;
                int t = D[c];
                for (int a = 5; a >= 0; a--) {
                    im[i][j * 6 + a] = t % 2;
                    t /= 2;
                }
            }
        }
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                char c;
                cin >> c;
                int t = D[c];
                for (int a = 5; a >= 0; a--) {
                    pa[i][j * 6 + a] = t % 2;
                    t /= 2;
                }
            }
        }
        int ans = 0;
        unordered_set<ull> used;
        for (int i = 0; i < 4; i++) {
            ppp(im, pa, p, ans, used);
            ch1(pa, p);
            ppp(im, pa, p, ans, used);
            ch1(pa, p);
            ch(pa, p);
        }
        cout << ans << endl;
    }
    return 0;
}