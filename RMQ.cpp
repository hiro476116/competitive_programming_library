#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll inf=1001001001001001;
ll mod=1000000007;
ll n;
vector<ll>segtree((1<<18)-1);
void init(ll nn){
    n=1;
    while (n<nn)
    {
        n*=2;
    }
    for (ll i = 0; i < 2*n-1; i++)
    {
        segtree[i]=inf;
    }
}
void update(ll k,ll a){
    k+=n-1;//最下段にいくため
    segtree[k]=a;
    while (k>0)
    {
        k=(k-1)/2;
        segtree[k]=min(segtree[k*2+1],segtree[2*k+2]);
    }
}
ll query(ll a,ll b,ll k,ll l, ll r){
    if (r<=a||b<=l)
    {
        return inf;
    }
    if (a<=l&&b>=r)
    {
        return segtree[k];
    }else{
        ll vl=query(a,b,2+k+1,l,(l+r)/2);
        ll vr=query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
}