#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void counting_sort(vector<int>& v) {
    int n = v.size();
    int max_element = *max_element(v.begin(), v.end());

    for (int exp = 1; max_element / exp > 0; exp *= 10) {
        vector<int> count(10, 0);
        vector<int> output(n);

        for (int i = 0; i < n; i++)
            count[(v[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            output[count[(v[i] / exp) % 10] - 1] = v[i];
            count[(v[i] / exp) % 10]--;
        }

        v = output;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);

    for (int& num : A)
        cin >> num;

    counting_sort(A);
    
    cout << A[0];
    for (int i = 1; i < A.size(); i++)
        cout << " " << A[i];
    cout << endl;

    return 0;
}