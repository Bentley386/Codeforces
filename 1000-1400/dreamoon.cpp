#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<unordered_set>

using namespace std;

// https://codeforces.com/contest/1330/problem/B

typedef long long  ll;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int t,n;
    vector<int> ints;
    unordered_set<int> s,possiblePerm;
    int res,max;
    vector<int> indices;
    cin >> t;
    while (t--){
        indices = vector<int>();
        max=0, res=0;
        cin >> n;
        ints = vector<int>(n);
        s=unordered_set<int>(), possiblePerm = unordered_set<int>();
        for (int i=0;i<n;i++) cin >> ints[i];
        for (int i=0;i<n;i++) {
            if (s.count(ints[i]) > 0) break;
            else {
                if (ints[i]> max) max = ints[i];
                s.insert(ints[i]);
                if (max == i+1) possiblePerm.insert(i);
            }
        }
        max = 0;
        s = unordered_set<int>();
        for(int i=n-1;i>=0;i--){
            if (s.count(ints[i]) > 0 ) break;
            else{
                if (ints[i] > max) max = ints[i];
                s.insert(ints[i]);
                if (max == n-i && possiblePerm.count(i-1) > 0) {
                    res++;
                    indices.push_back(i-1);
                }
            }
        }
        cout << res << endl;
        if (res>0){
            for (int i : indices) cout << i+1 << " " << n-i-1 << endl;
        }
    }
    return 0;
}