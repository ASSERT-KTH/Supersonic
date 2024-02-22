#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

struct item {
    vector<item*> ptr;
    string val;
    bool is_str;
};

bool isalphabet(char ch) {
    return 'a' <= ch and ch <= 'z';
}

string key(string &s, int &i) {
    string res;
    while (isalphabet(s[i]) or isdigit(s[i])) {
        res += s[i];
        ++i;
    }
    return res;
}

string string_(string &s, int &i) {
    string res;
    while (isalphabet(s[i]) or isdigit(s[i]) or s[i] == ' ') {
        res += s[i];
        ++i;
    }
    return res;
}

void indent(string &s, int &i, int n) {
    while (n > 0) {
        assert(s[i] == ' ');
        ++i;
        --n;
    }
}

void yaml(string &s, int &i, item &itm) {
    while (i < s.size()) {
        item* itm_ = new item();
        itm_->val = key(s, i);
        itm.ptr.push_back(itm_);

        assert(i < s.size());
        assert(s[i] == ':');
        ++i;

        if (s[i] == ' ') {
            ++i;
            item* str = new item();
            str->is_str = true;
            str->val = string_(s, i);
            itm_->ptr.push_back(str);
            assert(s[i] == '\n');
            ++i;
        } else {
            assert(s[i] == '\n');
            ++i;
            int j = i;
            while (j != s.size() and s[j] == ' ')
                ++j;
            int n = j - i;
            yaml(s, i, *itm_);
            indent(s, i, n);
        }
    }
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
        item* itm = &root;
        int idx = 1;
        while (true) {
            string str = string_(qry, idx);
            bool ok = false;
            for (item* i : itm->ptr) {
                if (!i->is_str and i->val == str) {
                    itm = i;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cout << "no such property" << endl;
                return;
            }
            if (idx == qry.size()) {
                item* obj = itm->ptr.front();
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
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}