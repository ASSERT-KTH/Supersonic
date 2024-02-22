#include <iostream>
#include <vector>
#include <sstream>

const int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int y) {
  return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

void M2S(int b, int ka, int t, int w, int ki, int& y, int& m, int& d) {
  ki += w * 20 * 18 * 20 + t * 20 * 18 + ka * 20 + b * 20 * 20;
  d = 21 + ki;
  m = 12;
  y = 2012;
  
  while (d > M[m - 1] + (check(y) && m == 2)) {
    d -= M[m - 1] + (check(y) && m == 2);
    m++;
    if (m > 12) {
      m = 1;
      y++;
    }
  }
}

void S2M(int y, int m, int d, int& b, int& ka, int& t, int& w, int& ki) {
  y -= 2012;
  d += (y ? 10 : -21);
  
  for (int i = 0; i < m - 1 && y; i++) {
    d += (M[i] + (i == 1 && check(y + 2012)));
  }
  
  y--;
  while (y > 0) {
    d += 365 + check(y + 2012);
    y--;
  }
  
  ki = d % (13 * 20 * 20 * 18 * 20);
  w = ki / (20 * 18 * 20);
  ki %= (20 * 18 * 20);
  t = w / (18 * 20);
  w %= (18 * 20);
  ka = t / 20;
  t %= 20;
  b = ka / 20;
  ka %= 20;
}

int main() {
  std::string str;
  
  while (std::cin >> str && str != "#") {
    std::vector<int> a;
    int num;
    
    std::stringstream ss(str);
    while (ss >> num) {
      a.push_back(num);
    }
    
    if (a.size() == 5) {
      int y, m, d;
      M2S(a[0], a[1], a[2], a[3], a[4], y, m, d);
      std::cout << y << "." << m << "." << d << std::endl;
    } else {
      int b, ka, t, w, ki;
      S2M(a[0], a[1], a[2], b, ka, t, w, ki);
      std::cout << b << "." << ka << "." << t << "." << w << "." << ki << std::endl;
    }
  }
  
  return 0;
}