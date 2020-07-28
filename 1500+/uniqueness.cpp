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

int tryIt (vector<int> ints, int n,bool right);

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int n;
    cin >> n;
    vector<int> ints(n);
    for( int i=0;i<n;i++) cin >> ints[i];
    unordered_set<int> left,right;
    int minim=n;
    for (int l=-1;l<n;l++){
        //cout << "min: " << minim << endl;
        //cout << "l: " << l << endl;
        if (l>=0){
            if (left.count(ints[l]) > 0){
                minim = min(minim,n-l);
                break;
            }
            left.insert(ints[l]);
        }
        right.clear();
        for(int r=n-1;r>=l;r--){
            //cout << "r: " << r << endl;
            if (r==l) {
                minim=0;
                break;
            }
            if (right.count(ints[r])>0 || left.count(ints[r])>0){
                minim = min(minim,r-l);
                break;
            }
            right.insert(ints[r]);
        }
    }
    cout << minim << endl;
    return 0;
}