#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
using ld=long double;
ll inf=10010010010010010;
ll mod=998244353;
vector<ll> lcs(vector<ll> &A, vector<ll> &B){
	vector<vector<ll>> dp(A.size() + 1, vector<ll>(B.size() + 1, 0));
	for (ll i = 0; i < A.size(); i++){
		for (ll j = 0; j < B.size(); j++){
			if (A[i] == B[j]){
				dp[i + 1][j + 1] = dp[i][j] + 1;
			} else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
    vector<ll>ans;
	ll i = A.size();
	ll j = B.size();
	while (dp[i][j] > 0){
		if (dp[i - 1][j] == dp[i][j]){
			i--;
		} else if (dp[i][j - 1] == dp[i][j]){
			j--;
		} else {
			i--;
			j--;
			ans.push_back(A[i]);
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main(){
  string s, t;
  cin >> s >> t;
  vector<ll> S(s.begin(), s.end()), T(t.begin(), t.end());
  vector<ll> C = lcs(S, T);
  string c(C.begin(), C.end());
  cout << c;
}