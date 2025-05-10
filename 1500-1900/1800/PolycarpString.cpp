#include<bits/stdc++.h>
 
using namespace std;

// https://codeforces.com/contest/1560/problem/E

using ll = long long;

constexpr ll INF = 2000000000;
constexpr ll MOD = 1000000007;
constexpr int N = 100005;

bool simulate(string s, vector<char>& order, string& t){
    set<char> skip;
    int j=0;
    for (char c : order){
        for (int i=0;i<s.size();++i){
            if (skip.count(s[i])) continue;
            if (s[i] !=t[j]) return false;
            ++j;
        }
        skip.insert(c);
    }
    if (j != t.size()) return false;
    return true;
}

void solve(){
    string t;
    getline(cin >> ws, t);
    map<char,int> letters;
    vector<char> order;
    for (int i=t.size()-1;i>=0;--i){
        if (letters.count(t[i]) == 0) {
            letters[t[i]]=1;
            order.push_back(t[i]);
        }
        else letters[t[i]]++;
    }
    int N = order.size();
    int len=0;
    for (int i=0;i<N;++i){
        int n = letters[order[i]];
        if (n % (N-i) != 0) {
            cout << "-1\n";
            return;
        } else {
            len += n/(N-i);
        }
    }
    reverse(order.begin(),order.end());
    string s = t.substr(0,len);
    if (!simulate(s, order, t)){
        cout << "-1\n";
        return;
    }
    cout << s << " ";
    for (int i=0;i<N;++i) cout << order[i];
    cout << endl;
}

int main(){
    int t; cin >> t;
    while (t--)
    solve();
    return 0;
}