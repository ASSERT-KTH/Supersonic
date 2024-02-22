#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SuffixArray {
private:
    string s;
    vector<int> sa, lcp, rank;
    int n;

    void createBeginBucket(int* v, int* bucket) {
        fill(bucket, bucket + n + 1, 0);
        for (int i = 0; i < n; i++)
            bucket[v[i]]++;
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            bucket[i] += sum;
            swap(sum, bucket[i]);
        }
    }

    void createEndBucket(int* v, int* bucket) {
        fill(bucket, bucket + n + 1, 0);
        for (int i = 0; i < n; i++)
            bucket[v[i]]++;
        for (int i = 1; i <= n; i++)
            bucket[i] += bucket[i - 1];
    }

    void inducedSort(int* v, int* sa, int mv, int* bucket, bool* is_l) {
        createBeginBucket(v, bucket);
        for (int i = 0; i < n; i++)
            if (sa[i] > 0 && is_l[sa[i] - 1])
                sa[bucket[v[sa[i] - 1]]++] = sa[i] - 1;
    }

    void invertInducedSort(int* v, int* sa, int mv, int* bucket, bool* is_l) {
        createEndBucket(v, bucket);
        for (int i = n - 1; i >= 0; i--)
            if (sa[i] > 0 && !is_l[sa[i] - 1])
                sa[--bucket[v[sa[i] - 1]]] = sa[i] - 1;
    }

    void saIs(int* v, int mv) {
        if (n == 1) {
            sa = vector<int>(1, 0);
            return;
        }
        vector<bool> is_l(n);
        vector<int> bucket(mv + 1);
        sa = vector<int>(n, -1);
        auto isLms = [&](int x) -> bool {
            return x > 0 && is_l[x - 1] && !is_l[x];
        };
        is_l[n - 1] = false;
        for (int i = n - 2; i >= 0; i--)
            is_l[i] = v[i] > v[i + 1] || (v[i] == v[i + 1] && is_l[i + 1]);
        createEndBucket(v, bucket);
        for (int i = 0; i < n; i++)
            if (isLms(i))
                sa[--bucket[v[i]]] = i;
        inducedSort(v, sa.data(), mv, bucket, is_l.data());
        invertInducedSort(v, sa.data(), mv, bucket, is_l.data());
        int cur = 0;
        vector<int> order(n);
        for (int i = 0; i < n; i++)
            if (isLms(i))
                order[i] = cur++;
        vector<int> next_v(cur);
        cur = -1;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (!isLms(sa[i]))
                continue;
            bool diff = false;
            for (int d = 0; d < n; d++) {
                if (prev == -1 || v[sa[i] + d] != v[prev + d] || is_l[sa[i] + d] != is_l[prev + d]) {
                    diff = true;
                    break;
                }
                else if (d > 0 && isLms(sa[i] + d))
                    break;
            }
            if (diff) {
                cur++;
                prev = sa[i];
            }
            next_v[order[sa[i]]] = cur;
        }
        vector<int> re_order(next_v.size());
        for (int i = 0; i < n; i++)
            if (isLms(i))
                re_order[order[i]] = i;
        vector<int> next_sa = saIs(next_v.data(), cur);
        createEndBucket(v, bucket);
        for (int i = 0; i < n; i++)
            sa[i] = -1;
        for (int i = next_sa.size() - 1; i >= 0; i--)
            sa[--bucket[v[re_order[next_sa[i]]]]] = re_order[next_sa[i]];
        inducedSort(v, sa.data(), mv, bucket, is_l.data());
        invertInducedSort(v, sa.data(), mv, bucket, is_l.data());
    }

    void constructLcp() {
        lcp.resize(n);
        rank.resize(n + 1);
        for (int i = 0; i <= n; i++)
            rank[sa[i]] = i;
        int h = 0;
        lcp[0] = 0;
        for (int i = 0; i < n; i++) {
            int j = sa[rank[i] - 1];
            if (h > 0)
                h--;
            for (; j + h < n && i + h < n; h++) {
                if (s[j + h] != s[i + h])
                    break;
            }
            lcp[rank[i] - 1] = h;
        }
    }

    class SparseTable {
    private:
        vector<vector<int>> st;

    public:
        void init(vector<int>& v) {
            int b = 0;
            for (; (1 << b) < v.size(); b++);
            st.assign(b, vector<int>(1 << b));
            for (int i = 0; i < v.size(); i++)
                st[0][i] = v[i];