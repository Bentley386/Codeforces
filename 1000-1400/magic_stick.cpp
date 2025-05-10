#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// https://codeforces.com/contest/1257/problem/B

void canGet(int x, int y);

int main(){
    int T,x,y;
    cin >> T;
    for (int i=0;i<T;i++){
        cin >> x >> y;
        canGet(x,y);
    }
    return 0;
}

void canGet(int x, int y){
    if (x>=y){
        cout << "YES\n";
        return;
    }
    if (x==1) {
        cout << "NO\n";
        return;
    }
    int highest = (x % 2 == 0) ? x : x-1;
    int prev = 0;
    while (highest > prev){
        prev = highest;
        highest = (highest % 2 == 0) ? highest : highest-1;
        highest = highest/2*3;
        if (highest>=y){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
    

}