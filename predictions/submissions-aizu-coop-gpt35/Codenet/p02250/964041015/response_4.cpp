#include <bits/stdc++.h>
using namespace std;

vector<int> create_begin_bucket(vector<int>& v) {
    int mv = *max_element(v.begin(), v.end());
    vector<int> bucket(mv + 1, 0);
    for (int i = 0; i < v.size(); i++)
        bucket[v[i]]++;
    int sum = 0;
    for (int i = 0; i < bucket.size(); i++) {
        bucket[i] += sum;
        sum = bucket[i];
    }
    return bucket;
}

vector<int> create_end_bucket(vector<int>& v) {
    int mv = *max_element(v.begin(), v.end());
    vector<int> bucket(mv + 1, 0);
    for (int i = 0; i < v.size(); i++)
        bucket[v[i]]++;
    for (int i = 1; i < bucket.size(); i++)
        bucket[i] += bucket[i - 1];
    return bucket;
}

void induced_sort(vector<int>& v, vector<int>& sa, int mv, vector<int>& bucket, vector<int>& is_l) {
    bucket = create_begin_bucket(v);
    for (int i = 0; i < v.size(); i++)
        if (sa[i] > 0 && is_l[sa[i] - 1])
            sa[bucket[v[sa[i] - 1]]++] = sa[i] - 1;
}

void invert_induced_sort(vector<int>& v, vector<int>& sa, int mv, vector<int>& bucket, vector<int>& is_l) {
    bucket = create_end_bucket(v);
    for (int i = v.size() - 1; i >= 0; i--)
        if (sa[i] > 0 && !is_l[sa[i] - 1])
            sa[--bucket[v[sa[i] - 1]]] = sa[i] - 1;
}

vector<int> sa_is(vector<int> v, int mv) {
    if (v.size() == 1)
        return vector<int>(1, 0);
    vector<int> is_l(v.size());
    vector<int> sa(v.size(), -1);

    auto is_lms = [&](int x) -> bool {
        return x > 0 && is_l[x - 1] && !is_l[x];
    };

    is_l[v.size() - 1] = 0;
    for (int i = v.size() - 2; i >= 0; i--)
        is_l[i] = v[i] > v[i + 1] || (v[i] == v[i + 1] && is_l[i + 1]);

    vector<int> bucket = create_end_bucket(v);
    for (int i = 0; i < v.size(); i++)
        if (is_lms(i))
            sa[--bucket[v[i]]] = i;

    induced_sort(v, sa, mv, bucket, is_l);
    invert_induced_sort(v, sa, mv, bucket, is_l);

    int cur = 0;
    vector<int> order(v.size());
    for (int i = 0; i < v.size(); i++)
        if (is_lms(i))
            order[i] = cur++;

    vector<int> next_v(cur);
    cur = -1;
    int prev = -1;
    for (int i = 0; i < v.size(); i++) {
        if (!is_lms(sa[i]))
            continue;
        bool diff = false;
        for (int d = 0; d < v.size(); d++) {
            if (prev == -1 || v[sa[i] + d] != v[prev + d] || is_l[sa[i] + d] != is_l[prev + d]) {
                diff = true;
                break;
            }
            else if (d > 0 && is_lms(sa[i] + d))
                break;
        }
        if (diff) {
            cur++;
            prev = sa[i];
        }
        next_v[order[sa[i]]] = cur;
    }

    vector<int> re_order(next_v.size());
    for (int i = 0; i < v.size(); i++)
        if (is_lms(i))
            re_order[order[i]] = i;

    vector<int> next_sa = sa_is(next_v, cur);
    bucket = create_end_bucket(v);
    for (int i = 0; i < sa.size(); i++)
        sa[i] = -1;
    for (int i = next_sa.size() - 1; i >= 0; i--)
        sa[--bucket[v[re_order[next_sa[i]]]]] = re_order[next_sa[i]];

    induced_sort(v, sa, mv, bucket, is_l);
    invert_induced_sort(v, sa, mv, bucket, is_l);

    return sa;
}

vector<int> construct_lcp(string& s, vector<int>& sa) {
    int n = s.size();
    vector<int> lcp(n, 0);
    vector<int> rank(n + 1);
    for (int i = 0; i <= n; i++)
        rank[sa[i]] = i;
    int h = 0;
    for (int i = 0; i < n; i++) {
        int j = sa[rank[i] - 1];