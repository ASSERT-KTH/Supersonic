int payment(vector<int> p) {
  int total_payment = 0;
  for (int i = 0; i < p.size(); i++) {
    total_payment += (10 * pow(10, i)) * p[i];
  }
  return total_payment;
}