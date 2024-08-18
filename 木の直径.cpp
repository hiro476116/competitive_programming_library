#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
using ld=long double;
ld pie=3.141592653589793;
ll inf=144499999999994;
ll mod=998244353;
vector<ll>diameter(ll n,vector<vector<ll>>&g){
    vector<ll>memo(n,inf);
    memo[0]=0;
    queue<ll>que;
    que.push(0);
    while (!que.empty())
    {
        ll v=que.front();
        que.pop();
        for (ll i = 0; i < g[v].size(); i++)
        {
            if (memo[g[v][i]]>memo[v]+1)
            {
                que.push(g[v][i]);
                memo[g[v][i]]=memo[v]+1;
            }
        }
    }
    ll id,x=0;
    for (ll i = 0; i < n; i++)
    {
        if (x<memo[i])
        {
            x=memo[i];
            id=i;
        }
    }
    que.push(id);
    for (ll i = 0; i < n; i++)
    {
        memo[i]=inf;
    }
    memo[id]=0;
    while (!que.empty())
    {
        ll v=que.front();
        que.pop();
        for (ll i = 0; i < g[v].size(); i++)
        {
            if (memo[g[v][i]]>memo[v]+1)
            {
                que.push(g[v][i]);
                memo[g[v][i]]=memo[v]+1;
            }
        }
    }
    x=0;
    ll syu;
    for (ll i = 0; i < n; i++)
    {
        if (memo[i]>x)
        {
            x=memo[i];
            syu=i;
        }
    }
    vector<ll>memo2(n,inf);
    memo2[syu]=0;
    que.push(syu);
    while (!que.empty())
    {
        ll v=que.front();
        que.pop();
        for (ll i = 0; i < g[v].size(); i++)
        {
            if (memo2[g[v][i]]>memo2[v]+1)
            {
                que.push(g[v][i]);
                memo2[g[v][i]]=memo2[v]+1;
            }
        }
    }
    ll len=memo[syu]+1;
    ll c1=-1,c2=-1;
    if (memo[syu]%2)
    {
        for (ll i = 0; i < n; i++)
        {
            if (memo[i]==memo2[i]-1)
            {
                c1=i;
            }
            if (memo[i]-1==memo2[i])
            {
                c2=i;
            }
        }
    }else{
        for (ll i = 0; i < n; i++)
        {
            if (memo[i]==memo[syu]/2&&memo2[i]==memo[syu]/2)
            {
                c1=i;
            }
        }
    }
    vector<ll>ans;
    ans.push_back(len);
    ans.push_back(id);
    ans.push_back(syu);
    ans.push_back(c1);
    ans.push_back(c2);
    return ans;
}
