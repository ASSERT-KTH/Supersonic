#include<iostream>
#include<vector>
#include<string>

#define N 3
typedef unsigned long long ull;

typedef struct{
    bool im[1010][1010], pa[110][110];
    int w, h, p, ans;
    std::vector<ull> used;
}ImageData;

void ppp(ImageData &imgData) {
  ull a = 0;
  ull roll[1001][1001] = {};
  for (int i = 0; i < imgData.p; i++)
    for (int j = 0; j < imgData.p; j++)
      a = a * N + imgData.pa[i][j];
  for (int i = 0; i < imgData.used.size(); i++)
    if (imgData.used[i] == a)
      return;
  imgData.used.push_back(a);
  
  ull g = 1;
  for (int i = 0; i < imgData.p; i++)
      g *= N;

  for (int j = 0; j < imgData.h; j++) {
    ull b = 0;
    for (int i = 0; i < imgData.p; i++)
      b = b * N + imgData.im[j][i];
    roll[j][imgData.p - 1] = b;
    for (int i = imgData.p; i < imgData.w; i++) {
      b = b * N + imgData.im[j][i] - imgData.im[j][i - imgData.p] * g;
      roll[j][i] = b;
    }
  }

  ull n = 1;
  for (int i = 0; i < imgData.p; i++)
      n *= N;

  for (int j = imgData.p - 1; j < imgData.w; j++) {
    ull b = 0, g = 1;
    for (int i = 0; i < imgData.p; i++)
      b = b * n + roll[i][j], g *= n;
    if (b == a)
      imgData.ans++;
    for (int i = imgData.p; i < imgData.h; i++) {
      b = b * n + roll[i][j] - roll[i - imgData.p][j] * g;
      if (b == a)
        imgData.ans++;
    }
  }
}
// Rest of the code remains same except replace all global variables to be accessed from imgData which is passed as parameter