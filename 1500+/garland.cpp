#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

#define INF 1000000000
#define MOD 998244353
using namespace std;
typedef long long  ll;

int main(){
    int n;
    cin >> n;
    vector<int> bulbs(n);
    vector<pair<int,int>> gaps;
    int even=0,odd=0,numzeros=0;
    bool left=false,right=false;
    for (int i=0;i<n;i++){
        cin >> bulbs[i];
        if (bulbs[i] != 0){
            if (bulbs[i] % 2 == 0) even++;
            else odd++;
            if (numzeros>0) {
                gaps.push_back(make_pair(i-1,numzeros));
                numzeros=0;
            }
        }
        if (bulbs[i]==0) numzeros++;
    }
    if (bulbs[0]==0) left=true;
    if (n==1) {
        cout << 0;
        return 0;
    } else if (n==2){
        cout << 1;
        return 0;
    }

    if (numzeros>0) {
        gaps.push_back(make_pair(n-1,numzeros));
        right=true;
    }

    int complexity=0;
    for (int i=1;i<n;i++){
        if(bulbs[i]!= 0 && bulbs[i-1] != 0 && bulbs[i] % 2 != bulbs[i-1]%2) complexity++;
    }

    if (n%2==0){
        even = n/2 - even;
        odd = n/2 - odd;
    } else {
        even = (n-1)/2 - even;
        odd = (n+1)/2 - odd;
    }

    sort(gaps.begin(), gaps.end(),[](const pair<int,int> &left, const pair<int,int> &right) {
    return left.second < right.second;
});
    for (pair<int,int> x : gaps){
        int start = x.first-x.second;
        if(start<0 || x.first == n-1) continue;
        if (bulbs[start] % 2 != bulbs[x.first+1] % 2) {
            complexity++;
            continue;
        }
        if (bulbs[start] % 2 == 0){
            if(even>=x.second) even -= x.second;
            else complexity+=2;
        }
        if (bulbs[start] % 2 == 1) {
            if(odd >= x.second) odd -= x.second;
            else complexity+=2;
        }
    }

    if (left){
        int i=0;
        while(i<n && bulbs[i] == 0) i++;
        if (i==n) {
            cout << 1;
            return 0;
        }
        if (bulbs[i] % 2 == 0 && i>even) complexity++;
        if (bulbs[i] % 2 == 0 && i<= even) even-=i;
        if (bulbs[i] % 2 == 1 && i>odd) complexity++;
        if (bulbs[i] % 2 == 1 && i<= odd) odd-=i;
    }
    if (right){
        int i=n-1;
        while(i>0 && bulbs[i] == 0) i--;
        if (bulbs[i] % 2 == 0 && n-1-i>even) complexity++;
        if (bulbs[i] % 2 == 1 && n-1-i > odd) complexity++;
    }
    cout << complexity;
    return 0;
}