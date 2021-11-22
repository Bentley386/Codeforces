#include<bits/stdc++.h>

#define INF 1000000000
#define MOD 998244353
using namespace std;
typedef long long  ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> prefix(n+1);
    prefix[0]=0;
    for (int i=0;i<n;++i) {
        scanf("%d",&a[i]);
        prefix[i+1] = prefix[i]+a[i];
    }
    map<int,pair<int,int>> segments;
    int curr;
    pair<int,int> currpair;
    int maxi=1;
    for (int r=1;r<=n;++r){
        for (int l=0;l<r;++l){
            curr=prefix[r]-prefix[l];
            if(segments.count(curr) == 0){
                segments[curr] = {1,r};
            } else {
                currpair = segments[curr];
                if (currpair.second <= l){
                    segments[curr] = {currpair.first+1,r};
                    maxi = max(currpair.first+1,maxi);
                }
            }
        }
    }
    if (maxi==1){
        cout << 1 << endl;
        cout << "1 1";
        return 0;
    }
    for (auto x : segments){
        if (x.second.first == maxi){
            curr = x.first;
            maxi = x.second.first;
            break;
        }
    }
    int prev=0;
    cout << maxi << endl;
    for (int r=1;r<=n;++r){
        for (int l=prev;l<r;++l){
            if(prefix[r]-prefix[l] == curr) {
                cout << l+1 << " " << r << endl;
                prev=r;
                break;
            }
        }
    }
    return 0;
}