#include <iostream>
#include <unordered_set>
#include <queue>
#include <array>
using namespace std;

unordered_set<int> visited;
queue<array<int, 3>> q; // 0: state, 1: zero index, 2: steps

int bfs(int start, int zeroIndex) {
    visited.clear();
    while(!q.empty()) q.pop();
    q.push({start, zeroIndex, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        if (curr[0] == 1234567) return curr[2];
        array<int, 4> offset = {-1, 1, -4, 4};
        for (int i = 0; i < 4; i++) {
            int nextZeroIndex = curr[1] + offset[i];
            if ((curr[1] == 3 && nextZeroIndex == 4) || (curr[1] == 4 && nextZeroIndex == 3)) continue;
            if (nextZeroIndex >= 0 && nextZeroIndex <= 7) {
                int next = curr[0] + (curr[0] / (int)pow(10, 7 - curr[1]) % 10 - curr[0] / (int)pow(10, 7 - nextZeroIndex) % 10) * (int)pow(10, 7 - nextZeroIndex);
                if (visited.find(next) == visited.end()) {
                    q.push({next, nextZeroIndex, curr[2] + 1});
                    visited.insert(next);
                }
            }
        }
    }
    return -1;
}

int main() {
    char c;
    while (1) {
        int start = 0, zeroIndex = 0;
        for (int i = 0; i < 8; i++) {
            cin >> c;
            if (c == '0') zeroIndex = i;
            start = start * 10 + c - '0';
        }
        cin.ignore(); // read '\n'
        int steps = bfs(start, zeroIndex);
        if (steps == -1) cout << "-1\n";
        else cout << steps << "\n";
        if (cin.peek() == EOF) break;
    }
    return 0;
}