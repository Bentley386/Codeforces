#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;
typedef long long  ll;
 
 
void solve(){
    int n,first,curr,ln,rn;
    cin >> n;
    if (n==1){
        cout << "! 1\n"; cout.flush();
        return;
    }
 
    cout << "? 1\n"; cout.flush();
    cin >> first;
    cout << "? 2\n"; cout.flush();
    cin >> rn;
    if (rn > first) {
        cout << "! 1\n"; cout.flush();
        return;
    }
 
 
    int left=2;
    int right=n;
    int mid; //5 2 3 4 1
    while (left <= right){
        mid = (left+right)/2;
        //cout << "left: " << left << ", right: " << right << ", mid" << mid << endl;
        cout << "? " << mid << "\n"; cout.flush();
        cin >> curr;
        cout << "? " << mid-1 << "\n"; cout.flush();
        cin >> ln;
        if (mid==n && curr<ln){
            cout << "! " << mid << "\n"; cout.flush();
            return;
        } else {
            cout << "? " << mid+1 << "\n";cout.flush();
            cin >> rn;
            if (curr<ln && curr < rn){
                cout << "! " << mid << "\n";cout.flush();
                return;
            }
        }
        if (ln<curr) right=mid-1;
        else left=mid+1;
    }
    cout << "! " << mid << "\n";cout.flush();
}
 
int main(){
    solve();
    return 0;
}