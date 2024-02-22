#include <iostream>
#define MAX 999999
using namespace std;
int num_prime[MAX + 1];
bool not_prime_flag[MAX + 1];
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    for (int i = 2; i < MAX + 1; ++i) {
        if (!not_prime_flag[i]) {
            for (int j = i * i; j < MAX + 1; j += 2 * i) {
                not_prime_flag[j] = true;
            }
            num_prime[i] = num_prime[i - 1] + 1;
        }
        else {
            num_prime[i] = num_prime[i - 1];
        }
    }
    while (cin >> n) {
        cout << num_prime[n] << "\n";
    }
    return 0;
}