#include <bits/stdc++.h>
#define N 3
#define MAX_H 1010
#define MAX_P 110
using namespace std;

typedef unsigned long long ull;

bool im[MAX_H][MAX_P * 6], pa[MAX_P][MAX_P * 6];
int w, h, p, ans;
vector<ull> used;

void ppp()
{
    ull a = 0;
    ull roll[MAX_H][MAX_P] = {};
    for (int i = 0; i < p; i++)
        for (int j = 0; j < p * 6; j++)
            a = a * N + pa[i][j];
    for (int i = 0; i < used.size(); i++)
        if (used[i] == a)
            return;
    used.push_back(a);
    for (int j = 0; j < h; j++)
    {
        ull b = 0, g = 1;
        for (int i = 0; i < p * 6; i++)
            b = b * N + im[j][i], g *= N;
        roll[j][p - 1] = b;
        for (int i = p; i < w; i++)
        {
            b = b * N + im[j][i * 6] * 4 + im[j][i * 6 + 1] * 2 + im[j][i * 6 + 2]
                - im[j][i * 6 - p * 6] * g;
            roll[j][i] = b;
        }
    }
    for (int j = p - 1; j < w; j++)
    {
        ull b = 0, g = 1, n = 1;
        for (int i = 0; i < p; i++)
            n *= N;
        for (int i = 0; i < p; i++)
            for (int k = 0; k < 6; k++)
                b = b * N + roll[i][j * 6 + k], g *= N;
        if (b == a)
            ans++;
        for (int i = p; i < h; i++)
        {
            b = b * N + roll[i][j * 6] * g + roll[i][j * 6 + 1] * (g / N)
                + roll[i][j * 6 + 2] * (g / N / N) - roll[i - p][j * 6] * g * n
                - roll[i - p][j * 6 + 1] * g * (n / N) - roll[i - p][j * 6 + 2] * (g / N / N) ;
            if (b == a)
                ans++;
        }
    }
}

void ch()
{
    bool npa[MAX_P][MAX_P * 6];
    for (int i = 0; i < p; i++)
        for (int j = 0; j < p * 6; j++)
            npa[i][j] = pa[p - j / 6 - 1][j % 6 + (p - 1 - i) * 6];
    memcpy(pa, npa, sizeof(npa));
}

void ch1()
{
    for (int i = 0; i < p; i++)
        for (int j = 0; j < p * 3; j++)
            swap(pa[i][j], pa[i][p * 6 - 1 - j]);
}

int main()
{
    int D[256];
    for (int i = 'A'; i <= 'Z'; i++)
        D[i] = i - 'A';
    for (int i = 'a'; i <= 'z'; i++)
        D[i] = i - 'a' + 26;
    for (int i = '0'; i <= '9'; i++)
        D[i] = i - '0' + 52;
    D['+'] = 62, D['/'] = 63;
    while (cin >> w >> h >> p, w)
    {
        string s;
        used.clear();
        for (int i = 0; i < h; i++)
        {
            cin >> s;
            for (int j = 0; j < s.size(); j++)
            {
                int t = D[s[j]];
                int a = 5;
                while (a >= 0)
                    im[i][j * 6 + a] = t % 2, t /= 2, --a;
            }
        }
        for (int i = 0; i < p; i++)
        {
            cin >> s;
            for (int j = 0; j < s.size(); j++)
            {
                int t = D[s[j]];
                int a = 5;
                while (a >= 0)
                    pa[i][j * 6 + a] = t % 2, t /= 2, --a;
            }
        }
        ans = 0;
        for (int i = 0; i < 4; i++)
        {
            ppp();
            ch1();
            ppp();
            ch();
        }
        cout << ans << endl;
    }
    return 0;
}