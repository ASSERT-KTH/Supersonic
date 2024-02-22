#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, B;
    while (cin >> N >> K, N || K) {
        vector<int> S(K);
        for (int i = K; i--;)
            cin >> S[i];
        bool isPossible = true;
        for (int i = 0; i < N; ++i) {
            for (int j = K; j--;) {
                cin >> B;
                S[j] -= B;
                if (S[j] < 0) {
                    isPossible = false;
                    break;
                }
            }
            if (!isPossible) break;
        }
        cout << (isPossible ? "Yes" : "No") << endl;
    }
    return 0;
}