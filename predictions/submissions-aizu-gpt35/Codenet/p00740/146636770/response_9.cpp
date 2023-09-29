#include <iostream>
using namespace std;

int main() {
    int stone[50] = {0}; //initialize array outside loop
    int n, p;
    while (1) {
        cin >> n >> p;
        if (n == 0 && p == 0) {
            return 0;
        }
        int bowl = p, ans;
        bool flg = true;
        for (int i = 0; flg; i = (i + 1) % n) {
            if (bowl == 0) {
                bowl = bowl + stone[i];
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
        cout << ans << endl;
    }
}