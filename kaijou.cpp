#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ll=long long;
using ld=long double;
ll inf=1001001001001;
ll mod=998244353;
// n の k 乗を mod で割った余りを計算
long long power_mod(long long n, long long k, long long mod) {
    long long result = 1;
    // k を右シフトしつつ n を 2 乗していく
    while (k > 0) {
        // k の最下ビットが 1 なら、今の n を答えに掛ける
        if ((k & 1) == 1) result = (result * n) % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return result;
}
// n! を mod で割った余りを計算
vector<long long> calc_factorial(int n, int mod) {
    vector<long long> factorial(n + 1);
    factorial[0] = 1; // 0 の階乗は 1
    for (int i = 1; i <= n; i++) {
        factorial[i] = (factorial[i - 1] * i) % mod;
    }
    return factorial;
}
// 階乗・組み合わせの mod 逆数
class FactorialMod {
    // 逆元を計算
    void calc_inverse() {
        inverse[0] = 0;
        inverse[1] = 1;
        for (int i = 2; i <= max_num; i++) {
            inverse[i] = mod - ((mod / i) * inverse[mod % i] % mod);
        }
    }
 
    // i! を mod で割った余りと逆元を計算
    void calc_factorial_inverse() {
        factorial[0] = factorial_inverse[0] = 1;
        for (int i = 1; i <= max_num; i++) {
            factorial[i] = (factorial[i - 1] * i) % mod;
            factorial_inverse[i] = (factorial_inverse[i - 1] * inverse[i]) % mod;
        }
    }
 
  public:
    int max_num;                         // 扱う最大の値
    int mod;                             // mod の法（素数）
    vector<long long> inverse;           // 逆元
    vector<long long> factorial;         // 階乗
    vector<long long> factorial_inverse; // 階乗の逆元
 
    FactorialMod(int _max_num, int _mod) {
        max_num = _max_num;
        mod = _mod;
        inverse = vector<long long>(max_num + 1);
        factorial = vector<long long>(max_num + 1);
        factorial_inverse = vector<long long>(max_num + 1);
        calc_inverse();
        calc_factorial_inverse();
    }
 
    // nCk を mod で割った余りを計算
    long long combination_mod(int n, int k) {
        if (n < 0 || k < 0 || n > max_num || k > max_num || k > n) return 0;
        return (((factorial[n] * factorial_inverse[k]) % mod) * factorial_inverse[n - k]) % mod;
    }
 
    // nHk を mod で割った余りを計算
    long long multi_choose_mod(int n, int k) {
        return combination_mod(n + k - 1, k);
    }
};

int main(void){
    int MOD = 1000000007;
    int MAX_NUM = 100;
 
    FactorialMod factorial_mod(MAX_NUM, MOD); // ここでコンストラクタが実行される
 
    cout << factorial_mod.inverse[10] << endl; // 10 の逆元 mod 1000000007
    cout << factorial_mod.factorial[10] << endl; // 10! mod 1000000007
    cout << factorial_mod.factorial_inverse[10] << endl; // 10! の逆元 mod 1000000007
 
    return 0;
}