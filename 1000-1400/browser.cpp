#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>

using namespace std;

// https://codeforces.com/contest/915/problem/B

typedef long long  ll;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int n,pos,l,r,toclose;
    cin >> n >> pos >> l >> r;
    if (r-l == n-1) {cout << 0 << endl; return 0;}
    else if (l==1) toclose = abs(r-pos)+1;
    else if (r==n) toclose = abs(pos-l)+1;
    else if (pos < l) toclose = r-pos+2;
    else if (pos > r) toclose = pos-l+2;
    else {
        int levo = pos-l+r-l+2;
        int desno = r-pos+r-l+2;
        toclose = std::min(levo,desno);
    }
    cout << toclose << endl;
    return 0;
}