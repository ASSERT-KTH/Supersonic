#include <complex>
#include <iostream>
using namespace std;

static const double EPS = 1e-12;

struct LineSeg {
  complex<double> a, b;
};

enum CCWiseState {
  ONLINE_FRONT = -2,
  CLOCKWISE,
  ON_SEGMENT,
  COUNTER_CLOCKWISE,
  ONLINE_BACK,
};

CCWiseState ccwise(complex<double> a, complex<double> b, complex<double> c) {
  complex<double> ba = b - a;
  complex<double> ca = c - a;
  double cross = (conj(ba) * ca).imag();
  double dot = (conj(ba) * ca).real();

  if (cross > EPS) {
    return COUNTER_CLOCKWISE;
  } else if (cross < -EPS) {
    return CLOCKWISE;
  } else if (dot < -EPS) {
    return ONLINE_BACK;
  } else if (norm(ba) < norm(ca)) {
    return ONLINE_FRONT;
  } else {
    return ON_SEGMENT;
  }
}

bool testcase_ends() {
  double x, y;
  if (cin >> x >> y) {
    complex<double> A(x, y);
    cin >> x >> y;
    complex<double> B(x, y);
    cin >> x >> y;
    complex<double> C(x, y);
    cin >> x >> y;
    complex<double> P(x, y);

    CCWiseState tmp = ccwise(A, P, B);
    if (tmp != ccwise(B, P, C) || tmp != ccwise(C, P, A)) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }

    return false;
  }

  return true;
}

int main() {
  int solved = 0;
  for (; !testcase_ends(); ++solved)
    ;
  
  return !solved;
}