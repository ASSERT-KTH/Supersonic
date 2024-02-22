int **way = (int **)malloc((b+1) * sizeof(int *));
for (int i = 0; i <= b; i++) {
  way[i] = (int *)malloc((a+1) * sizeof(int));
}