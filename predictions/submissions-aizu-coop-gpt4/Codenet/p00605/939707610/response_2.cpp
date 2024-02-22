#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, B, a;
    while (a = 1, cin >> N >> K, N || K) {
        vector<int> S(K);  // Using vector to manage memory
        for (int i = 0; i < K; ++i)
            cin >> S[i];
        for (int i = 0; i < N && a; ++i) {  // Skip loop if 'a' is already 0
            for (int j = 0; j < K; ++j) {
                cin >> B;
                S[j] -= B;
                if (S[j] < 0)
                    a = 0;
            }
        }
        cout << (a ? "Yes" : "No") << endl;
    }
    return 0;
}