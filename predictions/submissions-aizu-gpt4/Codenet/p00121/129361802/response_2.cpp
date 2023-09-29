#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct State {
    string s;
    int zero_pos;
    int steps;
    State(string s, int z, int steps) : s(s), zero_pos(z), steps(steps) {}
};

int bfs(string& start) {
    unordered_set<string> visited;
    queue<State> q;
    const vector<int> dir = {-1, 1, -4, 4};
    string target = "1234567";

    q.push(State(start, start.find('0'), 0));
    visited.insert(start);

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (curr.s == target) {
            return curr.steps;
        }

        for (int d: dir) {
            int new_zero_pos = curr.zero_pos + d;
            if (new_zero_pos < 0 || new_zero_pos > 7 ||
                (curr.zero_pos == 3 && new_zero_pos == 4) ||
                (curr.zero_pos == 4 && new_zero_pos == 3)) {
                continue;
            }

            string new_s = curr.s;
            swap(new_s[curr.zero_pos], new_s[new_zero_pos]);

            if (visited.find(new_s) == visited.end()) {
                visited.insert(new_s);
                q.push(State(new_s, new_zero_pos, curr.steps + 1));
            }
        }
    }

    return -1;
}

int main() {
    string s;
    while (getline(cin, s)) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        int result = bfs(s);
        cout << (result != -1 ? to_string(result) : "-1") << "\n";
    }

    return 0;
}