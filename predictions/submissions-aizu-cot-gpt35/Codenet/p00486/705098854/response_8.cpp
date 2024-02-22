#include <cstdio>

int main() {
  int sum = 0, osum = 0;
  int f1, f2, f3, w, h, L, HL, temp, oxy[2][2], *LXY[2], ox, oy, max = 0, dx, dy;
  int XY[2][100000]; // Use arrays instead of vectors
  scanf("%d %d", &w, &h);
  scanf("%d", &L);
  for (f1 = 0; f1 < 2; f1++)
    LXY[f1] = new int[L];
  for (f1 = 0; f1 < L; f1++) {
    scanf("%d %d", &LXY[0][f1], &LXY[1][f1]);
    XY[0][f1] = LXY[0][f1];
    XY[1][f1] = LXY[1][f1];
  }
  // Use sort instead of stable_sort
  sort(XY[0], XY[0] + L);
  sort(XY[1], XY[1] + L);
  HL = (L + 1) / 2;
  
  for (f1 = 0; f1 < 2; f1++) {
    oxy[0][f1] = XY[f1][HL - 1];
    oxy[1][f1] = XY[f1][HL];
  }
  dx = (oxy[0][0] == oxy[1][0]) ? 1 : 2;
  dy = (oxy[0][1] == oxy[1][1]) ? 1 : 2;
  
  for (f2 = 0; f2 < dx; f2++) {
    for (f3 = 0; f3 < dy; f3++) {
      sum = 0;
      max = 0;
      for (f1 = 0; f1 < L; f1++) {
        int x = LXY[0][f1]; // Store in variables to avoid repeated indexing
        int y = LXY[1][f1];
        temp = abs(x - oxy[f2][0]) + abs(y - oxy[f3][1]);
        sum += temp;
        if (max < temp)
          max = temp;
      }
      sum *= 2;
      sum -= max;
      if (osum == 0 || osum > sum) {
        osum = sum;
        ox = oxy[f2][0];
        oy = oxy[f3][1];
      }
    }
  }
  printf("%d\n", osum);
  printf("%d %d\n", ox, oy);
  
  // Free memory for LXY
  for (f1 = 0; f1 < 2; f1++)
    delete[] LXY[f1];
  
  return 0;
}