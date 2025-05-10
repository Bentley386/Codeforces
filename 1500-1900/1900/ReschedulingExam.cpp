#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
#define N 300000

using namespace std;

// https://codeforces.com/contest/1650/problem/E

typedef long long  ll;

int a[N];
int n,d;

int tryIt(int toskip){
    vector<int> inds;
    for (int i=0;i<n;++i){
        if (i==toskip) continue;
        inds.push_back(i);
    }
    int minmu = a[inds[0]]-1;
    for (int i=1;i<n-1;++i){
        minmu = min(minmu,a[inds[i]]-a[inds[i-1]]-1);
    }
    int maxmu = (a[inds[0]])/2-1; 
    for (int i=1;i<n-1;++i){
        maxmu = max(maxmu,(a[inds[i]]-a[inds[i-1]])/2-1);
    }
    maxmu = max(maxmu,d-a[inds[n-2]]-1);
    minmu = min(minmu,maxmu);
    return minmu;
}

void solve(){
    cin >> n >> d;
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    int minmu = a[0]-1;
    for (int i=1;i<n;++i){
        if (a[i]-a[i-1]-1 < minmu) minmu = a[i]-a[i-1]-1;
    }
    stack<int> mins;
    if (a[0]-1 == minmu) {
        mins.push(0);
    } else {
        for (int i=1;i<n;++i){
            if (a[i]-a[i-1]-1 == minmu) {
                mins.push(i);
                mins.push(i-1);
                break;
            }
        }
    }

    if (mins.size() == 2){
        int first = tryIt(mins.top());
        mins.pop();
        int second = tryIt(mins.top());
        minmu = max(minmu,max(first,second));
    }
    else if (mins.size() == 1){
        minmu = max(minmu,tryIt(mins.top()));
    }

    cout << minmu << endl;

}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}