#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;
int main() {
    ll n,q;cin >> n >> q;
    vector<ll> c(n),l(q),r(q),idx(q),ans(q);
    vector<ll>cnt(200001,0);
    ll sq = sqrt(q), count = 0, now_l = 0, now_r = 0;
    for (ll i = 0; i < n; i++) { scanf("%d",&c[i]); c[i]--; }
    for (ll i = 0; i < q; i++) { scanf("%d %d",&l[i], &r[i]); l[i]--; }
    iota(idx.begin(), idx.end(),0);
    sort(idx.begin(), idx.end(), [&](ll a,ll b){
        if (l[a]/sq != l[b]/sq) return l[a] < l[b];
        if (l[a]/sq % 2 == 1) return r[a] > r[b];
        return r[a] < r[b];
    });
    auto add = [&](ll x) {
        cnt[c[x]]++;
        if (cnt[c[x]]==1)
        {
            count+=1;
        }
    };
    auto del = [&](ll x) {
        cnt[c[x]]--;
        if (cnt[c[x]]==0)
        {
            count-=1;
        }
    };
    for (ll i = 0; i < q; i++) {
        while(now_l > l[idx[i]]) add(--now_l);
        while(now_r < r[idx[i]]) add(now_r++);
        while(now_l < l[idx[i]]) del(now_l++);
        while(now_r > r[idx[i]]) del(--now_r);
        ans[idx[i]] = count;
    }
    for (ll i = 0; i < q; i++) cout << ans[i] << endl;
    return 0;
}