#include <stdio.h>

int values[5004], maxValue, temp, index, value, i, format = "%d\n";

int main() {
  scanf("%d", &values[0]);
  for (i = 1; i <= values[0]; i++)
    scanf("%d", &values[i]);
  
  while (scanf("%d", &value) != EOF) {
    for (index = temp = maxValue = 0; index++ < values[0]; temp = values[index], values[index] = maxValue < temp ? maxValue = temp : temp)
      temp = (value == values[index]) ? temp + 1 : temp;
  }
  
  printf("%d\n", maxValue);
  
  return 0;
}