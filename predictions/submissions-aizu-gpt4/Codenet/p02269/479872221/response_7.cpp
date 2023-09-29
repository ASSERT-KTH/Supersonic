#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    unordered_set<string> H;
    char com[9], word[14];
    int NumOfCom;
    cin >> NumOfCom;
    while (NumOfCom) {
        cin >> com >> word;
        if (com[0] == 'i') {
            H.insert(word);
        } else {
            if (H.find(word) != H.end()) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
        NumOfCom--;
    };
    return 0;
}