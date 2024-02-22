#include <iostream>
#include <string>
using namespace std;

bool solve(const string& S) {
    int mask;
    for (mask = 0; mask < (1 << 11); mask++) {
        int pos = 0;
        bool result = equation(S, pos);
        if (!result) {
            return false;
        }
    }
    return true;
}

bool equation(const string& S, int& pos) {
    bool left = formula(S, pos);
    pos++;
    bool right = formula(S, pos);
    return left == right;
}

bool formula(const string& S, int& pos) {
    if (S[pos] == '(') {
        pos++;
        bool left = formula(S, pos);
        char op = S[pos];
        pos++;
        if (op == '-')
            pos++;
        bool right = formula(S, pos);
        pos++;
        bool ret = deduce(left, op, right);
        return ret;
    } else if (S[pos] == '-') {
        pos++;
        return !formula(S, pos);
    } else {
        return boolean(S, pos);
    }
}

bool deduce(bool x, char op, bool y) {
    if (op == '*') {
        return x && y;
    } else if (op == '+') {
        return x || y;
    } else {
        return !x || y;
    }
}

bool boolean(const string& S, int& pos) {
    bool ret;
    if (isalpha(S[pos])) {
        ret = (S[pos] == 'T');
        pos++;
    } else {
        static const bool values[] = {
            (mask >> 0) & 1, (mask >> 1) & 1, (mask >> 2) & 1,
            (mask >> 3) & 1, (mask >> 4) & 1, (mask >> 5) & 1,
            (mask >> 6) & 1, (mask >> 7) & 1, (mask >> 8) & 1,
            (mask >> 9) & 1, (mask >> 10) & 1
        };
        ret = values[S[pos] - 'a'];
        pos++;
    }
    return ret;
}

int main() {
    string S;
    while (cin >> S && S != "#") {
        bool result = solve(S);
        if (result) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}