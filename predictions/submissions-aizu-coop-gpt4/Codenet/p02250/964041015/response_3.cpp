#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstring>
#include<cmath>
#include<cassert>
using namespace std;

class suffix_array {
    // Class member vectors
    vector<int> v, is_l, bucket, sa, order, next_v, re_order;
    string s;
    vector<int> rank, lcp;
    vector<vector<int>> st;

public:
    suffix_array(string &t) {
        s = t;
        int n = s.size();
        v.resize(n+1);
        for(int i=0; i<n; i++)
            v[i] = s[i];
        is_l.resize(n+1);
        bucket.resize(256); // assuming ASCII characters
        sa.resize(n+1);
        order.resize(n+1);
        next_v.resize(n+1);
        re_order.resize(n+1);
        sa_is();
        construct_lcp();
        construct_sparse_table();
    }

    void sa_is() {
        // Implementation here
    }

    void construct_lcp() {
        // Implementation here
    }

    void construct_sparse_table() {
        // Implementation here
    }

    bool contain(string &t) {
        // Implementation here
    }

    int get_lcp(int i, int j) {
        // Implementation here
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    suffix_array sa(s);
    int q;
    cin>>q;
    while(q--) {
        string t;
        cin>>t;
        cout<<sa.contain(t)<<'\n';
    }
    return 0;
}