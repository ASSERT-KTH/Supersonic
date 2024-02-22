#include <algorithm>
#include <bitset>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 300000;

int main() {
    bitset<MAXN + 1> checked;
    vector<int> lists;
    for (int i = 2; i <= MAXN; ++i) {
        if (checked[i])
            continue;
        if (i % 7 == 1 || i % 7 == 6) {
            lists.push_back(i);
            for (int j = i; j <= MAXN; j += i) {
                checked.set(j);
            }
        }
    }
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 1)
            break;
        vector<int> ans;
        for (auto p : lists) {
            if (n % p == 0) {
                ans.push_back(p);
            }
        }
        printf("%d:", n);
        for (int i = 0; i < ans.size(); ++i) {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}