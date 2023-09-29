#include <unordered_set>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

const int dir[4] = { 1, -1, 4, -4 };
const string target = "12345678";

inline int getZero(string s) {
    return s.find('0');
}

inline void swap(string &s, int i, int j) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

int bfs(string start) {
    queue<pair<string, int>> q;
    unordered_set<string> visited;
    
    visited.insert(start);
    q.push({start, 0});
    
    while (!q.empty()) {
        string cur = q.front().first;
        int step = q.front().second;
        q.pop();
        
        if (cur == target) {
            return step;
        }
        
        int zeroPos = getZero(cur);
        for (int i = 0; i < 4; i++) {
            int newZeroPos = zeroPos + dir[i];
            if (newZeroPos < 0 || newZeroPos > 7 || (zeroPos == 3 && i == 0) || (zeroPos == 4 && i == 1)) {
                continue;
            }
            string newS = cur;
            swap(newS, zeroPos, newZeroPos);
            if (!visited.count(newS)) {
                visited.insert(newS);
                q.push({newS, step + 1});
            }
        }
    }
    return -1;
}

int main() {
    string s;
    while (getline(cin, s)) {
        if (s.empty()) {
            break;
        }
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        cout << bfs(s) << endl;
    }
    return 0;
}