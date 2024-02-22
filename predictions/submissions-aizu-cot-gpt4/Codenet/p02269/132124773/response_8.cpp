#include <iostream>
#include <map>
#include <string>

using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    cin >> n;
    map<string, bool> Dic;
    Dic.reserve(n); // reserve space for n elements
    string com, word;
    while (n--) {
        cin >> com >> word;
        if (com == "i")
            Dic[word] = true;
        else {
            if (Dic.find(word) != Dic.end()) // use find() to check if word is in the map
                cout << "yes\n"; // use '\n' instead of endl
            else
                cout << "no\n"; // use '\n' instead of endl
        }
    }
    return 0;
}