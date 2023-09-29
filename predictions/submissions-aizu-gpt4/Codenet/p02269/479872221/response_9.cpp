#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, bool> dict;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int NumOfCom;
    cin >> NumOfCom;
    string com, word;

    while (NumOfCom--) {
        cin >> com >> word;
        if (com[0] == 'i') {
            dict[word] = true;
        } else {
            if (dict[word]) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }
    return 0;
}