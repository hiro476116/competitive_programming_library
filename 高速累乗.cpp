using ll=long long;
ll mod;
ll modpow(ll x, ll n) {
  x = x%mod;
  if(n==0) return 1;  //再帰の終了条件

  else if(n%2==1) {
    return (x*modpow(x, n-1))%mod;  //nが奇数ならnを1ずらす
  }
  else return modpow((x*x)%mod, n/2)%mod;  //nが偶数ならnが半分になる
}