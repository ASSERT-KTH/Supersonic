#include <iostream>
#include <string>

template <template <typename> class Parser, typename T>
struct ParserImpl {
    using State = typename std::string::const_iterator;
  
    T solve(const std::string& S) {
        State begin = S.begin();
        return equation(begin);
    }
  
    T equation(State& begin) {
        T left = formula(begin);
        ++begin;
        T right = formula(begin);
        return left == right;
    }
  
    T formula(State& begin) {
        if (*begin == '(') {
            ++begin;
            T left = formula(begin);
            char op = *begin;
            ++begin;
            if (op == '-')
                ++begin;
            T right = formula(begin);
            ++begin;
            return deduce(left, op, right);
        } else if (*begin == '-') {
            ++begin;
            return !formula(begin);
        } else {
            return boolean(begin);
        }
    }
  
    T deduce(T x, char op, T y) {
        if (op == '*') {
            return x && y;
        } else if (op == '+') {
            return x || y;
        } else {
            return !x || y;
        }
    }
  
    T boolean(State& begin) {
        if (*begin == 'T')
            return true;
        else if (*begin == 'F')
            return false;
        else
            return (mask >> (*begin - 'a')) & 1;
    }
};

void solve(const std::string& S) {
    ParserImpl<Parser, bool> ps;
    for (int mask = 0; mask < (1 << 11); ++mask) {
        if (!ps.solve(S)) {
            std::cout << "NO" << std::endl;
            return;
        }
    }
    std::cout << "YES" << std::endl;
}

int main() {
    std::string S;
    while (std::cin >> S && S != "#") {
        solve(S);
    }
    return 0;
}