#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int M = 10;

int main()
{
    int k;
    while (cin >> k, k)
    {
        string s, t;
        cin >> s >> t;
        vector<int> dif(k);
        for (int i = 0; i < k; ++i)
        {
            dif[i] = ((t[i] - s[i]) + M) % M;
        }
        sort(dif.begin(), dif.end());

        int ans = k;
        for (int d = 0; d < ans; ++d)
        {
            if (dif[d] == 0)
            {
                --ans;
            }
            else
            {
                for (int i = d; i < k; ++i)
                {
                    dif[i] = (dif[i] - dif[d] + M) % M;
                }
                sort(dif.begin() + d + 1, dif.end());
            }
        }
        cout << ans << endl;
    }
}