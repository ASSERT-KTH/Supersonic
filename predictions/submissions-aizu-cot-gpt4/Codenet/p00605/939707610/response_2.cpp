#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, B;
    bool a;

    while (cin >> N >> K, N || K) 
    {
        vector<int> S(K);
        for (int i = K; i--;)
            cin >> S[i];

        a = true;
        for (int i = 0; i < N; ++i)
        {
            for (int j = K; j--;)
            {
                cin >> B;
                S[j] -= B;
                if (S[j] < 0) 
                {
                    a = false;
                    break;
                }
            }
            if (!a)
                break;
        }
        cout << (a ? "Yes" : "No") << '\n';
    }
    return 0;
}