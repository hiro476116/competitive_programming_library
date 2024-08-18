#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll inf=1001001001001;
ll mod=998244353;
vector<vector<ll>>wf(vector<vector<pair<ll,ll>>>&g,ll n){
    vector<vector<ll>>memo(n+1,vector<ll>(n+1,inf));
    for (ll i = 1; i <=n; i++)
    {
        memo[i][i]=0;
        queue<ll>que;
        que.push(i);
        while (!que.empty())
        {
            ll v=que.front();
            que.pop();
            for (ll j = 0; j < g[v].size(); j++)
            {
                if (memo[i][g[v][j].first]>memo[i][v]+g[v][j].second)
                {
                    memo[i][g[v][j].first]=memo[i][v]+g[v][j].second;
                    que.push(g[v][j].first);
                }
            }
        }
    }
    return memo;
}