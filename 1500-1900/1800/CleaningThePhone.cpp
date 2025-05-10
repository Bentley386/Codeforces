#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1475/problem/D

typedef long long  ll;
 
#define N 205000
 
int a[N];
void solve(){
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;++i) scanf("%d",a+i);
    vector<int> noob = vector<int>();
    vector<int> impo = vector<int>();
    for (int x,i=0;i<n;++i){
        scanf("%d",&x);
        if (x==1) noob.push_back(a[i]);
        else impo.push_back(a[i]);
    }
    sort(noob.begin(),noob.end());
    sort(impo.begin(),impo.end());
    int noobptr = noob.size()-1;
    int impoptr = impo.size()-1;
    ll freed=0;
    int conv=0;
    while (freed < m){
        if (noobptr<0 && impoptr < 0) {
            cout << "-1\n";
            return;
        }
        if (impoptr<0){
            freed+= noob[noobptr--];
            conv++;
            continue;
        }
        if (noobptr<0){
            freed+= impo[impoptr--];
            conv+=2;
            continue;
        }
        if (freed+noob[noobptr] >= m){
            conv++;
            break;
        }
 
        if (noobptr>0 && impo[impoptr] > noob[noobptr]+noob[noobptr-1]){
            freed += impo[impoptr--];
            conv+=2;
            continue;
        }
        if (noobptr == 0 && impo[impoptr] > noob[noobptr]){
            freed+= impo[impoptr--];
            conv+=2;
            continue;
        }
        freed += noob[noobptr--];
        conv++;
    }
 
    cout << conv << "\n";
 
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}