#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> boss, height;

inline int get_boss(int id) {
    return boss[id] == id ? id : boss[id] = get_boss(boss[id]);
}

inline bool is_same(int x, int y) {
    return get_boss(x) == get_boss(y);
}

inline void unite(int x, int y) {
    int boss_x = get_boss(x);
    int boss_y = get_boss(y);

    if (boss_x == boss_y) return;

    if (height[x] > height[y]) {
        boss[boss_y] = boss_x;
    } else if (height[x] < height[y]) {
        boss[boss_x] = boss_y;
    } else {
        boss[boss_y] = boss_x;
        height[x]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q, command, x, y;
    cin >> N >> Q;

    boss.resize(N);
    height.resize(N);
    
    for (int i = 0; i < N; i++) {
        boss[i] = i;
        height[i] = 1;
    }

    for (int i = 0; i < Q; i++) {
        cin >> command >> x >> y;
        if (command == 0) {
            unite(x, y);
        } else {
            cout << (is_same(x, y) ? 1 : 0) << "\n";
        }
    }

    return 0;
}