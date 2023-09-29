#include <iostream>
#include <algorithm>

using namespace std;

int a[20];
double sum[720][9];

void solve()
{
    for (int i = 0; i < 9; ++i)
        cin >> a[i];
    for (int i = 9; i < 18; ++i)
        cin >> a[i];

    sort(a, a + 18);

    double win = 0;
    double draw = 0;
    double lose = 0;

    do
    {
        int j = 0;
        while (a[j] < 10)
            ++j;

        double temp = 0;
        for (int i = 0; i < j / 2; ++i)
            temp += sum[i][j / 2];

        if (j == 18)
        {
            win += temp;
            continue;
        }
        draw += temp;

        temp = 0;
        for (int i = j / 2; i < j; ++i)
            temp += sum[i][j];

        lose += temp;

    } while (next_permutation(a, a + 18));

    cout.precision(5);
    cout << fixed << win / 362880 << " " << lose / 362880 << "\n";
}

int main()
{
    for (int i = 0; i < 9; ++i)
    {
        sum[i][1] = i + 1;
        for (int j = 2; j <= i + 1; ++j)
            sum[i][j] = sum[i][j - 1] * (i + 1 - j + 1) / j;
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}