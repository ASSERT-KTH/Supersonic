#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::vector<std::vector<int>> M(8, std::vector<int>(8));
        for (int j = 0; j < 8; j++) {
            std::string s;
            std::cin >> s;
            for (int k = 0; k < 8; k++) {
                M[j][k] = s[k] - '0';
            }
        }

        int x, y;
        std::cin >> x >> y;
        x--, y--;

        std::queue<std::pair<int, int>> q;
        q.push({y, x});

        while (!q.empty()) {
            auto [cy, cx] = q.front();
            q.pop();

            if (M[cy][cx] == 0) {
                continue;
            }

            M[cy][cx] = 0;

            for (int i = 0; i < 4; i++) {
                for (int j = 1; j <= 3; j++) {
                    int ny = cy + j * (i == 1) - j * (i == 3);
                    int nx = cx + j * (i == 0) - j * (i == 2);

                    if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && M[ny][nx] == 1) {
                        q.push({ny, nx});
                    }
                }
            }
        }

        std::cout << "Data " << i + 1 << ":" << std::endl;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                std::cout << M[j][k];
            }
            std::cout << std::endl;
        }
    }

    return 0;
}