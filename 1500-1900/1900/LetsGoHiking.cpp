#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1496/problem/D

typedef long long  ll;
 
#define N 100005
 
 
void solve(){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i=0;i<n;++i) scanf("%d",&p[i]);

    int longestinc=1;
    for (int current=1,i=0;i<n-1;++i){
        if (p[i]<p[i+1]) {
            current++;
            longestinc=max(longestinc,current);
        } else {
            current = 1;
        }
    }

    bool found = false;
    int longestincind;
    for (int current=1,i=0;i<n-1;++i){
        if (p[i]<p[i+1]) {
            current++;
            if (current==longestinc){
                if (found){
                    cout << "0\n";
                    return;
                } else {
                    found=true;
                    longestincind=i+1;
                    current=1;
                }
            }
        } else {
            current = 1;
        }
    }

    int longestdec=0;
    for (int current=1,i=0;i<n-1;++i){
        if (p[i]>p[i+1]) {
            current++;
            longestdec=max(longestdec,current);
        } else {
            current = 1;
        }
    }

    if (longestdec != longestinc){
        cout << "0\n";
        return;
    }

    found = false;
    for (int current=1,i=0;i<n-1;++i){
        if (p[i]>p[i+1]) {
            current++;
            if (current==longestdec){
                if (found){
                    cout << "0\n";
                    return;
                } else {
                    found=true;
                    current=1;
                    if (i+2-longestdec != longestincind){
                        cout << "0\n";
                        return;
                    }
                }
            }
        } else {
            current = 1;
        }
    }
    if (longestinc%2==0) {
        cout << "0\n";
    } else {
        cout << "1\n";
    }
}
 
int main(){
    int t=1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}