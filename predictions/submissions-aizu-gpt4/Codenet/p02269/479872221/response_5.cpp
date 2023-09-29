#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, bool> dict;

void insert(const string& str) {
    dict[str] = true;
}

bool find(const string& str) {
    return dict.count(str) > 0;
}

int main() {
    int NumOfCom;
    cin >> NumOfCom;
    string com, word;
    while (NumOfCom--) {
        cin >> com >> word;
        if (com[0] == 'i') {
            insert(word);
        } else {
            if (find(word)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    };
    return 0;
}