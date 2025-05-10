#include<bits/stdc++.h>
 
using namespace std;

// https://codeforces.com/contest/1554/problem/C

using ll = long long;

constexpr ll INF = 2000000000;
constexpr ll MOD = 1000000007;
constexpr int N = 100005;

void solve(){
    int n,m;
    cin >> n >> m;

    if (n>m) {
        cout << "0\n";
        return;
    }
    bool moved = false;
    int solution = m+1;
    for (int i=31;i>=0;--i){
        if (((1<<i) & n) && !((1<<i) & solution)) {
            for (int j=i;j>=0;--j){
                if ((1<<j) & solution){
                    moved = true;
                    solution -= 1<<j;
                    break;
                }
            }
            solution += 1<<i;
        }  if (!((1<<i)&n) && ((1<<i)&solution) && moved){
            solution -= 1<<i;
        }
    }

    cout << (n^solution);
    cout << endl;
}

int main(){
    int t; cin >> t;
    while (t--)
    solve();
    return 0;
}