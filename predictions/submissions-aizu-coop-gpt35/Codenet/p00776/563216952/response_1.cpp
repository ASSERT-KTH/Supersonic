#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int countPermutations(string t, int now) {
    if (now == t.size()) {
        return 1;
    }
    int count = 0;
    bool hasDuplicate = false;
    for (int i = 0; i < now; i++) {
        if (t[i] == t[now]) {
            hasDuplicate = true;
            break;
        }
    }
    if (!hasDuplicate && t[now] != 'z') {
        t[now] = t[now] + 1;
        count += countPermutations(t, now + 1);
        t[now] = t[now] - 1; // Reset the character for backtracking
    }
    count += countPermutations(t, now + 1);
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (1) {
        cin >> s;
        if (s == "#")
            break;
        int totalPermutations = countPermutations(s, 0);
        cout << totalPermutations << endl;
        if (totalPermutations <= 10) {
            // Generate and print all permutations
            sort(s.begin(), s.end());
            do {
                cout << s << endl;
            } while (next_permutation(s.begin(), s.end()));
        } else {
            // Generate and print a subset of permutations
            sort(s.begin(), s.end());
            for (int i = 0; i < 5; i++) {
                cout << s << endl;
                next_permutation(s.begin(), s.end());
            }
            for (int i = totalPermutations - 5; i < totalPermutations; i++) {
                cout << s << endl;
                prev_permutation(s.begin(), s.end());
            }
        }
    }
    return 0;
}