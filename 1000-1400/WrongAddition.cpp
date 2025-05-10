#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1619/problem/C

typedef long long  ll;

vector<int> numToList(ll x){
    vector<int> result;
    while (x > 0){
        result.push_back(x%10);
        x/=10;
    }
    return result;
}

ll listToNum(vector<int> digits){
    ll result = 0;
    ll curr = 1;
    for (int x : digits){
        result += curr*x;
        curr*=10;
    }
    return result;
}

ll solve(){
    ll a,s;
    cin >> a >> s;
    vector<int> va,vs,result;
    va = numToList(a); vs = numToList(s);


    int j=0;
    for (int i=0;i<va.size();++i){
        if (j>=vs.size()) return -1;
        if (va[i] <= vs[j]) {
            result.push_back(vs[j++]-va[i]);
        } else {
            result.push_back(10+vs[j++]-va[i]);
            if (j >= vs.size() || vs[j++] != 1) return -1;
        }
    }
    if (j< vs.size()) {
        for (;j<vs.size();++j) result.push_back(vs[j]);
    }
    return listToNum(result);
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cout << solve() << endl;
    }
    return 0;
}