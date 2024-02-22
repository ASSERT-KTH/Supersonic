#include <iostream>
using namespace std;

const int MAX_K = 1e6; // assuming K does not exceed 1 million
int S[MAX_K];

int main() {
    int N, K, B;
    while (cin >> N >> K, N || K) {
        int a = 1;
        for (int i = K; i--;)
            cin >> S[i];
        for (int i = 0; i < N; ++i)
            for (int j = K; j--;) {
                cin >> B;
                S[j] -= B;
                if (S[j] < 0) a = 0;
            }
        cout << (a ? "Yes" : "No") << endl;
    }
}