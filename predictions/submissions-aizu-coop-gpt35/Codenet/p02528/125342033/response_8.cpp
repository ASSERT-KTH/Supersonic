#include <cstdio>
#include <vector>

int main() {
  int n;
  scanf("%d", &n);

  std::vector<int> A(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  std::sort(A.begin(), A.end());

  bool firstElement = true;
  char outputBuffer[10];
  int outputBufferIndex = 0;

  for (int i = 0; i < n; i++) {
    if (!firstElement) {
      outputBuffer[outputBufferIndex++] = ' ';
    }
    int num = A[i];
    if (num == 0) {
      outputBuffer[outputBufferIndex++] = '0';
    } else {
      if (num < 0) {
        outputBuffer[outputBufferIndex++] = '-';
        num = -num;
      }
      int digits = 0;
      while (num > 0) {
        outputBuffer[outputBufferIndex++] = static_cast<char>('0' + num % 10);
        num /= 10;
        digits++;
      }
      for (int j = 0; j < digits / 2; j++) {
        std::swap(outputBuffer[outputBufferIndex - j - 1], outputBuffer[outputBufferIndex - digits + j]);
      }
    }
    firstElement = false;
  }

  outputBuffer[outputBufferIndex++] = '\n';
  outputBuffer[outputBufferIndex] = '\0';

  printf("%s", outputBuffer);

  return 0;
}