#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Recursive function to generate permutations in lexicographically sorted order
void generatePermutations(string prefix, string remaining, int remainingLen) {
    if (remainingLen == 0) {
        cout << prefix << endl;  // Print the permutation directly
        return;
    }
    
    bool used[26] = { false };  // Array to keep track of character availability
    
    // Count the occurrence of each character in the prefix
    for (char c : prefix) {
        used[c - 'a'] = true;
    }
    
    // Generate permutations by appending each available character to the prefix
    for (char c : remaining) {
        if (!used[c - 'a']) {
            string newPrefix = prefix + c;
            string newRemaining = remaining;
            newRemaining.erase(remove(newRemaining.begin(), newRemaining.end(), c), newRemaining.end());
            generatePermutations(newPrefix, newRemaining, remainingLen - 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    while (true) {
        cin >> s;
        if (s == "#")
            break;
        
        // Generate permutations
        int len = s.length();
        sort(s.begin(), s.end());  // Sort the input string
        generatePermutations("", s, len);
        
        cout << len << endl;
        if (len <= 10) {
            for (int i = 0; i < len; i++) {
                cout << s[i] << endl;
            }
        } else {
            for (int i = 0; i < 5; i++) {
                cout << s[i] << endl;
            }
            for (int i = len - 5; i < len; i++) {
                cout << s[i] << endl;
            }
        }
    }
    return 0;
}