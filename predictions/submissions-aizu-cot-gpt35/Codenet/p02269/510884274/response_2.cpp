#include <iostream>
#include <string>
using namespace std;

bool chk[244140624];
int n;
string ins, s;

int h(string s) {
    int ret = 0;
    for (char c : s) {
        ret <<= 2; // Multiply by 4
        ret |= (c == 'C') << 1; // Map 'C' to 2
        ret |= (c == 'G') << 2; // Map 'G' to 3
        ret |= (c == 'T') << 3; // Map 'T' to 4
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while (n--) {
        cin >> ins >> s;
        if (ins[0] == 'i') {
            chk[h(s)] = true;
        } else {
            cout << (chk[h(s)] ? "yes" : "no") << '\n';
        }
    }

    return 0;
}