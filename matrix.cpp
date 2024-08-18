#include <bits/stdc++.h>
using namespace std;
using ll =long long;
ll mod=998244353;
/// 行列積
vector<vector<ll>> mat_mul(vector<vector<ll>> &a, vector<vector<ll>> &b) {
  vector<vector<ll>> res(a.size(), vector<ll>(b[0].size()));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b[0].size(); j++) {
      for (int k = 0; k < b.size(); k++) {
        (res[i][j] += a[i][k] * b[k][j])%=mod;
      }
    }
  }
  return res;
}

/// 行列累乗
vector<vector<ll>> mat_pow(vector<vector<ll>> a, long long n) {
  vector<vector<ll>> res(a.size(), vector<ll>(a.size()));
  // 単位行列で初期化
  for (int i = 0; i < a.size(); i++)
    res[i][i] = 1;
  // 繰り返し二乗法
  while (n > 0) {
    if (n & 1) res = mat_mul(a, res);
    a = mat_mul(a, a);
    n >>= 1;
  }
  return res;
}

signed main()
{
  ll n;
  cin >> n;
  
  // フィボナッチ数列の行列累乗
  vector<vector<ll>> m(2, vector<ll>(2));
  m[0][0] = m[0][1] = m[1][0] = 1;
  m[1][1] = 0;
  m = mat_pow(m, n);
  ll ans = m[1][0];
  cout << ans << endl;
}