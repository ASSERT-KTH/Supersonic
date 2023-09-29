#include <iostream>
#include <vector>

typedef long long ll;

struct Gregorian {
  ll year, month, day;
};

struct Mayan {
  ll baktun, katun, tun, winal, kin;
};

int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(ll year) { return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); }

Gregorian convertToGregorian(ll baktun, ll katun, ll tun, ll winal, ll kin) {
  kin += baktun * 144000 + katun * 7200 + tun * 360 + winal * 20;
  Gregorian g;
  g.year = 2012, g.month = 12, g.day = 21 + kin;
  while (g.day > (isLeapYear(g.year + 1) ? 366 : 365))
    g.year++, g.day -= (isLeapYear(g.year) ? 366 : 365);
  while (g.day > M[g.month - 1] + (isLeapYear(g.year) && g.month == 2)) {
    g.day -= M[g.month - 1] + (isLeapYear(g.year) && g.month == 2);
    g.month++;
  }
  return g;
}

Mayan convertToMayan(ll year, ll month, ll day) {
  ll days = (year - 2012) * 365 + (year - 2012) / 4 - (year - 2012) / 100 + (year - 2012) / 400;
  for (int i = 0; i < month - 1; i++)
    days += M[i] + (i == 1 && isLeapYear(year));
  days += day - 21;
  Mayan m;
  m.kin = days % 20;
  days /= 20;
  m.winal = days % 18;
  days /= 18;
  m.tun = days % 20;
  days /= 20;
  m.katun = days % 20;
  days /= 20;
  m.baktun = days;
  return m;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  while (1) {
    std::string str;
    std::cin >> str;
    if (str == "#")
      break;
    std::vector<ll> a;
    ll num = 0;
    for (char c : str) {
      if (c == '.') {
        a.push_back(num);
        num = 0;
      } else {
        num = num * 10 + (c - '0');
      }
    }
    a.push_back(num);
    if (a.size() == 5) {
      Gregorian g = convertToGregorian(a[0], a[1], a[2], a[3], a[4]);
      std::cout << g.year << "." << g.month << "." << g.day << "\n";
    } else {
      Mayan m = convertToMayan(a[0], a[1], a[2]);
      std::cout << m.baktun << "." << m.katun << "." << m.tun << "." << m.winal << "." << m.kin << "\n";
    }
  }
  return 0;
}