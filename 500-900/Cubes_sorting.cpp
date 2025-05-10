#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1420/problem/A

typedef long long  ll;
 
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        bool cando=false;
        for (int i=1;i<n;i++) {
            if (a[i] >= a[i-1]){
                cando=true;
                break;
            }
        }
        if(cando) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}