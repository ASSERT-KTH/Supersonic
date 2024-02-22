#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<long long, string> H;

int getnum(char ch) {
    if (ch == 'A') return 1;
    else if (ch == 'C') return 2;
    else if (ch == 'G') return 3;
    else return 4;
}

long long getkey(string word) {
    long long sum = 0, p = 1;
    for (char i : word) {
        sum += p * getnum(i);
        p *= 5;
    }
    return sum;
}

bool insert(string str) {
    long long key = getkey(str);
    if (H.find(key) != H.end()) {
        if (H[key] == str) return false;
    }
    H[key] = str;
    return true;
}

bool find(string str) {
    long long key = getkey(str);
    if (H.find(key) != H.end()) {
        if (H[key] == str) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string com, word;
    int NumOfCom;
    scanf("%d", &NumOfCom);
    while (NumOfCom--) {
        cin >> com >> word;
        if (com[0] == 'i') {
            insert(word);
        } else {
            if (find(word)) printf("yes\n");
            else printf("no\n");
        }
    };
    return 0;
}