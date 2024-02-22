#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

struct item {
    map<string, item> ptr;
    string val;
    bool is_str;
};

bool isalphabet(char ch) {
    return 'a' <= ch and ch <= 'z';
}

bool is_indent_n(string &s, int i, int n) {
    if (n == 0)
        return true;
    if (i == s.size() or s[i] != ' ')
        return false;
    return is_indent_n(s, i + 1, n - 1);
}

void yaml(string &s, int &i, item &itm);
void mapping(string &s, int &i, item &itm, int n);
void mapping_item(string &s, int &i, item &itm, int n);
string key(string &s, int &i);
string string_(string &s, int &i);
void indent(string &s, int &i, int n);

void yaml(string &s, int &i, item &itm) {
    stack<item*> stk;
    stk.push(&itm);
    
    while (!stk.empty()) {
        item* itm_ = stk.top();
        stk.pop();
        
        mapping_item(s, i, *itm_, stk.size());
        
        if (i != s.size() && is_indent_n(s, i, stk.size()))
            stk.push(itm_);
    }
}

void mapping(string &s, int &i, item &itm, int n) {
    while (true) {
        mapping_item(s, i, itm, n);
        if (i == s.size() || !is_indent_n(s, i, n))
            break;
    }
}

void mapping_item(string &s, int &i, item &itm, int n) {
    indent(s, i, n);
    string k = key(s, i);
    
    itm.ptr[k].val = k;
    
    if (s[i] == ':') {
        ++i;
        if (s[i] == ' ') {
            ++i;
            item str;
            str.is_str = true;
            str.val = string_(s, i);
            itm.ptr[k].ptr[k] = str;
            assert(s[i] == '\n');
            ++i;
        } else {
            assert(s[i] == '\n');
            ++i;
            int j = i;
            while (j != s.size() && s[j] == ' ')
                ++j;
            assert(n < j - i);
            mapping(s, i, itm.ptr[k], j - i);
        }
    } else {
        assert(false);
    }
}

string key(string &s, int &i) {
    string res;
    while (isalphabet(s[i]) || isdigit(s[i])) {
        res += s[i];
        ++i;
    }
    return res;
}

string string_(string &s, int &i) {
    string res;
    while (isalphabet(s[i]) || isdigit(s[i]) || s[i] == ' ') {
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
            for (auto& p : itm->ptr) {
                if (!p.second.is_str && p.first == str) {
                    itm = &p.second;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cout << "no such property" << endl;
                return;
            }
            if (idx == qry.size()) {
                item *obj = &itm->ptr[str];
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