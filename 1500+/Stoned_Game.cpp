#include<bits/stdc++.h>


#define INF 100000000
#define MOD 998244353

using namespace std;
typedef long long  ll;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int previous=1000;
        for (int i=0;i<n;i++) cin >> a[i];
        int i=0;
        for(;;i++){
            int maxi = max_element(a.begin(),a.end())-a.begin();
            if (a[maxi]==0) break;
            else {
                if (previous != maxi) {
                    a[maxi]--;
                    previous=maxi;
                } else {
                    int maxi2=1000;
                    int val=0;
                    for (int j=0;j<n;j++){
                        if (j==previous) continue;
                        if (a[j]>val) {
                            maxi2=j;
                            val=a[j];
                        }
                    }
                    if (maxi2==1000) break;
                    a[maxi2]--;
                    previous = maxi2;
                }
            }
        }
        if (i%2==0) cout << "HL\n";
        else cout << "T\n";
    }
    return 0;
}

