#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, vector<int>& temp, int start, int mid, int end, int& cnt) {
    int i = start, j = mid;
    for (int k = start; k < end; k++) {
        temp[k] = (j == end || (i < mid && nums[i] <= nums[j])) ? nums[i++] : nums[j++];
        cnt += j - (k + 1);
    }
    for (int k = start; k < end; k++) {
        nums[k] = temp[k];
    }
}

void mergesort(vector<int>& nums, vector<int>& temp, int start, int end, int& cnt) {
    if (end - start <= 1) return;
    int mid = start + (end - start) / 2;
    mergesort(nums, temp, start, mid, cnt);
    mergesort(nums, temp, mid, end, cnt);
    merge(nums, temp, start, mid, end, cnt);
}

int main() {
    int N, cnt = 0;
    cin >> N;
    vector<int> nums(N), temp(N);
    for (int& num : nums) cin >> num;
    mergesort(nums, temp, 0, N, cnt);
    for (int i = 0; i < N; i++) {
        if (i == N - 1) {
            cout << nums[i] << endl;
        } else {
            cout << nums[i] << " ";
        }
    }
    cout << cnt << endl;
    return 0;
}