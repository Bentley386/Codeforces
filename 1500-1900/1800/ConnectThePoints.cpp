#include<bits/stdc++.h>
 
using namespace std;

// https://codeforces.com/contest/1666/problem/C

using ll = long long;

constexpr ll INF = 2000000000;
constexpr ll MOD = 998244353;
constexpr int N = 50000;
vector<ll> segs[15];

int buildSegs(ll x0, ll y0, ll x1, ll y1, int i){
    if (x0 == x1 || y0 == y1){
        segs[i] = vector<ll> {x0, y0, x1, y1};
        return 1;
    }
    segs[i] = vector<ll> {x0, y0, x1, y0};
    i++;
    segs[i] = vector<ll> {x1,y0,x1,y1};
    return 2;
}

void solve(){
    vector<ll> pX(3),pY(3);
    for (int i=0;i<3;++i){
        cin >> pX[i] >> pY[i];
    }
    vector<ll> temp = pX;
    sort(temp.begin(),temp.end());
    ll medianX = temp[1];

    temp = pY;
    sort(temp.begin(),temp.end());
    ll medianY = temp[1];

    int num=0;
    for (int i=0;i<3;++i){
        if (medianX == pX[i] && medianY == pY[i]) continue;
        num += buildSegs(pX[i],pY[i], medianX, medianY, num);
    }

    cout << num << endl;
    for (int i = 0 ; i<num;++i){
        for (ll x : segs[i]) cout << x << " ";
        cout << endl;
    }

}

int main(){
    solve();
    return 0;
}