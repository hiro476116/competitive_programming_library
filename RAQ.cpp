#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll=long long;
using ld=long double;
using mint = modint998244353;
ll inf=999999999999999;
ll mod=998244353;
//a[i]>b*a[i]+cに移す
pair<mint,ll>op(pair<mint,ll>a,pair<mint,ll>b){
    return make_pair((a.first+b.first),a.second+b.second);
}
pair<mint,ll>e(){
    return make_pair(0,0);
}
pair<mint,ll>mapping(pair<mint,mint>f,pair<mint,ll>r){
    return make_pair((r.first*f.first+r.second*f.second),r.second);
}
pair<mint,mint>composition(pair<mint,mint>f,pair<mint,mint>g){
    return make_pair(g.first*f.first,f.first*g.second+f.second);
}
pair<mint,mint>id(){
    return make_pair(1,0);
}
int main(){
    ll n,q;
    cin >> n >> q;
    vector<pair<mint,ll>>a(n,make_pair(0,1));
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[i].first=x;
    }
    lazy_segtree<pair<mint,ll>,op,e,pair<mint,mint>,mapping,composition,id>seg(a);
    vector<mint>ans;
    for (ll i = 0; i < q; i++)
    {
        ll t;
        cin >> t;
        if (t==0)
        {
            ll l,r,b,c;
            cin >> l >> r >> b >> c;
            seg.apply(l,r,pair<mint,mint>(b,c));
        }else{
            ll l,r;
            cin >> l >> r;
            ans.push_back(seg.prod(l,r).first);
        }
    }
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i].val() << endl;
    }
    
}