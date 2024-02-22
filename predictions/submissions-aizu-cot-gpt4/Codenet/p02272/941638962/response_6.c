#include <iostream>
#include <vector>
using namespace std;

void mergesort(vector<int>&, int, int);
void merge(vector<int>&, int, int, int);

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++)
        cin >> S[i];
    int count = 0;
    mergesort(S, 0, n);
    for (int i = 0; i < n; i++) {
        cout << S[i];
        if (i != n - 1)
            cout << " ";
    }
    cout << "\n" << count << "\n";
    return 0;
}

void mergesort(vector<int>& S, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergesort(S, left, mid);
        mergesort(S, mid, right);
        merge(S, left, mid, right);
    }
}

void merge(vector<int>& S, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int i = 0, j = mid, k = left;
    while (k < right) {
        if (j >= right || (i < mid && S[i] <= S[j])) {
            S[k++] = S[i++];
        } else {
            S[k++] = S[j++];
            count += mid - i;
        }
    }
}