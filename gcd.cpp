#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
ll inf=10010010010010010;
ll mod=998244353;
ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
	    ll r=a%b;
        a=b;
	    b=r;
	}
	return a;
}