#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll=long long;
using ld=long double;
ld pie=3.14159265359;
ll mod=1000000007;
ll inf=99999999999999999;
vector<vector<ll>>mul(vector<vector<ll>>&a,vector<vector<ll>>&b){
    vector<vector<ll>>c(a.size(),vector<ll>(b[0].size(),0));
    for (ll i = 0; i < a.size(); i++)
    {
        for (ll j = 0; j < b[0].size(); j++)
        {
            for (ll k = 0; k < a[0].size(); k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return c;
}
vector<vector<ll>>matpow(vector<vector<ll>>a,ll n){
    vector<vector<ll>>b(a.size(),vector<ll>(a.size(),0));
    for (ll i = 0; i < a.size(); i++)
    {
        b[i][i]=1;
    }
    while (n>0)
    {
        if (n%2)
        {
            b=mul(a,b);
            n-=1;
        }else{
            a=mul(a,a);
            n/=2;
        }
    }
    return b;
}