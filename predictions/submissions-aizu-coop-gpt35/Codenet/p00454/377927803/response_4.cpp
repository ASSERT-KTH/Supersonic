#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Component {
    int minX, maxX, minY, maxY;
};

int compress(std::vector<Component>& components, int* x1, int* x2, int w) {
    std::vector<int> xs;
    int n = components.size();

    for (int i = 0; i < n; ++i) {
        for (int d = -1; d <= 1; ++d) {
            int tx1 = x1[i] + d, tx2 = x2[i] + d;
            if (0 <= tx1 && tx1 <= w)
                xs.push_back(tx1);
            if (0 <= tx2 && tx2 <= w)
                xs.push_back(tx2);
        }
    }

    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());

    for (int i = 0; i < n; ++i) {
        x1[i] = std::lower_bound(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = std::lower_bound(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }

    return xs.size();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int w, h;
    while (std::cin >> w >> h, w) {
        int n;
        std::cin >> n;

        std::vector<Component> components(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> components[i].minX >> components[i].minY >> components[i].maxX >> components[i].maxY;
        }

        w = compress(components, x1, x2, w);
        h = compress(components, y1, y2, h);

        std::vector<bool> fld(w * h, false);

        for (const auto& component : components) {
            for (int y = component.minY; y <= component.maxY - 1; ++y) {
                for (int x = component.minX; x <= component.maxX - 1; ++x) {
                    fld[y * w + x] = true;
                }
            }
        }

        int ans = 0;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        for (int y = 0; y < h - 1; ++y) {
            for (int x = 0; x < w - 1; ++x) {
                if (fld[y * w + x])
                    continue;
                ans++;
                std::queue<std::pair<int, int>> q;
                q.push(std::make_pair(y, x));
                while (!q.empty()) {
                    std::pair<int, int> p = q.front();
                    q.pop();
                    for (int i = 0; i < 4; ++i) {
                        int ny = p.first + dy[i], nx = p.second + dx[i];
                        if (ny < 0 || ny >= h - 1 || nx < 0 || nx >= w - 1 || fld[ny * w + nx])
                            continue;
                        fld[ny * w + nx] = true;
                        q.push(std::make_pair(ny, nx));
                    }
                }
            }
        }
        std::cout << ans << std::endl;
    }

    return 0;
}