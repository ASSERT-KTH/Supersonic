#include <bits/stdc++.h>
using namespace std;

struct item {
    unordered_map<string, item*> ptr;
    string val;
    bool is_str;
};

void yaml(string &s, int &i, item &itm);
void mapping(string &s, int &i, item &itm);
void mapping_item(string &s, int &i, item &itm);
string key(string &s, int &i);
string string_(string &s, int &i);

void yaml(string &s, int &i, item &itm) {
    mapping(s, i, itm);
}

void mapping(string &s, int &i, item &itm) {
    mapping_item(s, i, itm);
    while (i != s.size() && s[i] == '\n') {
        ++i;
        int j = i;
        while (j != s.size() && s[j] == ' ')
            ++j;
        if (j - i <= 0)
            continue;
        mapping(s, i, *itm->ptr[key(s, i)]);
    }
}

void mapping_item(string &s, int &i, item &itm) {
    itm->val = key(s, i);
    assert(s[i] == ':');
    ++i;
    if (s[i] == ' ') {
        ++i;
        item *str = new item();
        str->is_str = true;
        str->val = string_(s, i);
        itm->ptr["value"] = str;
    } else {
        int j = i;
        while (j != s.size() && s[j] == ' ')
            ++j;
        mapping(s, i, *new item(), j - i);
        itm->ptr["value"] = &*new item();
        *itm->ptr["value"] = *new item(*itm->ptr[key(s, i)]);
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
            bool ok = false;
            if (itm->ptr.find(str) != itm->ptr.end() && !itm->ptr[str]->is_str) {
                itm = itm->ptr[str];
                ok = true;
            }
            if (!ok) {
                cout << "no such property" << endl;
                return;
            }
            if (idx == qry.size()) {
                item *obj = itm->ptr["value"];
                if (obj->is_str)
                    cout << "string \"" << obj->val << "\"" << endl;
                else
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