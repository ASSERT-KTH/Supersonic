#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, i, j, B, a;
    while (a = 1, cin >> N >> K, N || K) {
        vector<int> S(K);
        for (i = K; i--;)
            cin >> S[i];
        for (i = 0; i < N; ++i)
            for (j = K; j--;)
                cin >> B, S[j] -= B, S[j] < 0 ? a = 0 : 0;
        cout << (a ? "Yes" : "No") << endl;
    }
    return 0;
}