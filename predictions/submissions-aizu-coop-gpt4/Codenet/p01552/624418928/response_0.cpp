// Use ostringstream instead of string for concatenation
std::ostringstream yaml_str;
{
    string buf;
    while (getline(cin, buf)) {
        yaml_str << buf << '\n';
    }
}

// Replace recursion with iteration in the indent function
void indent(string &s, int &i, int n) {
    for (int j = 0; j < n; ++j) {
        assert(s[i] == ' ');
        ++i;
    }
}

// Use unique_ptr instead of raw pointers
std::unique_ptr<item> itm_ = std::make_unique<item>();
itm_->val = key(s, i);
itm.ptr.push_back(std::move(itm_));