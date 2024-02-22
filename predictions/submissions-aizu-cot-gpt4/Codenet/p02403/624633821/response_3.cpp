#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    while (cin >> H >> W && (H != 0 || W != 0)) {
        for (int i = 0; i < H; i++) {
            cout << string(W, '#') << '\n';
        }
        cout << '\n';
    }

    return 0;
}