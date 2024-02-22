#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#define N 3

typedef unsigned long long ull;

int main() {
    int D[256];
    for (int i = 'A'; i <= 'Z'; i++)
        D[i] = i - 'A';
    for (int i = 'a'; i <= 'z'; i++)
        D[i] = i - 'a' + 26;
    for (int i = '0'; i <= '9'; i++)
        D[i] = i - '0' + 52;
    D['+'] = 62, D['/'] = 63;

    int w, h, p;
    while (std::cin >> w >> h >> p, w) {
        std::vector<std::vector<bool>> image(h, std::vector<bool>(w));
        std::vector<std::vector<bool>> pattern(p, std::vector<bool>(p));

        std::string s;
        for (int i = 0; i < h; i++) {
            std::cin >> s;
            for (int j = 0; j < s.size(); j++) {
                int t = D[s[j]];
                int a = 6;
                while (a--) {
                    image[i][j * 6 + a] = t % 2;
                    t /= 2;
                }
            }
        }
        for (int i = 0; i < p; i++) {
            std::cin >> s;
            for (int j = 0; j < s.size(); j++) {
                int t = D[s[j]];
                int a = 6;
                while (a--) {
                    pattern[i][j * 6 + a] = t % 2;
                    t /= 2;
                }
            }
        }

        int ans = 0;
        std::unordered_set<ull> used;
        std::vector<ull> roll(h, 0);
        for (int i = 0; i < p; i++) {
            ull b = 0, g = 1;
            for (int j = 0; j < p; j++) {
                b = b * N + pattern[i][j];
                g *= N;
            }
            roll[0] = b;
            for (int j = p; j < w; j++) {
                b = b * N + pattern[i][j] - pattern[i][j - p] * g;
                roll[j - p + 1] = b;
            }
        }

        std::unordered_set<ull> patterns;
        for (int r = 0; r < 4; r++) {
            for (int i = 0; i < p; i++) {
                ull b = 0, g = 1, n = 1;
                for (int j = 0; j < p; j++) {
                    n *= N;
                }
                for (int j = 0; j < p; j++) {
                    b = b * n + roll[i][j];
                    g *= n;
                }
                patterns.insert(b);
                for (int j = p; j < h; j++) {
                    b = b * n + roll[i][j] - roll[i - p][j] * g;
                    patterns.insert(b);
                }
            }
            std::vector<std::vector<bool>> newPattern(p, std::vector<bool>(p));
            for (int i = 0; i < p; i++) {
                for (int j = 0; j < p; j++) {
                    newPattern[i][j] = pattern[j][p - i - 1];
                }
            }
            pattern = newPattern;
        }

        for (int i = 0; i < h - p + 1; i++) {
            for (int j = 0; j < w - p + 1; j++) {
                ull b = 0, g = 1, n = 1;
                for (int k = 0; k < p; k++) {
                    n *= N;
                }
                for (int k = 0; k < p; k++) {
                    b = b * n + image[i + k][j];
                    g *= n;
                }
                if (patterns.find(b) != patterns.end()) {
                    ans++;
                }
                for (int k = 1; k < h - p + 1; k++) {
                    b = b * n + image[i + k + p - 1][j] - image[i + k - 1][j] * g;
                    if (patterns.find(b) != patterns.end()) {
                        ans++;
                    }
                }
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}