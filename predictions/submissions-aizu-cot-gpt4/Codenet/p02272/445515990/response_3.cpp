#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int cnt;
vector<int> S;
vector<int> L;
vector<int> R;

void merge(int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  L.reserve(n1 + 1);
  R.reserve(n2 + 1);

  copy(S.begin() + left, S.begin() + mid, back_inserter(L));
  copy(S.begin() + mid, S.begin() + right, back_inserter(R));
  
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  int i = 0, j = 0;
  
  for (int k = left; k < right; ++k) {
    if(L[i] <= R[j]) {
      S[k] = L[i++];
    } else {
      S[k] = R[j++];
    }
    cnt++;
  }
}

void mergesort(int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(left, mid);
    mergesort(mid, right);
    merge(left, mid, right);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  S.reserve(N);
  for (int i = 0; i < N; ++i) {
    int temp;
    cin >> temp;
    S.push_back(temp);
  }

  mergesort(0, N);

  for (int i = 0; i < N; ++i) {
    cout << S[i] << (i == N - 1 ? "\n" : " ");
  }
  
  cout << cnt << '\n';
  return 0;
}