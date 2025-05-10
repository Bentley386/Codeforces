#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/contest/1591/problem/C

typedef long long  ll;

#define N 200005

int x[N];

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> right,left;
    for (int temp,i=0;i<n;++i) {
        scanf("%d",&temp);
        if (temp>0) right.push_back(temp);
        else left.push_back(-temp);
    }
    sort(right.begin(),right.end());
    sort(left.begin(),left.end());

    stack<int> right2, left2;
    for (int i=right.size()-1;i>=0;i-=k){
        right2.push(right[i]);
    } 

    for (int i=left.size()-1;i>=0;i-=k){
        left2.push(left[i]);
    }

    ll result=0;
    while (left2.size()>1){
        result += 2*left2.top();
        left2.pop();
    }
    while (right2.size()>1){
        result += 2*right2.top();
        right2.pop();
    }
    if (right2.size() == 0) result += left2.top();
    else if (left2.size() == 0) result += right2.top();
    else {
        result += (ll) (right2.top() + left2.top()) + min(right2.top(),left2.top());
    }
    cout << result << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}