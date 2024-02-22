#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
#include <boost/functional/hash.hpp>
using namespace std;

struct State {
    vector<int> puzzle;
    int zero_pos;
    int g;
    int h;
    bool operator<(const State& rhs) const { return g + h > rhs.g + rhs.h; }
};

struct StateHasher {
    size_t operator()(const State& s) const {
        size_t seed = 0;
        boost::hash_combine(seed, boost::hash_range(s.puzzle.begin(), s.puzzle.end()));
        boost::hash_combine(seed, s.zero_pos);
        return seed;
    }
};

vector<int> goal_puzzle(8);

int heuristic(const vector<int>& puzzle) {
    int h = 0;
    for (int i = 0; i < 8; ++i) {
        if (puzzle[i] != 0)
            h += abs(puzzle[i] - goal_puzzle[i]);
    }
    return h;
}

unordered_map<State, int, StateHasher> dist;

void solve(State start) {
    priority_queue<State> q;
    start.g = 0;
    start.h = heuristic(start.puzzle);
    dist[start] = start.g;
    q.push(start);
    vector<int> dx = {-1, 1, -3, 3};
    while (!q.empty()) {
        State current = q.top();
        q.pop();
        if (current.puzzle == goal_puzzle) {
            return;
        }
        for (int i = 0; i < 4; ++i) {
            State next = current;
            next.zero_pos += dx[i];
            if (next.zero_pos < 0 || next.zero_pos >= 8 || (current.zero_pos == 2 && next.zero_pos == 3) || (current.zero_pos == 3 && next.zero_pos == 2))
                continue;
            swap(next.puzzle[next.zero_pos], next.puzzle[current.zero_pos]);
            next.g = current.g + 1;
            next.h = heuristic(next.puzzle);
            if (!dist.count(next) || next.g < dist[next]) {
                dist[next] = next.g;
                q.push(next);
            }
        }
    }
}

int main() {
    // Input and output handling...
    return 0;
}