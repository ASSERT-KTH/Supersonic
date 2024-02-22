struct Edge {
  int u, v;
  double w;
  Edge() {}
  Edge(int _u, int _v, double _w) : u(_u), v(_v), w(_w) {}
  bool operator<(const Edge &other) const { return w < other.w; }
};