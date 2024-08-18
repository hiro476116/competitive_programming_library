using ll=long long;
ll modpow(ll x, ll n) {
  if(n==0) return 1;  //再帰の終了条件

  else if(n%2==1) {
    return (x*modpow(x, n-1));  //nが奇数ならnを1ずらす
  }
  else return modpow((x*x), n/2);  //nが偶数ならnが半分になる
}