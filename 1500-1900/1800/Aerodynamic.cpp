#include<bits/stdc++.h>


#define INF 100000000
#define MOD 998244353

using namespace std;

// https://codeforces.com/contest/1299/problem/B

typedef long long  ll;


int main(){
    int n;
    cin >> n;
    vector<pair<ll,ll>> vertices(n);
    int x,y;
    for (int i =0;i<n;i++){
        scanf("%d %d",&x,&y);
        vertices[i] = make_pair(x,y);
    }
    if (n%2==1) {
        cout << "NO";
        return 0;
    }
    ll l1,l2,k1,k2;
    for(int i=0;i<n/2;i++){
        l1=pow(vertices[i].second-vertices[(i+1)%n].second,2)+ pow(vertices[i].first-vertices[(i+1)%n].first,2);
        l2=pow(vertices[i+n/2].second-vertices[(i+n/2+1)%n].second,2)+ pow(vertices[i+n/2].first-vertices[(i+n/2+1)%n].first,2);
        if (l1!=l2){
            cout << "NO";
            return 0;
        }
        k1 = (vertices[i+1].second-vertices[i].second)*(vertices[(i+n/2+1)%n].first-vertices[i+n/2].first);
        k2 = (vertices[i+1].first-vertices[i].first)*(vertices[(i+n/2+1)%n].second-vertices[i+n/2].second);
        if (k1!=k2){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}

