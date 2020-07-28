#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<unordered_set>

using namespace std;
typedef long long  ll;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int n,k;
    cin >> n >> k;
    vector<int> ints(n);
    for(int i=0;i<n;i++) cin >> ints[i];
    //povecujem mediano dokler je pod stvarjo nad njo, pol poecujem se tisto
    sort(ints.begin(),ints.end());
    int median = n/2;
    int i;
    if (n==1){
        cout << ints[median]+k << endl;
        return 0;
    }
    while (k--){
        if (ints[median] < ints[median+1]) ints[median]++;
        else {
            ints[median+1]++;
            i=2;
            while(median+i<n && ints[median+i] == ints[median]){
                if (k==0) break;
                ints[median+i]++;
                i++;
                k--;
            }
        }
    }
    cout << ints[median] << endl;
    return 0;
}