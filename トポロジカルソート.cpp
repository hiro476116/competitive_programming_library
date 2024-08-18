#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
using ld=long double;
ll inf=10010010010010010;
ll mod=998244353;
//辞書順最小トポロジカルソート 辞書順最小じゃなくていい時は普通のqueue
vector<ll> topological_sort(vector<vector<ll>> &G, vector<ll> &indegree, ll V) {
    // トポロジカルソートを記録する配列
    vector<ll> sorted_vertices;

    // 入次数が0の頂点を発見したら、処理待ち頂点としてキューに追加する
    priority_queue<ll,vector<ll>,greater<ll>> que;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }

    // キューが空になるまで、操作1~3を繰り返す
    while (que.empty() == false) {
        // キューの先頭の頂点を取り出す
        int v = que.top();
        que.pop();

        // その頂点と隣接している頂点の入次数を減らし、0になればキューに追加
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v][i];
            indegree[u] -= 1;
            if (indegree[u] == 0) {
                que.push(u);
            }
        }
        // 頂点vを配列の末尾に追加する 
        sorted_vertices.push_back(v);
    }
    vector<ll>dame;
    if (sorted_vertices.size()!=V)
    {
        return dame;//トポロジカルソート不可能
    }
    
    // トポロジカルソートを返す
    return sorted_vertices;
}
int main(){
    ll n,m;
    cin >> n >> m;
    vector<vector<ll> >g(n+1,vector<ll>(0)),gg(n+1,vector<ll>(0));
    bool check=true;
    vector<ll>mm(n+1,0);
    for (ll i = 0; i < m; i++)
    {
        ll a,b;
        cin >> a >> b;
        g[a].push_back(b);
        mm[b]+=1;
    }
    for (ll i = 1; i <=n; i++)
    {
        sort(g[i].begin(),g[i].end());
    }
    vector<ll>ans;
    ans=topological_sort(g,mm,n);
    if (ans.size()==0)
    {
        cout << -1 << endl;
        return 0;
    }
    
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
