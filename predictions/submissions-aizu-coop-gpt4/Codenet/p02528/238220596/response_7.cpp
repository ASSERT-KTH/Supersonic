#include <cstdio>

void heapify(int a[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && a[left] > a[largest])
    largest = left;
  if (right < n && a[right] > a[largest])
    largest = right;
  if (largest != i) {
    std::swap(a[i], a[largest]);
    heapify(a, n, largest);
  }
}

void hsort(int a[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(a, n, i);
  for (int i = n - 1; i >= 0; i--) {
    std::swap(a[0], a[i]);
    heapify(a, i, 0);
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  static int a[1000000];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  hsort(a, n);
  for (int i = 0; i < n; i++)
    printf("%d%c", a[i], (i == n - 1) ? '\n' : ' ');
  return 0;
}