#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<size_t> chk;
int n;
string ins, s;

size_t hashFunc(const string& s) {
    size_t val = 0;
    for (char c : s) {
        val = val * 5 + (c - 'A' + 1) % 5;
    }
    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (n--) {
        cin >> ins >> s;
        if (ins[0] == 'i') {
            chk.insert(hashFunc(s));
        } else {
            cout << (chk.count(hashFunc(s)) ? "yes" : "no") << '\n';
        }
    }
    return 0;
}