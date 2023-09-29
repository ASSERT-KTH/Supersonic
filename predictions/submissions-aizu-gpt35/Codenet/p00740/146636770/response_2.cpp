#include <iostream>
using namespace std;

int main(void) {
    const int MAX_STONE = 50;
    const int MAX_LOOP = 1000000;

    while (1) {
        int stone[MAX_STONE] = {0};
        int bowl, n, p, ans = 0;
        cin >> n >> p;

        if (n == 0 && p == 0) {
            return 0;
        }

        bowl = p;
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

        for (int i = 0; i < MAX_LOOP; i++) {
            for (int j = 0; j < MAX_LOOP; j++) {
                int k = i + j;
            }
        }

        cout << ans << endl;
    }
    return 0;
}