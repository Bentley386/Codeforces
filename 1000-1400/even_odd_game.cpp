#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1472/problem/D

typedef long long  ll;
 
void solve(){
    int n;
    cin >> n;
    vector<int> even,odd;
    for (int curr,i=0;i<n;++i){
        scanf("%d",&curr);
        if(curr%2==0) even.push_back(curr);
        else odd.push_back(curr);
    }
    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());
    ll alice=0,bob=0;
    for(int i=0;i<n;++i){
        if (i%2==0){
            if (odd.size() == 0) {
                alice += even.back();
                even.pop_back();
            } else if (even.size() > 0 && even.back() > odd.back()) {
                alice += even.back();
                even.pop_back();
            } else {
                odd.pop_back();
            }
        } else {
            if (even.size() == 0){
                bob += odd.back();
                odd.pop_back();
            } else if (odd.size() > 0 && odd.back() > even.back()){
                bob += odd.back();
                odd.pop_back();
            } else {
                even.pop_back();
            }
        }
    }
    if (alice > bob) cout << "Alice\n";
    else if (alice < bob) cout << "Bob\n";
    else cout << "Tie\n";
 
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}