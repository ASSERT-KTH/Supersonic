#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int H, W;
    while (cin >> H >> W && H != 0 && W != 0) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << ((i ^ j) & 1 ? '.' : '#');
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}