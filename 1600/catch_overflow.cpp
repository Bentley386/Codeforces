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
    ll maxint = pow(2,32)-1;
    int l;
    cin >> l;
    ll result=0;
    bool overflow=false;
    string current;
    vector<ll> loops;
    while (l--){
        cin >> current;
        if (current == "add"){
            if (loops.size()==0) result++;
            else result+=loops[loops.size()-1];
            if (result>maxint) overflow=true;

        } else if (current == "for"){
            int n;
            cin >> n;
            if (loops.size()==0) loops.push_back(n);
            else loops.push_back(min(maxint+1,loops[loops.size()-1]*n));
 
        }
        else if (current == "end") {
            loops.pop_back();
        }
    }
    if (overflow) cout << "OVERFLOW!!!\n";
    else cout << result << endl;
    return 0;
}
