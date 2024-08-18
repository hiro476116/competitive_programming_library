#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
ld pie=3.141592653589793;
ll mod=998244353;
ld inf=10000999999999900;
vector<ll>ss(vector<ll>a){
    ll n=a.size();
    if (n==1)
    {
        return a;
    }
    vector<ll>mae;
    for (ll i = 0; i < n/2; i++)
    {
        mae.push_back(a[i]);
    }
    vector<ll>b=ss(mae);
    vector<ll>ato;
    for (ll i = n/2; i < n; i++)
    {
        ato.push_back(a[i]);
    }
    vector<ll>c=ss(ato);
    ll mnow=0,anow=0;
    vector<ll>d;
    b.push_back(inf);
    c.push_back(inf);
    for (ll i = 0; i < n; i++)
    {
        if (b[mnow]<=c[anow])
        {
            d.push_back(b[mnow]);
            mnow++;
        }else{
            d.push_back(c[anow]);
            anow++;
        }
    }
    return d;
}
