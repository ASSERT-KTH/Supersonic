#include <iostream>
#include <vector>
#include <map>
using namespace std;

void counting_sort(vector<int> &v) {
    map<int, int> cnt;
    vector<int> tmp(v);
    for (int x : v)
        cnt[x]++;
    int index = 0;
    for(auto &i : cnt) {
        while(i.second--) {
            v[index++] = i.first;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, max_num = 0;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) {
        cin >> A[i];
        max_num = max(max_num, A[i]);
    }

    counting_sort(A);
    cout << A[0];
    for(int i=1; i<A.size(); i++) {
        cout << " " << A[i];
    }
    cout << '\n';

    return 0;
}