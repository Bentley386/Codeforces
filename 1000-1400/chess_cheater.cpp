#include<bits/stdc++.h>
 
#define INF 1000000000
#define MOD 998244353
using namespace std;

// https://codeforces.com/contest/1427/problem/B

typedef long long  ll;
 
bool games[100005];
 
int main(){
    int t,n,k;
    cin >> t;
    int num=1;
    while (t--){
        cin >> n >> k;
        char c;
        scanf("%c",&c);
        vector<pair<int,int>> segments;
        int howmany=0;
        for (int i=0;i<n;++i){
            scanf("%c",&c);
            if (c=='W') {
                games[i] = true;
                if (howmany>0) {
                    segments.push_back({howmany,i});
                    howmany=0;
                }
            }
            else {
                games[i] = false;
                howmany++;
            }
        }
        if (howmany>0){
            segments.push_back({howmany,n});
        }
 
        bool prev;
        int score=0;
        if (games[0]){
            prev = true;
            score++;
        } else {
            prev = false;
        }
 
        for (int i=1;i<n;++i){
            if (games[i]){
                if (prev) score+=2;
                else score++;
                prev=true;
            } else prev=false;
        }
 
        sort(segments.begin(),segments.end(), [&](pair<int,int> &a, pair<int,int> &b){
            if (a.second >=n || a.second-a.first-1 < 0) return false;
            if (b.second >=n || b.second-b.first-1 < 0) return true;
            return (a.first < b.first);
        });
 
        for (auto x : segments){
            if (k<1) break;
            int before = x.second-x.first-1;
            int after = x.second;
 
            if (k>=x.first) k-= x.first;
            else {
                score+= (before<0 && after>= n) ? 2*k-1 : 2*k;
                break;
            }       
 
 
            score += x.first*2+1;
            if (before<0) score--;
            if (after >= n) score--;
        }
        cout << score << "\n";
        num++;
    }
    return 0;
}