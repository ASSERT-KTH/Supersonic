#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class suffix_array {
public:
	string s;
	vector<int> sa, lcp, rank;

	suffix_array(string &t) 
	: s(t) {
		sa_is(s);
		construct_lcp();
	}

	bool contain(string &t) {
		int lb = 0, ub = s.size();
		while (ub - lb > 1) {
			int mid = (lb + ub) >> 1;
			if (s.compare(sa[mid], t.size(), t) < 0) lb = mid;
			else ub = mid;
		}
		return s.compare(sa[ub], t.size(), t) == 0;
	}

private:
	void sa_is(string &s) {
		vector<int> v(s.size() + 1);
		for (size_t i = 0; i < s.size(); i++) v[i] = s[i];
		sa = sa_is(v, *max_element(v.begin(), v.end()));
	}

	vector<int> sa_is(vector<int> v, int mv) {
		int n = v.size();
		vector<int> is_l(n), bucket(mv + 1), sa(n, -1), order(n);
		auto is_lms = [&](int x) -> bool {
			return x > 0 && is_l[x - 1] && !is_l[x];
		};

		is_l[n - 1] = 0;
		for (int i = n - 2; i >= 0; i--) is_l[i] = v[i] > v[i + 1] || (v[i] == v[i + 1] && is_l[i + 1]);
		for (int i = 0; i < n; i++) if (is_lms(i)) sa[--bucket[v[i]]] = i;
		induced_sort(v, sa, bucket, is_l);
		invert_induced_sort(v, sa, bucket, is_l);

		int cur = 0;
		for (int i = 0; i < n; i++) if (is_lms(i)) order[i] = cur++;
		vector<int> next_v(cur), re_order(cur);
		cur = -1;
		int prev = -1;
		for (int i = 0; i < n; i++) {
			if (!is_lms(sa[i])) continue;
			bool diff = false;
			for (int d = 0; d < n; d++) {
				if (prev == -1 || v[sa[i] + d] != v[prev + d] || is_l[sa[i] + d] != is_l[prev + d]) {
					diff = true;
					break;
				} else if (d > 0 && is_lms(sa[i] + d)) break;
			}
			if (diff) {
				cur++;
				prev = sa[i];
			}
			next_v[order[sa[i]]] = cur;
		}
		for (int i = 0; i < n; i++) if (is_lms(i)) re_order[order[i]] = i;
		vector<int> next_sa = sa_is(next_v, cur);

		fill(sa.begin(), sa.end(), -1);
		for (int i = next_sa.size() - 1; i >= 0; i--) sa[--bucket[v[re_order[next_sa[i]]]]] = re_order[next_sa[i]];
		induced_sort(v, sa, bucket, is_l);
		invert_induced_sort(v, sa, bucket, is_l);
		return sa;
	}

	void induced_sort(vector<int> &v, vector<int> &sa, vector<int> &bucket, vector<int> &is_l) {
		fill(bucket.begin(), bucket.end(), 0);
		for (auto &x : v) bucket[x]++;
		int sum = 0;
		for (auto &x : bucket) {
			x += sum;
			swap(sum, x);
		}
		vector<int> temp_sa(sa.size());
		for (int i = 0; i < sa.size(); i++) if (sa[i] > 0 && is_l[sa[i] - 1]) temp_sa[bucket[v[sa[i] - 1]]++] = sa[i] - 1;
		sa = move(temp_sa);
	}

	void invert_induced_sort(vector<int> &v, vector<int> &sa, vector<int> &bucket, vector<int> &is_l) {
		fill(bucket.begin(), bucket.end(), 0);
		for (auto &x : v) bucket[x]++;
		for (int i = 1; i < bucket.size(); i++) bucket[i] += bucket[i - 1];
		vector<int> temp_sa(sa.size());
		for (int i = sa.size() - 1; i >= 0; i--) if (sa[i] > 0 && !is_l[sa[i] - 1]) temp_sa[--bucket[v[sa[i] - 1]]] = sa[i] - 1;
		sa = move(temp_sa);
	}

	void construct_lcp() {
		int n = s.size();
		rank.resize(n + 1);
		lcp.resize(n);
		for (int i = 0; i <= n; i++) rank[sa[i]] = i;
		int h = 0;
		lcp[0] = 0;
		for (int i = 0; i < n; i++) {
			int j = sa[rank[i] - 1];
			if (h > 0) h--;
			for (; j + h < n && i + h < n; h++) if (s[j + h] != s[i + h]) break;
			lcp[rank[i] - 1] = h;
		}
	}
};

int main() {
	string s;
	cin >> s;
	suffix_array sa(s);
	int q;
	cin >> q;
	while (q--) {
		string t;
		cin >> t;
		cout << sa.contain(t) << '\n';
	}
	return 0;
}