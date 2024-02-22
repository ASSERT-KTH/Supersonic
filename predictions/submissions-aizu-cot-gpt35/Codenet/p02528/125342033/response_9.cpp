#include <cstdio>

int main() {
  int n;
  int A[1000001];

  // Read input
  char input[1000001];
  fgets(input, sizeof(input), stdin);
  sscanf(input, "%d", &n);

  fgets(input, sizeof(input), stdin);
  for (int i = 0; i < n; i++)
    sscanf(input, "%d", A + i);

  // Sort array
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (A[j] > A[j+1]) {
        int temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
    }
  }

  // Print sorted array
  char output[1000001];
  int len = sprintf(output, "%d", A[0]);
  for (int i = 1; i < n; i++)
    len += sprintf(output + len, " %d", A[i]);
  puts(output);

  return 0;
}