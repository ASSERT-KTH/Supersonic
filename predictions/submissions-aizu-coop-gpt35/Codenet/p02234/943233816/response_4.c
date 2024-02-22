int** m;

// Allocate memory for the m matrix
m = (int**)malloc((n + 1) * sizeof(int*));
for (i = 0; i <= n; i++) {
  m[i] = (int*)malloc((n + 1) * sizeof(int));
}