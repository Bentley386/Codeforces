#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1481/problem/C

typedef long long  ll;
 
#define N 100005
 
int a[N],b[N],c[N],s[N];
stack<int> needed[N];
 
void solve(){
    int n,m;
    cin >> n >> m;
 
    for (int i=0;i<n;++i) scanf("%d",a+i);
    for (int i=0;i<n;++i) scanf("%d",b+i);
    for (int i=0;i<m;++i) scanf("%d",c+i);
    for (int i=1;i<=n;++i) needed[i] = stack<int>();
 
    for (int i=0;i<n;++i){
        if (a[i] != b[i]){
            needed[b[i]].push(i);
        }
    }
 
    for (int i=0;i<m;++i){
        if (needed[c[i]].size() > 0) {
            s[i] = needed[c[i]].top();
            a[s[i]] = c[i];
            needed[c[i]].pop();
        } else {
            s[i]=-1;
        }
    }
    if (s[m-1]  == -1) {
        for (int i=0;i<n;++i) {
            if (a[i] == c[m-1]) {
                s[m-1] = i;
                break;
            }
        }
    }
 
    if (s[m-1] == -1) {
        cout << "NO\n";
        return;
    } else {
        for (int i=0;i<n;++i){
            if (a[i] != b[i]) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        for (int i=0;i<m;++i){
            if (s[i]==-1) {
                cout << s[m-1]+1 << " ";
            } else {
                cout << s[i]+1 << " ";
            }
        }
        cout << "\n";
    }
    
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}