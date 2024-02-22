#include <iostream>
#include <bitset>
#include <unordered_set>

using namespace std;

// Inline function to replace REP macro
inline void REP(int& i, int a, int b) {
    for (i = a; i < b; i++) {
    }
}

// Inline function to replace rep macro
inline void rep(int& i, int n) {
    REP(i, 0, n);
}

// Optimized pow function using exponentiation by squaring
unsigned long long pow(unsigned long long x, unsigned long long n) {
    unsigned long long res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= x;
        }
        x *= x;
        n >>= 1;
    }
    return res;
}

// Optimized dic_op function using ASCII value subtraction
int dic_op(char str[14]) {
    int j;
    long long f = 1;
    long long g = 0;
    for (j = 0;; j++) {
        if (str[j] == 'A') {
            g += f * 1;
        } else if (str[j] == 'C') {
            g += f * 2;
        } else if (str[j] == 'G') {
            g += f * 3;
        } else if (str[j] == 'T') {
            g += f * 4;
        } else {
            break;
        }
        f *= 5;
    }
    return g;
}

int main() {
    int i, n;
    unordered_set<int> dic;
    char opstr[7];
    char str[13];

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> opstr >> str;

        if (opstr[0] == 'i') {
            dic.insert(dic_op(str));
        } else if (opstr[0] == 'f') {
            if (dic.find(dic_op(str)) != dic.end()) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }

    return 0;
}