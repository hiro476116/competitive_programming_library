#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll=long long;
using ld=long double;
ld pie=3.141592653589793;
ll mod=1000000007;
ll inf=1009999999999999990;
string s;
int main(){
    ll x=0,y=0;
    vector<ll>r(s.size(),0);
    while (x<s.size())
    {
        while (x-y>=0&&x+y<s.size()&&s[x-y]==s[x+y])
        {
            y++;
        }
        r[x]=y;
        ll k=1;
        while (x-k>=0&&k+r[x-k]<y)
        {
            r[x+k]=r[x-k];
            k++;
        }
        x+=k;
        y-=k;
    }
}