#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;
const int INF = 1000000001;
const int MAX = 500000;
int cnt;
int S[MAX] = {0};

void merge(int *A, int left, int mid, int right) {
  int i = left, j = mid, k = left;
  while (i < mid && j < right) {
    if (A[i] <= A[j]) {
      swap(A[k++], A[i++]);
    } else {
      swap(A[k++], A[j++]);
    }
    cnt++;
  }
  while (i < mid) {
    swap(A[k++], A[i++]);
    cnt++;
  }
  while (j < right) {
    swap(A[k++], A[j++]);
    cnt++;
  }
}

void mergesort(int *A, int left, int right) {
  stack<pair<int, int>> ranges;
  ranges.push({left, right});
  while (!ranges.empty()) {
    tie(left, right) = ranges.top();
    ranges.pop();
    if (left + 1 < right) {
      int mid = (left + right) / 2;
      ranges.push({left, mid});
      ranges.push({mid, right});
      merge(A, left, mid, right);
    }
  }
}

int main() {
  int N;
  cnt = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  mergesort(S, 0, N);
  ostringstream out;
  for (int i = 0; i < N; i++) {
    if (i > 0) {
      out << " ";
    }
    out << S[i];
  }
  out << "\n" << cnt << "\n";
  cout << out.str();
  return 0;
}