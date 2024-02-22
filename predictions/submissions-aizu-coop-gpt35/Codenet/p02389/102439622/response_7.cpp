#include <stdio.h>

int main() {
  int a;
  scanf("%d", &a); // Read the length of one side of the rectangle
  int area = a * a; // Calculate the area as a * a
  int perimeter = 4 * a; // Calculate the perimeter as 4 * a
  printf("%d %d\n", area, perimeter); // Print the area and perimeter
  return 0;
}