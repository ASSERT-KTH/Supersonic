#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, bool> dic;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while(n--) {
        string op, str;
        cin >> op >> str;
        if (op[0] == 'i') {
            dic[str] = true;
        } else if (op[0] == 'f') {
            if (dic[str])
                cout << "yes" << '\n';
            else
                cout << "no" << '\n';
        }
    }
    return 0;
}