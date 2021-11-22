#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;
typedef long long  ll;
 
 
 
void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> ppl(n);
    vector<tuple<int,int,int>> byH(n),byW(n);
    vector<pair<int,int>> byHp(n),byWp(n);
    for (int h,w,i=0;i<n;++i){
        scanf("%d %d",&h,&w);
        ppl[i] = {h,w};
        byH[i] = make_tuple(h,w,i);
        byW[i] = make_tuple(w,h,i);
    }
    sort(byH.begin(),byH.end());
    for (int minim=INF,i=0;i<n;++i){
        if(get<1>(byH[i]) < minim){
            minim = get<1>(byH[i]);
            byHp[i] = {get<2>(byH[i]),minim};
        } else {
            byHp[i] = byHp[i-1];
        }
    }
 
    sort(byW.begin(),byW.end());
    for (int minim=INF,i=0;i<n;++i){
        if(get<1>(byW[i]) < minim){
            minim = get<1>(byW[i]);
            byWp[i] = {get<2>(byW[i]),minim};
        } else {
            byWp[i] = byWp[i-1];
        }
    }
 
 
    pair<int,int> cand;
    for (int i=0;i<n;++i){
        cand = ppl[i];
        int ind = lower_bound(byH.begin(),byH.end(),make_tuple(cand.first,-INF,-INF))-byH.begin()-1;
        if (ind>=0 && byHp[ind].second < cand.second) {
            cout << byHp[ind].first+1 << "\n";
        } else {
            ind = lower_bound(byW.begin(),byW.end(),make_tuple(cand.first,-INF,-INF)) - byW.begin()-1;
            if (ind>=0 && byWp[ind].second < cand.second) {
                cout << byWp[ind].first+1 << "\n";
            } else cout << "-1\n";
        }
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