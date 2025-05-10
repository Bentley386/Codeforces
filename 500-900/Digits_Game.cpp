#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1419/problem/A

typedef long long  ll;
 
int main(){
    int t;
    cin >> t;
    int razeWins=0;
    for (int k=0;k<t;k++){
        int n;
        cin  >> n;
        char c;
        scanf("%c",&c);
        int razeOdd=0,razeEven=0,BreachOdd=0,BreachEven=0;
        for (int i=0;i<n;i++){
            scanf("%c",&c);
            if((i+1) % 2 == 0){
                if (int(c-'0') % 2 == 0) BreachEven++;
                else BreachOdd++;
            } else {
                if (int(c-'0') % 2 == 0) razeEven++;
                else razeOdd++;
            }
        }
        if (n%2==1) {
            if (razeOdd > 0) cout << 1 << endl;
            else cout << 2 << endl;
        } else {
            if (BreachEven > 0) cout << 2 << endl;
            else cout << 1 << endl; 
        }
    }
    return 0;
}