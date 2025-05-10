#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1395/problem/A

typedef long long  ll;
 
vector<ll> balls(4);
bool test1();
bool test2();
bool test3();
 
int main(){
    int T;
    cin >> T;
    loo:while (T--){
        for (int i =0;i<4;i++) cin >> balls[i];
        if (test1() || test2() || test3()) {
            cout << "Yes\n";
            continue;
        }
        for (int i=0;i<3;i++){
            if (balls[i]<=0){
                cout << "No\n";
                goto loo;
            }
        }
        for (int i=0;i<3;i++) balls[i]--;
        balls[3]+=3;
        if (test1() || test2() || test3()){
            cout << "Yes\n";
            continue;
        }
        cout << "No\n";
    }
    return 0;
}
 
bool test3(){
    for (int i=0;i<4;i++){
        if (balls[i]%2==1 && balls[(i+1)%4]%2==0 && balls[(i+2)%4]%2==0 && balls[(i+3)%4]%2==0) return true;
    }
    return false;
}
 
bool test2(){
    for (int i=0;i<4;i++){
        if (balls[i] % 2 != 0) return false;
    }
    return true;
 
}
 
bool test1(){
    for (int i=0;i<4;i++){
        if (balls[i] != 0) return false;
    }
    return true;
}