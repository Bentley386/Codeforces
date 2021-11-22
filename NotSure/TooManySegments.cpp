#include<bits/stdc++.h>

#define INF 1000000000
#define MOD 998244353
using namespace std;
typedef long long  ll;

typedef struct  {
    int i;
    int l;
    int r;
    int num;
} seg;

int main(){
    int m=0;
    vector<int> points(200);
    vector<int> p;
    int n,k,l,r;
    cin >> n >> k;
    vector<seg> segments;
    for (int i=1;i<=n;i++){
        cin >> l >> r;
        for(int j=l-1;j<=r-1;j++) points[j]++;
        seg cur;
        cur.i=i;
        cur.l=l;
        cur.r=r;
        segments.push_back(cur);
    }
    for (int i=0;i<200;i++){
        if (points[i]<=k) continue;
        while (points[i] > k){
            seg seggy;
            seggy.r=-1;
            for (auto x : segments) {
                if (x.l-1 > i) continue;
                if (x.r > seggy.r) seggy=x;
            }
            for (int j=seggy.l-1;j<=seggy.r-1;j++) points[j]--;
            m++;
            p.push_back(seggy.i);
            for (seg& x : segments){
                if (x.i == seggy.i) x.l = 500;
            }
        }
    }
    cout << m << "\n";
    for (int i=0;i<m-1;i++) cout << p[i] << " ";
    if (m>0) cout << p[m-1];
    return 0;
}