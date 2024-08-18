#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
using ld=long double;
ld pie=3.14159265359;
ll inf=10010010010010010;
ll mod=998244353;
struct unionfind
{
    vector<ll>par,siz;
    unionfind(ll n): par(n,-1),siz(n,1){}
    ll root(ll x){
        if (par[x]==-1)
        {
            return x;
        }else{
            return par[x]=root(par[x]);
        }
    }
    bool issame(ll x,ll y){
        return root(x)==root(y);
    }
    bool unite(ll x,ll y){
        x=root(x);
        y=root(y);
        if (x==y)
        {
            return false;
        }
        if (siz[x]<siz[y])
        {
            swap(x,y);
        }
        par[y]=x;
        siz[x]+=siz[y];
        return true;
    }
    ll size(ll x){
        return siz[root(x)];
    }
};