#include <iostream>
#include <vector>
using namespace std;

bool im[1010][1010], pa[110][110];
int w, h, p, ans;

void ppp() {
    int minRot = p, minRef = p;
    ull a = 0;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            a = a * 2 + pa[i][j];
            if (pa[i][j] != pa[p - i - 1][j]) minRot = min(minRot, i);
            if (pa[i][j] != pa[i][p - j - 1]) minRef = min(minRef, i);
        }
    }
    for (int i = minRot; i < p; i++) {
        for (int j = minRef; j < p; j++) {
            ull b = 0, g = 1;
            for (int k = 0; k < p; k++) {
                b = b * 2 + im[j][k];
                g *= 2;
            }
            if (b == a) ans++;
            for (int k = p; k < w; k++) {
                b = b * 2 + im[j][k] - im[j][k - p] * g;
                if (b == a) ans++;
            }
        }
    }
}

int main() {
    while (cin >> w >> h >> p, w) {
        string s;
        for (int i = 0; i < h; i++) {
            cin >> s;
            for (int j = 0; j < s.size(); j++) {
                int t = s[j];
                int a = 6;
                while (a--) {
                    im[i][j * 6 + a] = t % 2;
                    t /= 2;
                }
            }
        }
        for (int i = 0; i < p; i++) {
            cin >> s;
            for (int j = 0; j < s.size(); j++) {
                int t = s[j];
                int a = 6;
                while (a--) {
                    pa[i][j * 6 + a] = t % 2;
                    t /= 2;
                }
            }
        }
        ans = 0;
        for (int i = 0; i < 4; i++) {
            ppp();
            swap(im, pa);
            ppp();
            swap(im, pa);
            for (int j = 0; j < p; j++) {
                for (int k = 0; k < p / 2; k++) {
                    swap(pa[j][k], pa[j][p - k - 1]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}