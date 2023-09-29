#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int main() {
    unordered_map<string, bool> dic;
    int n;
    string opstr, str;
    cin >> n;
    while (n--) {
        cin >> opstr >> str;
        if (opstr[0] == 'i') {
            dic[str] = true;
        } else if (opstr[0] == 'f') {
            if (dic[str])
                puts("yes");
            else
                puts("no");
        }
    }
    return 0;
}