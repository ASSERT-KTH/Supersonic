#include <iostream>
#include <vector>

using namespace std;

vector<int> lists(300001, 0);

void sieve() {
    for (int i=2; i <= 300000; i++) {
        if (lists[i])
            continue;
        if (i % 7 == 1 || i % 7 == 6) {
            for (int j = i; j <= 300000; j += i) {
                lists[j] = i;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    
    int n;
    while (cin >> n && n != 1) {
        cout << n << ':';
        int temp = n;
        while (temp > 1) {
            cout << " " << lists[temp];
            temp /= lists[temp];
        }
        cout << '\n';
    }
    return 0;
}