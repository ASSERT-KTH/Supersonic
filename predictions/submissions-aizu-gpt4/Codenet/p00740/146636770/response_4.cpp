#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    vector<int> stone(50, 0);
    int n, p, bowl, ans;
    bool flg;
    while (1) {
        cin >> n >> p;
        if (n == 0 && p == 0) break;
        bowl = p;
        flg = true;
        for (int i = 0; flg; i = (i + 1) % n) {
            if (bowl == 0) {
                bowl = stone[i];
                stone[i] = 0;
            } else {
                stone[i]++;
                bowl--;
                if (bowl == 0 && stone[i] == p) {
                    ans = i;
                    flg = false;
                }
            }
        }
        cout << ans << "\n";
        fill(stone.begin(), stone.begin() + n, 0);
    }
    return 0;
}