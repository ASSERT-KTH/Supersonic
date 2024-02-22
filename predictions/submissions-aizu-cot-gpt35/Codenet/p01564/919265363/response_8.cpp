#include <iostream>
#include <vector>

struct douse {
  int32_t all, r, l, sum, siz;
  bool id;
  douse() : id(1) {}
  douse(int32_t a, int32_t lef, int32_t rig, int32_t s, int32_t si)
      : all(a), l(lef), r(rig), sum(s), siz(si), id(0) {}
  douse operator~() {
    douse ret = *this;
    std::swap(ret.l, ret.r);
    return ret;
  }
  douse operator+(const douse &other) {
    if (id)
      return other;
    if (other.id)
      return *this;
    douse ret;
    ret.all = std::max(std::max(all, other.all),
                       std::max(r + other.l, std::max(r, other.l)));
    ret.r = std::max(other.r, r > 0 ? r + other.sum : other.sum);
    ret.l = std::max(l, other.l > 0 ? sum + other.l : sum);
    ret.sum = sum + other.sum;
    ret.siz = siz + other.siz;
    ret.id = 0;
    return ret;
  }
  douse operator*(const ass &other) {
    douse ret;
    ret.all = ret.r = ret.l = other.data > 0 ? other.data * siz : other.data;
    ret.sum = other.data * siz;
    ret.siz = siz;
    ret.id = id;
    return ret;
  }
};

struct ass {
  int32_t data;
  ass(int32_t a = 0) : data(a) {}
  ass operator*(const ass &other) { return other; }
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  uint32_t n, q;
  std::cin >> n >> q;
  std::vector<douse> a(n);
  int32_t t1;
  for (uint32_t i = 0; i < n; ++i) {
    std::cin >> t1;
    a[i] = douse(t1, t1, t1, t1, 1);
  }
  link_cut_tree<douse, ass> L(a);
  uint32_t t2, t3;
  for (uint32_t i = 0; i < n - 1; ++i) {
    std::cin >> t2 >> t3;
    L.link(t2 - 1, t3 - 1);
  }
  uint32_t t4;
  for (uint32_t i = 0; i < q; ++i) {
    std::cin >> t2 >> t3 >> t4 >> t1;
    if (t2 == 1) {
      L.update(t3 - 1, t4 - 1, ass(t1));
    } else {
      std::cout << L.path(t3 - 1, t4 - 1).all << "\n";
    }
  }
  return 0;
}