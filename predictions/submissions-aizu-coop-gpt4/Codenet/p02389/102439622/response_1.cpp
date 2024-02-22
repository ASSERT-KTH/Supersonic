#include <stdio.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  
  int doubleA = a * 2; // store the result of a * 2 in a variable
  int area = doubleA * b; // use the stored result to calculate the area
  int c = doubleA + b * 2; // use the stored result to calculate the perimeter
  
  printf("%d %d\n", area, c);
}