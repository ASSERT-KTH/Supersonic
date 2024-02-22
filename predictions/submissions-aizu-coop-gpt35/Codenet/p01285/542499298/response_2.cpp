// Before
double abs(Point a) { return sqrt(norm(a)); }

// After
double distance(Point a) { return sqrt(a.x * a.x + a.y * a.y); }