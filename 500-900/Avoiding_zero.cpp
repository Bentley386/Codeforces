#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1427/problem/A

typedef long long  ll;
 
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0;i<n;++i) cin >> a[i];
        sort(a.rbegin(),a.rend());
        int sum=0;
        for (int i=0;i<n;++i) {
            sum+= a[i];
            if (sum==0){
                sum=0;
                break;
            }
        }
 
        if (sum==0){
            reverse(a.begin(),a.end());
            for (int i=0;i<n;++i){
                sum += a[i];
                if (sum == 0){
                    sum=0;
                    break;
                }
            }
        }
 
        if (sum==0){
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i=0;i<n;++i) cout << a[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}