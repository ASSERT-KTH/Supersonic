#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct item {
    map<string, item> ptr;
    string val;
    bool is_str;
};

void yaml(string &s, int &i, item &itm);
void mapping(string &s, int &i, item &itm, int n);
void mapping_item(string &s, int &i, item &itm, int n);

void yaml(string &s, int &i, item &itm) {
    mapping(s, i, itm, 0);
}

void mapping(string &s, int &i, item &itm, int n) {
    mapping_item(s, i, itm, n);
    if (i < s.size() && s[i] == ' ') {
        mapping(s, i, itm, n);
    }
}

void mapping_item(string &s, int &i, item &itm, int n) {
    while (n != 0) {
        assert(i < s.size());
        assert(s[i] == ' ');
        ++i;
        --n;
    }

    assert(i < s.size());
    itm.val = key(s, i);
    ++i;

    if (i < s.size() && s[i] == ' ') {
        ++i;
        itm.ptr[""] = string_(s, i);
        assert(i < s.size());
        assert(s[i] == '\n');
        ++i;
    } else {
        assert(i < s.size());
        assert(s[i] == '\n');
        ++i;
        int j = i;
        while (j != s.size() && s[j] == ' ') {
            ++j;
        }
        mapping(s, i, itm.ptr[itm.val], j - i);
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
            auto it = itm->ptr.find(str);
            if (it == itm->ptr.end() || it->second.is_str) {
                cout << "no such property" << endl;
                return;
            }
            itm = &it->second;
            if (idx == qry.size()) {
                cout << "object" << endl;
                return;
            }
            ++idx;
        }
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}