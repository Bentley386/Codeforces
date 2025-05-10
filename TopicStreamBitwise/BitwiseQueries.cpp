#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;

// https://codeforces.com/gym/344975/problem/K

typedef long long  ll; 


int main(){
    int n;
    cin >> n;
    vector<int> xors(n+1);
    xors[0]=-1; xors[1]=0;
    map<int,int> values;
    int firstsame=-1, secondsame=-1;
    for (int curr,i=2;i<=n;++i) {
        cout << "XOR 1 " << i << endl;
        cin >> curr;
        xors[i] = curr;
        if (firstsame == -1){
            if (curr==0) {
                firstsame=1;
                secondsame=i;
            } else if (values.count(curr)){
                firstsame = values[curr];
                secondsame=i;
            }
        }
        values[curr]=i;
    } //n-1 queries

    //a ^ x1 = a ^ x2 -> x1=x2
    int first;
    if (firstsame != -1){
        cout << "AND " << firstsame << " " << secondsame << endl;
        int known;
        cin >> known;

        if (firstsame == 1) first = known;
        else first = known^xors[firstsame];
    } else {
        //x+y = x^y+2(x&y).  a+b=x, a+c=y, b+c=z  a=(x+y-z)/2
        int a=1;
        int b = max_element(xors.begin(),xors.end()) - xors.begin();
        int c = (b==n) ? n-1 : b+1;
        int x = xors[b]; //a&b=0
        int y;
        cout << "AND 1 " << c << endl;
        cin >> y;
        y = xors[c] + 2*y;
        int z;
        cout << "AND " << b << " " << c << endl;
        cin >> z;
        z = (xors[b]^xors[c])+2*z;
        first = (x+y-z)/2;
    }
    cout << "! " << first << " ";
    for (int i=2;i<=n;++i){
        cout << (xors[i]^first) << " ";
    }
    cout << endl;

    return 0;
}