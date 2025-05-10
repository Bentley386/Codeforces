#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1395/problem/B

typedef long long  ll;
 
int main(){
    int n,m,Sx,Sy;
    cin >> n >> m >> Sx >> Sy;
    cout << Sx << " " << Sy << "\n";
    cout << Sx << " " << 1 << "\n";
    cout << 1 << " " << 1 << "\n";
    int x=1,y=1;
    bool right=true;
    for (int i=1;i<n*m;i++){
        if (x==n || x==1){
            if (x==n){
                if (right) {
                    y++;
                    right = false;
                } else x--;
            }
            if (x==1){
                if (right) x++;
                else {
                    y++;
                    right = true;
                }
            }
        }
        else {
            if (right) x++;
            else x--;
        }
        if (x == Sx && (y==Sy || y==1)) continue;
        cout << x << " " << y << "\n";
    }
    return 0;
}