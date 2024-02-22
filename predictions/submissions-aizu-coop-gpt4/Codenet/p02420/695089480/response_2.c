#include <string.h> 

int main() {
  char str[201];
  int num_loops, num_rotations, rotation_value, total_rotations, str_length;
  for (; scanf("%s%d", str, &num_rotations), str[0] != '-'; puts("")) {
    str_length = strlen(str);
    for (num_loops = total_rotations = 0; num_loops < num_rotations; scanf("%d", &rotation_value), total_rotations += rotation_value, num_loops++)
      ;
    for (num_loops = 0; num_loops < str_length; printf("%c", str[(total_rotations + num_loops++) % str_length]))
      ;
  }
  return 0;
}