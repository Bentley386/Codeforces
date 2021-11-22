#include<bits/stdc++.h>


#define INF 100000000
#define MOD 998244353

using namespace std;
typedef long long  ll;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a.begin(),a.end());
    if (n==1){
        if(a[0]%2==1) cout << "sjfnb";
        else cout << "cslnb";
        return 0;
    }
    int doubles=0;
    multiset<int> occurences;
    for (int x : a){
        occurences.insert(x);
        if(occurences.count(x)>2) {
            cout << "cslnb";
            return 0;
        } else if (occurences.count(x)==2){
            if (*lower_bound(a.begin(),a.end(),x-1) == x-1 || x==0){
                cout << "cslnb";
                return 0;
            }
            doubles++;
        }
    }
    if (doubles>1){
        cout << "cslnb";
        return 0;
    }
    int previous = 0;
    ll sum = a[0];
    for (int i=1;i<n;i++){
        if (a[i]==previous) continue;
        sum+=a[i]-previous-1;
        previous++;
    }
    if (sum%2==1) cout << "sjfnb";
    else cout << "cslnb";
    return 0;
}

