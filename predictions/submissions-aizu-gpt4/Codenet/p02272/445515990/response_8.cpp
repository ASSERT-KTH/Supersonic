#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int merge_and_count(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0, inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left, k = 0; i <= right;)
        arr[i++] = temp[k++];
    return inv_count;
}

int merge_sort(vector<int>& arr, int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count = merge_sort(arr, left, mid);
        inv_count += merge_sort(arr, mid + 1, right);
        inv_count += merge_and_count(arr, left, mid, right);
    }
    return inv_count;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    int cnt = merge_sort(arr, 0, N - 1);
    for (int i = 0; i < N; ++i)
        cout << arr[i] << (i == N - 1 ? "\n" : " ");
    cout << cnt << endl;
    return 0;
}