#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1417/problem/B

typedef long long  ll;
 
int main(){
    int t,n,T,curr;
    ll pairs1,pairs2;
    cin >> t;
    while (t--){
        map<int,ll> used1,used2;
        cin >> n >> T;
        for(int i=0;i<n;++i){
            scanf("%d",&curr);
            if (used1.count(T-curr) == 0) {
                if (used1.count(curr)==0) used1[curr] = 1;
                else used1[curr]++;
                cout << "1 ";
            } else {
                pairs1 = (used1.count(curr) == 0) ? used1[T-curr] : used1[T-curr]*used1[curr];
                if (used2.count(curr) == 0){
                    pairs2 = (used2.count(T-curr) == 0) ? 0 : used2[T-curr];
                } else pairs2 = (used2.count(T-curr) == 0) ? 0 : used2[T-curr]*used2[curr];
                if (pairs1<pairs2) {
                    used1[curr] = (used1.count(curr) == 0) ? 1 : used1[curr]+1;
                    cout << "1 ";
                } else {
                    used2[curr] = (used2.count(curr) == 0) ? 1 : used2[curr]+1;
                    cout << "0 ";
                }
            }
        }
        cout << "\n";
    } //1 2 3 4 5 6
    return 0;
}