#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

using namespace std;
typedef long long  ll;

int main(){
    int N,Q, CanReachX[100010],CanReachY[100010],ra,ca,rb,cb,first,second;

    cin >> N >> Q;
    CanReachX[0] = 0; //CanReachX[i] tells us the leftmost column we can reach from ith column
    cin >> first;
    for (int i=1;i<N;i++) {
        cin >> second;
        if ((second-first) % 2 == 0) CanReachX[i] = CanReachX[i-1];
        else CanReachX[i] = i;
        first = second;
    }
    cin >> first;
    CanReachY[0] = 0;  //CanReachY[i] tells us the uppermost row we can reach from ith row
    for (int i=1;i<N;i++){
        cin >> second;
        if ((second-first) % 2 == 0) CanReachY[i] = CanReachY[i-1];
        else CanReachY[i] = i;
        first = second;
    }

    while (Q--){
        cin >> ra >> ca >> rb >> cb;
        if (ra > rb) swap(ra,rb);
        if (ca > cb) swap(ca,cb);
        if ((CanReachX[rb-1] <= ra-1) && (CanReachY[cb-1] <= ca-1)) cout << "YES\n";
        else cout << "NO\n";     
    }

    return 0;
}
