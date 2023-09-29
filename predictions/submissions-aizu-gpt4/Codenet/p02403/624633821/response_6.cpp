#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int,int>> pairs;
    int h, w;

    while (cin >> h >> w, h || w) {
        pairs.emplace_back(h, w);
    }

    for (const auto& [h, w] : pairs) {
        string s(w, '#');
        for (int i = 0; i < h; i++) {
            cout << s << "\n";
        }
        cout << "\n";
    }
    return 0;
}