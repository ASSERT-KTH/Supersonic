#include <algorithm>
#include <array>
#include <climits>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <type_traits>
#include <utility>
#include <vector>

// ... (Keep the rest of the code as is until...)

struct douse {
  // ... (Keep the rest of the code as is until...)

  douse operator*(const ass &other) {
    douse ret;
    ret.siz = siz;
    ret.sum = other.data * ret.siz;
    ret.all = ret.r = ret.l = other.data > 0 ? ret.sum : other.data;
    ret.id = id;
    return ret;
  }
};

// ... (Keep the rest of the code as is until...)

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  // ... (Keep the rest of the code as is until...)
}