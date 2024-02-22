// Include Eigen library
#include <Eigen/Dense>
using namespace Eigen;

// Use Eigen's Matrix class instead of vector<vector<ll>>
using mat = Matrix<ll, Dynamic, Dynamic>;

// Use Eigen's matrix multiplication
mat mul(const mat &A, const mat &B) {
    return A * B;
}

// Use binary exponentiation to compute matrix power
mat mat_pow(const mat &A, ll x) {
    int n = A.rows();
    mat ret = Matrix<ll, Dynamic, Dynamic>::Identity(n, n);
    mat P = A;
    while (x) {
        if (x & 1)
            ret = mul(ret, P);
        P = mul(P, P);
        x >>= 1;
    }
    return ret;
}

// Rest of the code remains the same...