#include <stdio.h>

int main(void) {
  int arr[3];
  scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

  if (arr[0] < arr[1] && arr[1] < arr[2]) {
    puts("Yes");
  } else {
    puts("No");
  }

  return 0;
}