#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

#define INF 1000000000

using namespace std;
typedef long long  ll;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int q,n;
    ll k;
    string chars;
    cin >> q;
    while(q--){
        cin >> n >> k;
        cin >> chars;
        int numzero=0;
        int numone=0;
        for (int i=0;i<n;i++){
            if (chars.at(i) == '1') {
                numone++;
                continue;
            }
            if (numone > k) break;
            k-=numone;
            numzero++;
        }
        int pos=INF;
        int i = numzero+numone;
        while(i<n){
            if (chars.at(i) == '0'){
                pos = i;
                break;
            }
            i++;
        }

        for(int i=0;i<numzero;i++) cout << '0';
        if (pos==INF){
            for(int i=0;i<numone;i++) cout << '1';
            for(int i=numzero+numone;i<n;i++) cout << chars[i];
        } else {
            int leftone = pos-k-numzero;
            for(int i=0;i<leftone;i++) cout << '1';
            cout << '0';
            for(int i=0;i<numone-leftone;i++) cout << '1';
            i = numzero+numone+1;
            while(i<n){
                cout << chars[i];
                i++;
            }
        }
        cout << "\n";
    }
    return 0;
}