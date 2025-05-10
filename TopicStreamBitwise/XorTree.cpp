#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/344975/problem/J

typedef long long  ll; 

int solveBit(vector<int>& relevant, int depth){
    vector<int> zeros = vector<int>();
    vector<int> ones = vector<int>();
    for (int x : relevant) {
        if ((1<<depth & x) != 0) ones.push_back(x);
        else zeros.push_back(x);
    }
    if (zeros.size() < 2){
        if (ones.size()<2) return 0;
        return solveBit(ones,depth-1);
    } else if (ones.size() < 2){
        return solveBit(zeros,depth-1);
    } else {
        int first = solveBit(ones,depth-1);
        int second = solveBit(zeros,depth-1);
        return min(first+zeros.size()-1,second+ones.size()-1);
    }

}

int main(){
    int n;
    cin >> n;
    vector<int> a(n); //a[i] < 10^9 < 2^30. Maxdepth=29
    for (int i=0;i<n;++i) scanf("%d",&a[i]); 
    cout << solveBit(a,29) << "\n";

    return 0;
}