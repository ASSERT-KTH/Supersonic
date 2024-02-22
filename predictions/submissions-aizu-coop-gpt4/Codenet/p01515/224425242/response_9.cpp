#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int mask;
unordered_map<string, bool> memo;

string preprocess(string S) {
    for (char &c : S) {
        if (islower(c)) {
            c = (mask >> (c - 'a')) & 1 ? 'T' : 'F';
        }
    }
    return S;
}

bool solve(string S) {
    if (memo.count(S)) {
        return memo[S];
    }

    vector<bool> stk;
    for (char c : S) {
        if (c == 'T') {
            stk.push_back(true);
        } else if (c == 'F') {
            stk.push_back(false);
        } else if (c == '+' || c == '*') {
            bool x = stk.back(); stk.pop_back();
            bool y = stk.back(); stk.pop_back();
            bool res = (c == '+' ? x || y : x && y);
            stk.push_back(res);
        } else if (c == '-') {
            bool x = stk.back(); stk.pop_back();
            stk.push_back(!x);
        }
    }

    bool res = stk.back(); stk.pop_back();
    return memo[S] = res;
}

int main() {
    string S;
    while (cin >> S && S != "#") {
        memo.clear();
        bool ans = true;
        for (mask = 0; mask < (1 << 11); mask++) {
            if (!solve(preprocess(S))) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}