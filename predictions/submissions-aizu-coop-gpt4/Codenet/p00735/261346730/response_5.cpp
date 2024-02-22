#include <vector>
#include <iostream>
using namespace std;

#define MAX 300001

int main() {
    vector<int> lists;
    bool checked[MAX] = {};

    for (int i = 1; i < MAX; i += 7) {
        if (!checked[i]) {
            lists.push_back(i);
            for (int j = i * i; j < MAX; j += i) {
                checked[j] = true;
            }
        }
    }
    for (int i = 6; i < MAX; i += 7) {
        if (!checked[i]) {
            lists.push_back(i);
            for (int j = i * i; j < MAX; j += i) {
                checked[j] = true;
            }
        }
    }

    while (true) {
        int n;
        cin >> n;
        if (n == 1) break;
        vector<int> ans;
        for (auto p : lists) {
            if (n % p == 0) {
                ans.push_back(p);
                for (int i = 0; i < ans.size(); ++i) {
                    int factor = p * ans[i];
                    if (n % factor == 0 && !checked[factor]) {
                        ans.push_back(factor);
                    }
                }
            }
        }
        cout << n << ':';
        for (auto a : ans) {
            cout << " " << a;
        }
        cout << endl;
    }

    return 0;
}