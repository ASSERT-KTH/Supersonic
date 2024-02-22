#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    unordered_map<string, bool> Dic;
    string com, word;
    while (n--) {
        cin >> com >> word;
        if (com == "insert")
            Dic[word] = true;
        else {
            if (Dic[word])
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }
    return 0;
}