#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
#define N 1000006

using namespace std;

// https://codeforces.com/contest/1650/problem/C

typedef long long  ll;

void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pair<int,int>> pts(m);
    map<int,int> ind;
    for (int i=0;i<m;++i){
        int x,w;
        scanf("%d %d",&x,&w);
        pts[i] = make_pair(x,w);
        ind[x] = i+1;
    }
    sort(pts.begin(),pts.end(),[] (auto x, auto y) {return (x.second < y.second);});
    sort(pts.begin(),pts.begin()+2*n);
    ll weights=0;
    for (int i=0;i<2*n;++i) weights+=pts[i].second;
    cout << weights << endl;
    for (int i=0;i<n;++i){
        cout << ind[pts[i].first] << " " << ind[pts[2*n-1-i].first] << endl;
    }
}


int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}