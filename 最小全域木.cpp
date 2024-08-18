#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
using ld=long double;
ll inf=10010010010010010;
ll mod=1000000007;
struct unionfind
{
    vector<int>par,siz;
    unionfind(int n): par(n,-1),siz(n,1){}
    int root(int x){
        if (par[x]==-1)
        {
            return x;
        }else{
            return par[x]=root(par[x]);
        }
    }
    bool issame(int x,int y){
        return root(x)==root(y);
    }
    bool unite(int x,int y){
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
    int size(int x){
        return siz[root(x)];
    }
};
ll main(){
    ll n,m,q;
    cin >> n >> m >> q;
    vector<pair<ll,pair<ll,ll> > >g(m+1);
    for (int i = 0; i < m; i++)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        g[i]=pair(c,make_pair(a,b));
    }
    map<pair<ll,pair<ll,ll>>,ll >me;
    vector<ll>uu(q+1),vv(q+1),ww(q+1);
    for (ll i = 1; i <=q; i++)
    {
        cin >> uu[i] >> vv[i] >> ww[i];
        g.push_back(make_pair(ww[i],make_pair(uu[i],vv[i])));
        me[make_pair(ww[i],make_pair(uu[i],vv[i]))]=i;
    }
    ll res=0;
    unionfind uf(n+1);
    sort(g.begin(),g.end());
    vector<ll>ans(q+1,0);
    for (ll i = 1; i < g.size(); i++)
    {
        ll w=g[i].first;
        ll u=g[i].second.first;
        ll v=g[i].second.second;
        if (uf.issame(u,v))
        {
            continue;
        }
        res+=w;
        if (me[make_pair(w,make_pair(u,v))]>=1)
        {
            ans[me[make_pair(w,make_pair(u,v))]]+=1;
            continue;
        }
        uf.unite(u,v);
    }
    for (int i = 1; i <=q; i++)
    {
        if (ans[me[make_pair(ww[i],make_pair(uu[i],vv[i]))]]>=1)
        {
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}