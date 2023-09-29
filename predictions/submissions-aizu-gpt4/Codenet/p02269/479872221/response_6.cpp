#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> H;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int NumOfCom;
    cin >> NumOfCom;
    string com, word;

    while (NumOfCom--) {
        cin >> com >> word;
        if (com[0] == 'i') {
            H[word] = true;
        } else {
            if (H.find(word) != H.end()) {
                cout << "yes" << '\n';
            } else {
                cout << "no" << '\n';
            }
        }
    }

    return 0;
}