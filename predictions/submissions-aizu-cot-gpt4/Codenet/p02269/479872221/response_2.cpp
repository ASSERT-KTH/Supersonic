#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

long long getkey(char word[]) {
    int sum = 0, p = 1, i;
    for (i = 0; word[i]; i++) {
        sum = sum + p * (word[i] - 'A' + 1);
        p = p * 5;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<long long, bool> dnaMap;
    char com[9], word[14];
    int NumOfCom;
    cin >> NumOfCom;
    while (NumOfCom) {
        cin >> com >> word;
        if (com[0] == 'i') {
            dnaMap[getkey(word)] = true;
        } else {
            if (dnaMap[getkey(word)]) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
        NumOfCom--;
    };
    return 0;
}