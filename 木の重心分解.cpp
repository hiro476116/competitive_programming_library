#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
using ld=long double;
ld pie=3.141592653589793;
ll inf=1444440099999944;
ll mod=1000000007;
vector<int> Centroid(const vector<vector<int>> &g) {
        int n = g.size();
        vector<int> centroid;
        vector<int> sz(n);
        function<void (int, int)> dfs = [&](int u, int prev) {
                sz[u] = 1;
                bool is_centroid = true;
                for (auto v : g[u]) if (v != prev) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        if (sz[v] > n / 2) is_centroid = false;
                }
                if (n - sz[u] > n / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
        dfs(0, -1);
        return centroid;
}