#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
using ld=long double;
ld pie=3.14159265359;
ll inf=80010010;
ll mod=1000000007;
template<class T> struct Partition {
    vector<vector<T> > P;
    constexpr Partition(int MAX) noexcept : P(MAX, vector<T>(101, 0)) {
        for (int k = 0; k < 101; ++k) P[0][k] = 1;
        for (int n = 1; n < MAX; ++n) {
            for (int k = 1; k < 101; ++k) {
                P[n][k] = (P[n][k-1] + (n-k >= 0 ? P[n-k][k] : 0))%mod;
            }
        }
    }
    constexpr T get(int n, int k) {
        if (n < 0 || k < 0) return 0;
        return P[n][k];
    }
};