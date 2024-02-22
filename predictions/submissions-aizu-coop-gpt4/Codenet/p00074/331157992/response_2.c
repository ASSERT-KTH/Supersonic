#include <stdio.h>

main(h, m, s, t) {
  int h_div, m_div, s_mod;
  for (; scanf("%d%d%d", &h, &m, &s) * -~h;) {
    t = ((120 << 6) - (h << 6) - m) - s; // convert 120 hours to seconds and subtract input time
    for (h = 2; h--; t = (t << 1) + t) { // multiply time by 3 using shift and addition
      h_div = t >> 6; // divide by 60 using shift
      m_div = (t >> 1) % 60; // divide by 60 using shift and modulo
      s_mod = t % 60;
      printf("%02d:%02d:%02d\n", h_div, m_div, s_mod);
    }
  }
}