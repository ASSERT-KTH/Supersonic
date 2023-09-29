#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, bool> H;

int insert(const string& str) {
    if(H.find(str) == H.end()) {
        H[str] = true;
        return 1;
    }
    return 0;
}

int find(const string& str) {
    if(H.find(str) != H.end()) {
        return 1;
    }
    return 0;
}

int main() {
    string com, word;
    int NumOfCom;
    cin >> NumOfCom;
    while(NumOfCom--) {
        cin >> com >> word;
        if(com[0] == 'i') {
            insert(word);
        } else {
            cout << (find(word) ? "yes" : "no") << endl;
        }
    }
    return 0;
}