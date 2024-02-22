#include <iostream>
using namespace std;

int main() {
  int price1, price2, price3, price4, discount1, discount2;
  cin >> price1 >> price2 >> price3 >> price4 >> discount1 >> discount2;

  int minPrice = min(min(price1, price2), min(price3, price4));
  int maxDiscount = max(discount1, discount2);
  
  int total = price1 + price2 + price3 + price4 - minPrice + maxDiscount;

  cout << total << endl;
  return 0;
}