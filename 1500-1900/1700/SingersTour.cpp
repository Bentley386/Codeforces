#include<bits/stdc++.h>
 
using namespace std;

// https://codeforces.com/contest/1618/problem/E

using ll = long long;

constexpr ll INF = 2000000000;
constexpr ll MOD = 998244353;
constexpr int N = 50000;

int b[N], a[N];

//a1+na2+(n-1)a3+...+2an = b1
//2a1+a2 + na3 + ....+3an = b2
//a1+a2-na2+a3+a4... = b2-b1
//sum(a) -na2 = b2-b1
//a2 = (sum(a)-b2+b1)/n

//a1+na2+(n-1)a3 +....+2an = b1
//na1 + (n-1)a2 ++ ... +an = bn
//sum(a)-na1 = b1-bn -> a1 = sum(a)+bn-b1 / n

//n*(n+1)/2 * sum(a) = sum(b)

void solve(){
    ll n; cin >> n;
    for (int i=0;i<n;++i) scanf("%d", b+i);
    if (n==1){
        cout << "YES\n";
        cout << b[0] << endl;
        return;
    }
    ll sum = 0LL;
    ll sumn = n*(n+1)/2;
    for (int i=0;i<n;++i) sum += b[i];
    if (sum % sumn != 0) {
        cout << "NO\n";
        return;
    }
    ll suma = sum/sumn;

    for (int i=0;i<n;++i){
        int prev = (i==0) ? n-1 : i-1;
        ll num = suma - b[i] + b[prev];
        if (num % n != 0 || num<=0) {
            cout << "NO\n";
            return;
        }
        a[i] = num/n;
    }
    cout << "YES\n";
    for (int i=0;i<n;++i) cout << a[i] << " ";
    cout << endl;

}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}