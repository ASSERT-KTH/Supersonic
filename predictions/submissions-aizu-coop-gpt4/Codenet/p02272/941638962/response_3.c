#include <stdio.h>
#include <vector>
#define MAX 1000000001

void mergesort(std::vector<int> &S);
void merge(std::vector<int> &S, int left, int mid, int right, std::vector<int> &Left, std::vector<int> &Right, int &count);

int main(void) {
  int n;
  scanf("%d", &n);
  std::vector<int> S(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);
  mergesort(S);
  for (int i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n");
  return 0;
}

void mergesort(std::vector<int> &S) {
  int n = S.size();
  std::vector<int> Left(n), Right(n);
  int count = 0;
  for (int segmentSize = 1; segmentSize < n; segmentSize *= 2) {
    for (int i = 0; i < n; i += 2 * segmentSize) {
      int mid = i + segmentSize < n ? i + segmentSize : n;
      int end = i + 2 * segmentSize < n ? i + 2 * segmentSize : n;
      merge(S, i, mid, end, Left, Right, count);
    }
  }
}

void merge(std::vector<int> &S, int left, int mid, int right, std::vector<int> &Left, std::vector<int> &Right, int &count) {
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; i++)
    Left[i] = S[left + i];
  for (int i = 0; i < n2; i++)
    Right[i] = S[mid + i];
  Left[n1] = MAX;
  Right[n2] = MAX;
  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
    if (Left[j] > Right[i])
      S[k] = Right[i++];
    else
      S[k] = Left[j++];
  }
  count += right - left;
}