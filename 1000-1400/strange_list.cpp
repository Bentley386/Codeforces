#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1471/problem/B

typedef long long  ll;
 
void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n),howmany(n,0);
    ll sum=0;
    int minim=INF,minimid;
    for (int copy,i=0;i<n;++i) {
        scanf("%d",&copy);
        a[i]=copy;
        sum += copy;
        if (minim!=0){
            while (copy % x == 0) {
                howmany[i]++;
                copy/=x;
            }
            if (howmany[i] < minim){
                minim = howmany[i];
                minimid = i;
            }
        }   
    }
    if (minim>0){
        for (int i=0;i<n;++i){
            sum+= (ll)minim*a[i];
        }
    }
    for (int i=0;i<minimid;++i) sum+= a[i];
    cout << sum << endl;
 
 
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}