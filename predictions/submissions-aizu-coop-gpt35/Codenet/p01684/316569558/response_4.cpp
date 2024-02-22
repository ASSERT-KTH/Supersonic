double calc(double ra, double rb, double s) {
  double lb = abs(ra - rb);
  double ub = ra + rb;
  double sum = 0.0;
  double d, tha, thb;
  
  for (int _ = 0; _ < 80; ++_) {
    d = (lb + ub) / 2;
    tha = acos((ra * ra + d * d - rb * rb) / (2.0 * d * ra));
    thb = acos((rb * rb + d * d - ra * ra) / (2.0 * d * rb));
    sum = ra * ra * tha + rb * rb * thb - ra * d * sin(tha);
    if (sum > s) {
      lb = d;
    } else {
      ub = d;
    }
  }
  
  return ub;
}