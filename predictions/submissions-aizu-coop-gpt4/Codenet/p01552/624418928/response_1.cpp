#include <bits/stdc++.h>
using namespace std;

struct item {
    unordered_map<string, item*> ptr;
    string val;
    bool is_str;
};

bool is_indent_n(string &s, int i, int n) {
    for (int j = 0; j < n; j++) {
        if (i == s.size() || s[i] != ' ')
            return false;
        i++;
    }
    return true;
}

void yaml(string &s, int &i, item &itm);
void mapping(string &s, int &i, item &itm, int n);
void mapping_item(string &s, int &i, item &itm, int n);
string key(string &s, int &i);
string string_(string &s, int &i);

void yaml(string &s, int &i, item &itm) { mapping(s, i, itm, 0); }

void mapping(string &s, int &i, item &itm, int n) {
    while (i != s.size() && is_indent_n(s, i, n)) {
        mapping_item(s, i, itm, n);
    }
}

void mapping_item(string &s, int &i, item &itm, int n) {
    for (int j = 0; j < n; j++, i++) assert(s[i] == ' ');
    item *itm_ = new item();
    itm_->val = key(s, i);
    itm.ptr[itm_->val] = itm_;
    assert(i < s.size() && s[i] == ':');
    ++i;
    if (s[i] == ' ') {
        ++i;
        item *str = new item();
        str->is_str = true;
        str->val = string_(s, i);
        itm_->ptr["value"] = str;
        assert(s[i] == '\n');
        ++i;
    } else {
        assert(s[i] == '\n');
        ++i;
        int j = i;
        while (j != s.size() && s[j] == ' ')
            ++j;
        assert(n < j - i);
        mapping(s, i, *itm_, j - i);
    }
}

string key(string &s, int &i) {
    string res;
    while (isalpha(s[i]) || isdigit(s[i])) {
        res += s[i];
        ++i;
    }
    return res;
}

string string_(string &s, int &i) {
    string res;
    while (isalpha(s[i]) || isdigit(s[i]) || s[i] == ' ') {
        res += s[i];
        ++i;
    }
    return res;
}

void solve() {
    string qry, yaml_str;
    cin >> qry;
    cin.ignore();
    {
        string buf;
        while (getline(cin, buf)) {
            yaml_str += buf;
            yaml_str += '\n';
        }
    }
    item root;
    root.val = "root";
    {
        int idx = 0;
        yaml(yaml_str, idx, root);
    }
    {
        item *itm = &root;
        int idx = 1;
        while (true) {
            string str = string_(qry, idx);
            if (itm->ptr.count(str) == 0) {
                cout << "no such property" << endl;
                return;
            }
            itm = itm->ptr[str];
            if (idx == qry.size()) {
                if (itm->ptr.count("value") && itm->ptr["value"]->is_str)
                    cout << "string \"" << itm->ptr["value"]->val << "\"" << endl;
                else
                    cout << "object" << endl;
                return;
            }
            ++idx;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}