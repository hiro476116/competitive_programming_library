#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
using ld=long double;
ld pie=3.141592653589793;
ll inf=144499999994;
ll mod=1000000007;
std::vector<std::pair<long long,long long>> convex_hull(std::vector<std::pair<long long,long long>> P){
    /*
    Copyright (c) 2021 0214sh7
    https://github.com/0214sh7/library/
    */
    if(P.size()<=2){
        return P;
    }
    std::vector<std::pair<long long,long long>> H,L,R;
    sort(P.begin(),P.end());
    
    //下半分
    for(int i=0;i<P.size();i++){
        int j=L.size();
        while(j>=2 && (L[j-1].first-L[j-2].first)*(P[i].second-L[j-2].second)<=(L[j-1].second-L[j-2].second)*(P[i].first-L[j-2].first)){
            L.pop_back();
            j--;
        }
        L.push_back(P[i]);
    }
    
    //上半分
    for(int i=P.size()-1;i>=0;i--){
        int j=H.size();
        while(j>=2 && (H[j-1].first-H[j-2].first)*(P[i].second-H[j-2].second)<=(H[j-1].second-H[j-2].second)*(P[i].first-H[j-2].first)){
            H.pop_back();
            j--;
        }
        H.push_back(P[i]);
    }
    
    
    R=L;
    for(int i=1;i<H.size()-1;i++){
        R.push_back(H[i]);
    }
    
    return R;
}