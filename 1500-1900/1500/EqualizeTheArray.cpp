#include<bits/stdc++.h>
 
#define INF 2000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1490/problem/F

typedef long long  ll;

#define N 200005

void solve(){
    int n;
    cin >> n;
    map<int,int> occurences; //for each unique el, count how many times 
    for (int temp,i=0;i<n;++i) {
        scanf("%d",&temp);
        if (occurences.count(temp) == 0) occurences[temp]=1;
        else occurences[temp]++;
    }
    map<int,int> freq; //key: frequencies of els, value: how many els have same freq
    for (pair<int,int> x : occurences) {  
        int count = x.second;
        if (freq.count(count) == 0) freq[count]=1;
        else freq[count]++;
    }
    int answer = INF;
    int sofarval=0;
    int sofaramount=0;
    for (auto x=freq.rbegin();x!=freq.rend();x++){
        int num = x->second; //different numbers of same occ
        int mul = x->first; //number of occurences
        int total = num*mul;
        answer = min(answer,n-total-sofarval+(sofarval-sofaramount*mul));
        sofarval+=total;
        sofaramount+=num;
    }

    cout << answer << endl;
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}