#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
ll inf=1001001001001;
ll mod=1000000007;
ll modpow(ll x, ll n) {
  if(n==0) return 1;  //再帰の終了条件

  else if(n%2==1) {
    return (x*modpow(x, n-1));  //nが奇数ならnを1ずらす
  }
  else return modpow((x*x), n/2);  //nが偶数ならnが半分になる
}
string change(string s,ll n,ll m){
    if (s=="0")
    {
        return s;
    }
    //n進数→m進数
    reverse(s.begin(),s.end());
    ll x=0;
    ll memo=1;
    for (ll i = 0; i < s.size(); i++)
    {
        x+=(s[i]-'0')*memo;
        memo*=n;
    }
    string t;
    while (x>0)
    {
        t.push_back((char)(x%m+'0'));
        x/=m;
    }
    reverse(t.begin(),t.end());
    return t;
}