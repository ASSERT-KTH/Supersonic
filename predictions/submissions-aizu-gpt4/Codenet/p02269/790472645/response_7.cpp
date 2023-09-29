#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int dic_op(const string& str) {
    int g = 0, f = 1;
    for (const auto& ch : str) {
        switch(ch) {
            case 'A': g += f; break;
            case 'C': g += f * 2; break;
            case 'G': g += f * 3; break;
            case 'T': g += f * 4; break;
            default: return g;
        }
        f *= 5;
    }
    return g;
}

int main() {
    int n;
    string opstr, str;
    unordered_map<int, bool> dic;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> opstr >> str;
        if (opstr[0] == 'i') {
            dic[dic_op(str)] = true;
        } else if (opstr[0] == 'f') {
            cout << (dic[dic_op(str)] ? "yes" : "no") << '\n';
        }
    }
    return 0;
}