#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/contest/1591/problem/A

typedef long long  ll;

#define N 300005

void solve(){
    int n;
    cin >> n;
    int h=1;
    bool last = false;
    bool dead = false;
    int a;
    scanf("%d",&a);
    if (a) {
        last = true;
        h++;
    }
    for(int i=1;i<n;++i){
        scanf("%d",&a);
        if (last) {
            if (a) h+=5;
            else last=false;
        } else {
            if (a) {
                last = true;
                h+=1;
            }
            else dead = true;
        }
    }
    if (dead) cout << "-1\n";
    else cout << h << "\n";
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}