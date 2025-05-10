#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
#define N 200005

using namespace std;

// https://codeforces.com/contest/1647/problem/D

typedef long long  ll;

bool prime (ll x){
    if (x==1) return false;
    for (int i=2;i*i<=x;++i){
        if (x%i == 0) return false;
    }
    return true;
}

ll primePower (ll x){
    int divisor;
    for (int i=2;i*i<=x;++i){
        if (x%i == 0) {
            divisor = i;
            break;
        }
    }
    while (x % divisor == 0) x/= divisor;
    if (x==1) return divisor;
    else return 0;
}

int count (ll x, ll d){
    int c = 0;
    while (x%d==0) {
        x/=d;
        ++c;
    }
    return c;
}

void solve(){
    ll x,d;
    cin >> x >> d;
    int c = count(x,d);
    if (c==1) {
        cout << "NO\n";
        return;
    }

    ll leftover = x;
    for (int i=0;i<c;++i) leftover /= d;

    if (prime(d)){
        if (prime(leftover) || leftover == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    } 
    else if (primePower(d)) {
        if (leftover == 1){
            if (x/d % (d*d) == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else if (!prime(leftover)) cout << "YES\n";
        else {
            if (x/d % (d*d) != 0) cout << "NO\n";
            else {
                if (leftover == primePower(d) && d == leftover*leftover){
                    if (x/(d*d) % (d*d) != 0) {
                        cout << "NO\n";
                        return;
                    }
                }
                cout << "YES\n";
            }
        }
    }
    else {
        if ((prime(leftover) || leftover == 1) && x/d % (d*d) != 0) cout << "NO\n";
        else cout << "YES\n";
    }
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
} 