t = a[(begin & ~0x1F) |
      __builtin_ctz(L[begin >> 5] & bitmaskr[begin & 0x1F])];
return std::min(
    a[(end & ~0x1F) |
      (31 ^ __builtin_clz(R[end >> 5] & bitmaskl[end & 0x1F]))],
    t);