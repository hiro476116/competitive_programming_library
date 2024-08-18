#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll=long long;
ll inf=1001001001001;
ll mod=998244353;
template<typename T> class BIT {
private:
	int n;
	vector<T> bit;
public:
	// 0_indexed で i 番目の要素に x を加える
	void add(int i, T x){
		i++;
		while(i < n){
			bit[i] += x, i += i & -i;
		}
	}
	// 0_indexed で [0,i] の要素の和(両閉区間！！)
	T sum(int i){
		i++;
		T s = 0;
		while(i > 0){
			s += bit[i], i -= i & -i;
		}
		return s;
	}
	BIT(){}
	//初期値がすべて0の場合
	BIT(int sz) : n(sz+1), bit(n, 0){}
	BIT(const vector<T>& v) : n((int)v.size()+1), bit(n, 0){
		for(int i = 0; i < n-1; i++){
			add(i,v[i]);
		}
	}
	void print(){
		for(int i = 0; i < n-1; i++){
			cout << sum(i) - sum(i-1) << " ";
		}
		cout << "\n";
	}
	//-1スタート
	void print_sum(){
		for(int i = 0; i < n; i++){
			cout << sum(i-1) << " ";
		}
		cout << "\n";
	}
};
 
// u を昇順にソートするのに必要な交換回数(転倒数) (u は {0,..., n-1} からなる重複を許した長さ n の数列)
long long inv_count(const vector<ll>& u)
{
	int n = (int)u.size();
	BIT<int> bt(n);
	long long ans = 0;
	for(int i = 0; i < n; i++){
		ans += i - bt.sum(u[i]);
		bt.add(u[i], 1);
	}
	return ans;
}
int main(){
    ll n;
    cin >> n;
    vector<ll>a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans=inv_count(a);
    vector<ll>sol;
    sol.push_back(ans);
    for (ll i = 0; i < n-1; i++)
    {
        ans+=n-1-a[i]-a[i];
        sol.push_back(ans);
    }
    for (ll i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << endl;
    }
    
}