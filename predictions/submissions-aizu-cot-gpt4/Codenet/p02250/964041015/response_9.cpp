#include <bits/stdc++.h>
using namespace std;

class suffix_array {
  //...
  vector<int> sa_is(vector<int> v, int mv) {
    int v_size = v.size();
    if (v_size == 1)
      return vector<int>(1, 0);
    vector<int> is_l(v_size);
    vector<int> bucket(mv + 1);
    vector<int> sa(v_size, -1);
    auto is_lms = [&](int x) -> bool {
      return x > 0 && is_l[x - 1] && !is_l[x];
    };
    is_l[v_size - 1] = 0;
    for (int i = v_size - 2; i >= 0; i--)
      is_l[i] = v[i] > v[i + 1] || (v[i] == v[i + 1] && is_l[i + 1]);
    create_end_bucket(v, bucket);
    vector<int> is_lms_vector(v_size, 0);
    for (int i = 0; i < v_size; i++)
      if (is_lms(i))
        is_lms_vector[i] = 1;
    vector<int> order(v_size);
    vector<int> next_v(v_size);
    vector<int> re_order(v_size);
    vector<int> next_sa(v_size);
    //...
  }
  vector<int> sa_is(string &s) {
    int s_size = s.size();
    vector<int> v(s_size + 1);
    v.reserve(s_size + 1);
    for (int i = 0; i < s_size; i++)
      v[i] = s[i];
    sa = sa_is(v, *max_element(v.begin(), v.end()));
  }
  //...
public:
  //...
  suffix_array(string &t) {
    t.reserve(t.size());
    init(t);
  }
  //...
};

//...