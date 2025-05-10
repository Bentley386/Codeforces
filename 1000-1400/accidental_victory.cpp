#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1490/problem/E

typedef long long  ll;
 
#define N 200005
 
void solve(){
    int n;
    cin >> n;
    vector<pair<ll,int>> a(n);
    for (int i=0;i<n;++i){
        int temp;
        scanf("%d",&temp);
        a[i] = {temp,i+1};
    }
    sort(a.begin(),a.end());
    int maxim = a[n-1].first;
    int cum=0;
    int startindex=n-1;
    for (int i=0;i<n;++i){
        cum+=a[i].first;
        int j=i;
        while (j<n-1 && cum >= a[j+1].first){
            cum+=a[j+1].first;
            j++;
            if (cum>=maxim) break;
        }
        if (cum >= maxim){
            startindex=i;
            break;
        }
        i=j;
    }
 
    cout << n-startindex << "\n";
    vector<int> result;
    for (int i=startindex;i<n;++i)
        result.push_back(a[i].second);
    sort(result.begin(),result.end());
    for (int x : result) {
        cout << x << " ";
    }
    cout << "\n";
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}