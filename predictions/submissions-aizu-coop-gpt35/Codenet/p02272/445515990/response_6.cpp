void merge(int *A, int left, int mid, int right) {
  int n1, n2, n, i, j;
  n1 = mid - left;
  n2 = right - mid;
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = INF;
  R[n2] = INF;
  i = 0;
  j = 0;
  for (int k = 0; k < right - left; k++) {
    if (L[i] <= R[j]) {
      A[left + k] = L[i];
      i++;
    } else {
      A[left + k] = R[j];
      j++;
    }
    cnt++;
  }
}