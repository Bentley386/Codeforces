#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 1000000007
using namespace std;

// https://codeforces.com/gym/302977/problem/O

typedef long long  ll;


int dp[300005]; //longest ending at [i]

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0;i<n;++i) scanf("%d",&a[i]);
    deque<int> zeroes;
    for (int i=0;i<n;++i){
        if (a[i]==0) zeroes.push_back(i);
    }
    if (zeroes.size() <= k) {
        cout << n << endl;
        for (int i=0;i<n;++i) cout << "1 ";
        return 0;
    }
    int curr = zeroes[k]-1;
    dp[curr]=curr+1;
    for (int i=curr+1;i<n;++i){
        if (a[i]==1) dp[i] = dp[i-1]+1;
        else {
            dp[i] = i-zeroes.front();
            zeroes.pop_front();
        }
    }


    int maxind = max_element(dp,dp+n) - dp;
    cout << dp[maxind] << endl;
    for (int i=maxind;i>=0;--i){
        if (a[i]==0 && k>0) {
            a[i]=1;
            k--;
            if (k==0) break;
        }
    }

    for (int i=0;i<n;++i) cout << a[i] << " ";

    return 0;
}
 