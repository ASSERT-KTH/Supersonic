#include <iostream>
#include <cstring>
using namespace std;

int k, ans;
int dif[12];
const int M = 10;

// new function to calculate the difference between two characters
int getDifference(char a, char b) {
    int diff = (b - a + M) % M;
    return diff;
}

void rec(int d, int p, int* tempDif) {
    if (p == k) {
        ans = d;
        return;
    }
    if (d >= ans)
        return;
    int rot = tempDif[p];
    if (rot == 0) {
        rec(d, p + 1, tempDif);
        return;
    }
    rec(d + 1, p + 1, tempDif);
    for (int i = p; i < k; i++) {
        tempDif[i] = (tempDif[i] - rot) % M;
        if (tempDif[i] < 0) {
            tempDif[i] += M;
        }
        rec(d + 1, p + 1, tempDif);
    }
    for (int i = p; i < k; i++) {
        tempDif[i] = (tempDif[i] + rot) % M;
    }
}

int main() {
    while (cin >> k, k) {
        string s, t;
        cin >> s >> t;
        memset(dif, 0, sizeof(dif));
        for (int i = 0; i < k; i++) {
            dif[i] = getDifference(s[i], t[i]);
        }
        ans = k;
        rec(0, 0, dif);
        cout << ans << endl;
    }
    return 0;
}