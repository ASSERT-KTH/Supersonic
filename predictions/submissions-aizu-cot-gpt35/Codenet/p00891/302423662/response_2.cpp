#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#define N 3

typedef uint64_t ull;

bool im[1001][1001], pa[110][110];

void ppp(const int p, std::unordered_set<ull>& used, int& ans) {
    ull a = 0;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            a = a * N + pa[i][j];
        }
    }
    if (used.count(a) > 0) {
        return;
    }
    used.insert(a);

    int h = p;
    int w = p;

    ull roll[1001][1001] = {};

    for (int i = 0; i < h; i++) {
        ull b = 0, g = 1;
        for (int j = 0; j < p; j++) {
            b = b * N + im[i][j];
            g *= N;
        }
        roll[i][p - 1] = b;
        for (int j = p; j < w; j++) {
            b = b * N + im[i][j] - im[i][j - p] * g;
            roll[i][j] = b;
        }
    }

    for (int j = p - 1; j < w; j++) {
        ull b = 0, g = 1, n = 1;
        for (int i = 0; i < p; i++) {
            n *= N;
        }
        for (int i = 0; i < p; i++) {
            b = b * n + roll[i][j];
            g *= n;
        }
        if (b == a) {
            ans++;
        }
        for (int i = p; i < h; i++) {
            b = b * n + roll[i][j] - roll[i - p][j] * g;
            if (b == a) {
                ans++;
            }
        }
    }
}

void ch(const int p) {
    bool npa[110][110];
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            npa[i][j] = pa[j][p - i - 1];
        }
    }
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            pa[i][j] = npa[i][j];
        }
    }
}

void ch1(const int p) {
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p / 2; j++) {
            std::swap(pa[i][j], pa[i][p - j - 1]);
        }
    }
}

int main() {
    std::unordered_map<char, int> D;
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
    while (std::cin >> w >> h >> p && w) {
        std::string s;
        std::unordered_set<ull> used;
        for (int i = 0; i < h; i++) {
            std::cin >> s;
            for (int j = 0; j < p; j++) {
                std::bitset<6> bits(D[s.substr(j * 6, 6)[0]]);
                for (int k = 0; k < 6; k++) {
                    im[i][j * 6 + k] = bits[5 - k];
                }
            }
        }
        for (int i = 0; i < p; i++) {
            std::cin >> s;
            for (int j = 0; j < p; j++) {
                std::bitset<6> bits(D[s.substr(j * 6, 6)[0]]);
                for (int k = 0; k < 6; k++) {
                    pa[i][j * 6 + k] = bits[5 - k];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 2; i++) {
            ppp(p, used, ans);
            ch1(p);
            ppp(p, used, ans);
            ch1(p);
            ch(p);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}