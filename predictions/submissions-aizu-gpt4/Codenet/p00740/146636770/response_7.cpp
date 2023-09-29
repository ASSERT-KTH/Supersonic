#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> stone(50);
    int n, p, bowl, ans;
    bool flg;

    while (true) {
        fill(stone.begin(), stone.end(), 0);
        cin >> n >> p;

        if (n == 0 && p == 0) {
            return 0;
        }

        bowl = p;
        flg = true;

        for (int i = 0; flg; i = (i + 1) % n) {
            if (bowl == 0) {
                bowl += stone[i];
                stone[i] = 0;
            } else {
                ++stone[i];
                --bowl;

                if (bowl == 0 && stone[i] == p) {
                    ans = i;
                    flg = false;
                }
            }
        }
        cout << ans << endl;
    }
}