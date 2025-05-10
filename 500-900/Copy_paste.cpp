#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1417/problem/A

typedef long long  ll;
 
int main(){
    int t,n,k;
    cin >> t;
    int answer;
    while (t--){
        cin >> n >> k;
        vector<int> a(n);
        for (int i=0;i<n;++i) cin >> a[i];
        sort(a.begin(),a.end());
        int min = a[0];
        answer=0;
        for (int i=1;i<n;i++){
            answer += (k-a[i])/min;
        }
        cout << answer << endl;
    }
 
 
 
    return 0;
}