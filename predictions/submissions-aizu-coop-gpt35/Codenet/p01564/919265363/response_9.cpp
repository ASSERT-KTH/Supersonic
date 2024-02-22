#include <cstdint>
#include <iostream>
#include <vector>

using int32 = std::int_fast32_t;
using intl32 = std::int_least32_t;

struct ass {
  intl32 data;
  ass(intl32 a = 0) : data(a) {}
  ass operator*(const ass &other) { return other; }
};

struct douse {
  intl32 all, r, l, sum, siz;
  bool id;
  douse() : id(1) {}
  douse(int32 a, int32 lef, int32 rig, int32 s, int32 si)
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

template <uint32_t Size> class link_cut_tree {
  struct node_t {
    uint32_t left, right, per;
    douse value, sum;
    ass lazy;
    uint8_t b;
    node_t()
        : left(Size), right(Size), per(Size), value(douse()), sum(douse()),
          b(0) {}
    inline bool isroot() { return !(b & 4); }
    douse reflect() {
      if (b & 1) {
        if (b & 2)
          return ~(sum * lazy);
        return sum * lazy;
      }
      if (b & 2)
        return ~sum;
      return sum;
    }
    void assign(ass &data) {
      if (b & 1)
        lazy = lazy * data;
      else {
        lazy = data;
        b |= 1;
      }
    }
    void push(node_t *tree) {
      if (b & 2) {
        std::swap(left, right);
        tree[left].b ^= 2;
        tree[right].b ^= 2;