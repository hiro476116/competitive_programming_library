#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll inf=1001001001001;
ll mod=998244353;
vector<ll>dk(vector<vector<pair<ll,ll>>>&g,ll n,ll st){
    vector<ll>memo(n+1,inf);
    memo[st]=0;
    queue<ll>que;
    que.push(st);
    while (!que.empty())
    {
        ll v=que.front();
        que.pop();
        for (ll i = 0; i < g[v].size(); i++)
        {
            if (memo[g[v][i].first]>memo[v]+g[v][i].second)
            {
                memo[g[v][i].first]=memo[v]+g[v][i].second;
                que.push(g[v][i].first);
            }
        }
    }
    return memo;
}