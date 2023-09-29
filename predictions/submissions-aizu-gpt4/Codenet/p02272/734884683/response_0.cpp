#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

vector<uint32_t> merge(const vector<uint32_t>& left, const vector<uint32_t>& right) {
    vector<uint32_t> result;
    auto left_it = left.begin();
    auto right_it = right.begin();
    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it <= *right_it) {
            result.push_back(*left_it);
            ++left_it;
        } else {
            result.push_back(*right_it);
            ++right_it;
        }
    }
    result.insert(result.end(), left_it, left.end());
    result.insert(result.end(), right_it, right.end());
    return result;
}

vector<uint32_t> mergeSort(vector<uint32_t>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }
    vector<uint32_t> left(arr.begin(), arr.begin() + arr.size() / 2);
    vector<uint32_t> right(arr.begin() + arr.size() / 2, arr.end());
    return merge(mergeSort(left), mergeSort(right));
}

int main() {
    int n;
    cin >> n;
    vector<uint32_t> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    A = mergeSort(A);
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
    return 0;
}