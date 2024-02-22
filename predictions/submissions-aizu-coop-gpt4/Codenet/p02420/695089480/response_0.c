#include <stdio.h>
#include <string.h>

int main() {
  char input_string[201];
  while (scanf("%s", input_string), input_string[0] != '-') {
    int num_shifts;
    scanf("%d", &num_shifts);
    
    int string_length = strlen(input_string);
    int total_shift = 0;
    for (int i = 0; i < num_shifts; ++i) {
      int shift;
      scanf("%d", &shift);
      total_shift += shift;
    }

    for (int i = 0; i < string_length; ++i) {
      printf("%c", input_string[(total_shift + i) % string_length]);
    }

    fputs("\n", stdout);
  }

  return 0;
}