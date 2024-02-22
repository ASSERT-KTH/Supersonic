#include <stdio.h>

int main() {
  int arr[3];
  scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
  
  printf("%s\n", (arr[0] < arr[1] && arr[1] < arr[2]) ? "Yes" : "No");
  
  return 0;
}