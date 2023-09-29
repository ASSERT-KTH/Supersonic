#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> stone(50);
    int n, p, bowl;

    while (cin >> n >> p, n || p) {
        fill(stone.begin(), stone.begin() + n, 0);
        bowl = p;
        bool flg = true;
        int ans;
        for (int i = 0; flg; i = (i + 1) % n) {
            if (!bowl) {
                bowl += stone[i];
                stone[i] = 0;
            } else {
                stone[i]++;
                bowl--;
                if (!bowl && stone[i] == p) {
                    ans = i;
                    flg = false;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}