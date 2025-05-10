#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1469/problem/B

typedef long long  ll;
 
bool solve(string &s){
    int num = 0;
    bool rdy = false;
    for (char &c : s){
        rdy = false;
        if (c == '?') num++;
        else if (c  == ')') {
            if (num==0) return false;
            num--;
        }
        else if (c == '(') {
            num++;
            rdy = true;
        }
    }
    if (num%2 == 1 || rdy) return false;
    return true;
}
 
int main(){
    int t,n,m;
    vector<int> pr,pb;
    cin >> t;
    while (t--){
        cin >> n;
        pr = vector<int>(n);
        cin >> pr[0];
        for (int i=1; i<n; ++i) {
            cin >> pr[i];
            pr[i] += pr[i-1];
        }
        cin >> m;
        pb = vector<int>(m);
        cin >> pb[0];
        for (int i=1;i<m;++i) {
            cin >> pb[i];
            pb[i] += pb[i-1];
        }
 
        cout << max(0,*max_element(pb.begin(),pb.end())) + max(0,*max_element(pr.begin(),pr.end())) << "\n";
    }
    return 0;
}