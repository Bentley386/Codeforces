#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1486/problem/C1

typedef long long  ll;
 
void binarysearch(int l, int r,int prev){
    int max2;
    if (r==l+1){
        int result = (prev==l) ? r : l;
        cout << "! " << result << "\n";
        return;
    }
    if (r==l+2) {
        if (prev==l){
            cout << "? " << l << " " << l+1 << "\n";
            cout.flush();
            cin >> max2;
            if (max2==prev) cout << "! " << l+1 << "\n";
            else cout << "! " << r << "\n";
        } else if (prev==l+1) {
            cout << "? " << l << " " << l+1 << "\n";
            cout.flush();
            cin >> max2;
            if (max2==prev) cout << "! " << l << "\n";
            else cout << "! " << r << "\n";
        } else {
            cout << "? " << l+1 << " " << r << "\n";
            cout.flush();
            cin >> max2;
            if (max2==prev) cout << "! " << l+1 << "\n";
            else cout << "! " << l << "\n";
        }
        return;
    }

    int mid = (l+r)/2;
    if (prev<= mid){ 
        cout << "? " << l << " " << mid << "\n";
        cout.flush();
        cin >> max2; 
        if (max2==prev) binarysearch(l,mid,max2);
        else {
            cout << "? " << mid << " " << r << "\n";
            cout.flush();
            cin >> max2;
            binarysearch(mid,r,max2);
        }
    } else {
        cout << "? " << mid << " " << r << "\n";
        cout.flush();
        cin >> max2;
        if (max2==prev) binarysearch(mid,r,max2);
        else {
            cout << "? " << l << " " << mid << "\n";
            cout.flush();
            cin >> max2;
            binarysearch(l,mid,max2);
        }
    }

}

void solve(){
    int n;
    cin >> n;
    int max2;
    cout << "? 1 " << n << "\n";
    cout.flush();
    cin >> max2;
    binarysearch(1,n,max2);

}
 
int main(){
    solve();
    return 0;
}