#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    vector<pair<int, int>> dimensions;
    int h, w;

    while (cin >> h >> w, h || w) {
        dimensions.emplace_back(h, w);
    }

    for (const auto& [H, W] : dimensions) {
        cout << string(H, '\n' + string(W, '#')) << "\n\n";
    }

    return 0;
}