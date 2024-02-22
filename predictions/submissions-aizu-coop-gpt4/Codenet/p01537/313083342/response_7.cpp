// Lambda function definitions moved outside
auto c3 = [](const P &a, const P &b, const P &c) {
  ld A = norm(b - c);
  ld B = norm(c - a);
  ld C = norm(a - b);
  ld S = abs(cross(b - a, c - a));
  P p = (A * (B + C - A) * a + B * (C + A - B) * b + C * (A + B - C) * c) / (4 * S * S);
  ld r = abs(p - a);
  return make_pair(r, p);
};
auto c2 = [](const P &a, const P &b) {
  P c = (a + b) / (ld)2;
  ld r = abs(a - c);
  return make_pair(r, c);
};
auto in_circle = [](const P &a, const C &c) {
  return norm(a - c.pnt) <= c.rad * c.rad + eps;
};

C smallest_enclosing_disc(vector<P> ps) {
  // Replaced random_shuffle() with shuffle()
  shuffle(ps.begin(), ps.end(), std::mt19937{std::random_device{}()});
  C c = c2(ps[0], ps[1]);
  // Unchanged code omitted for brevity
  return c;
}

int main() {
  // Unchanged code omitted for brevity
  rep(i, m) {
    int k;
    cin >> k;
    G g(k);
    rep(j, k) {
      ld x, y;
      cin >> x >> y;
      g[j] = P(x, y);  // Replaced push_back() with direct assignment
    }
    mb[i] = smallest_enclosing_disc(g).rad;
  }
  // Unchanged code omitted for brevity
}