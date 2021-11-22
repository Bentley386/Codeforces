#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int l,r;
    int res;
    cin >> l >> r;
    if (abs(r-l)<=1) res=l; 
    else res=2;
    cout << res << "\n";
    return 0;
}