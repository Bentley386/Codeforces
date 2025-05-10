#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
#define N 1000006

using namespace std;

// https://codeforces.com/contest/1642/problem/D

typedef long long  ll;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    set<int> nums;
    for (int i=0;i<n;++i) {
        scanf("%d",&a[i]);
        if (nums.count(a[i])) nums.erase(a[i]);
        else nums.insert(a[i]);
    }
    if (nums.size() > 0) {
        cout << -1 << endl;
        return;
    }
    vector<pair<int,int>> q;
    vector<int> tandems;
    int cumul=0;
    while (a.size() > 0){
        if (a[1] == a[0]) {
            tandems.push_back(2);
            cumul+=2;
            a = vector<int>(a.begin()+2,a.end());
            continue;
        }
        vector<int> repeats;
        for (int i=1;i<a.size();++i){
            if (a[i]==a[0]) {
                break;
            }
            repeats.push_back(a[i]);
        }
        int j = repeats.size();
        tandems.push_back(2*j+2);
        for (int i=0;i<repeats.size();++i){
            q.push_back(make_pair(repeats[i],cumul+2+j+i));
        }
        cumul+= 2*j+2;
        reverse(repeats.begin(),repeats.end());
        repeats.insert(repeats.end(),a.begin()+j+2,a.end());
        a = repeats;
    }
    cout << q.size() << endl;
    for (auto x : q){
        cout << x.second << " " << x.first << endl;
    }
    cout << tandems.size() << endl;
    for (auto x : tandems) cout << x << " ";
    cout << endl;
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}