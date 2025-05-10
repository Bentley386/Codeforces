#include<bits/stdc++.h>
 
using namespace std;

// https://codeforces.com/contest/1698/problem/D

using ll = long long;

constexpr ll INF = 2000000000;
constexpr ll MOD = 1000000007;
constexpr int N = 100005;

int check(int l, int r){
    cout << "? " << l << " " << r << endl;
    int n=r-l+1;
    int num = 0; //number of right
    int correctOne = -1;
    for (int temp,i=0;i<n;++i){
        cin >> temp;
        if (temp > r || temp < l) num++;
        else correctOne = temp;
    }
    int right = n-num;
    if (right % 2 == 0) return 0;
    else if (right == 1) return correctOne;
    else return -1;

}

void solve(){
    int n; cin >> n;

    int l=1, r=n;
    int mid = (l+r)/2;
    while (l<r){
        if (r==l+1) {
            mid = check(l,r);
            break;
        }
        mid = (l+r)/2;
        int res = check(l,mid);
        if (res > 0) {
            mid = res; break;
        }

        else if (res == -1) { //2 1 3 5 4
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << "! " << mid << endl;
}

int main(){
    int t; cin >> t;
    while (t--)
    solve();
    return 0;
}