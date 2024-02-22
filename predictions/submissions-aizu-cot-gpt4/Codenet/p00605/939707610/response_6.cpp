#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, i, j, B;
    bool a;
    while (cin >> N >> K, N || K) {
        vector<int> S(K);
        a = true;
        for (i = K; i--;)
            cin >> S[i];
        for (i = 0; i < N && a; ++i) {
            for (j = K; j--;) {
                cin >> B;
                S[j] -= B;
                if (S[j] < 0) {
                    a = false;
                    break;
                }
            }
        }
        cout << (a ? "Yes" : "No") << endl;
    }
    return 0;
}