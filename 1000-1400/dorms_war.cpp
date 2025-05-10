#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
#define N 100005

using namespace std;

// https://codeforces.com/contest/1670/problem/B

typedef long long  ll;


void solve(){
    int n; cin >> n;
    string s;
    getline(cin >> ws,s);
    set<char> special;
    int k; cin >> k;
    for (int i=0;i<k;++i){
        char c;
        cin >> ws >> c;
        special.insert(c);
    }
    int result;
    int first = -1;
    for (int i=0;i<n;++i){
        if (special.count(s[i])){
            first = i;
            result = i;
            break;
        }
    }
    if (first == -1) cout << 0 << endl;
    else {
        int curr=1;
        for (int i=first+1;i<n;++i){
            if (special.count(s[i])){
                result = max(result,curr);
                curr = 0;
            }
            curr++;
        }
        cout << result << endl;

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();
    return 0;
} 