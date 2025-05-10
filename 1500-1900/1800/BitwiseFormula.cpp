#include<bits/stdc++.h>
 
#define INF 2000000000000000ll
#define MOD 998244353
using namespace std;
typedef long long  ll;
 
int sums0[5001];
int sums1[5001];
 
string myBinary(string x, string y, string Op, int m){
    for (int i=0;i<m;++i){
        if (Op=="AND"){
            if (x[i]=='0' || y[i]=='0') x[i]='0';
            else x[i]='1';
        } else if (Op == "OR"){
            if (x[i] == '0' && y[i] == '0') x[i]='0';
            else x[i]='1';
        } else if (Op == "XOR"){
            if (x[i] == y[i]) x[i] = '0';
            else x[i] = '1';
        }
    }
    return x;
}

int main(){
    int n,m;
    cin >> n >> m;
    map<string,string> variables0;
    variables0["?"] = string(m,'0');
    map<string,string> variables1;
    variables1["?"] = string(m,'1');

    for (int i=0;i<n;++i){
        string curr;
        getline(cin >> ws, curr);
        vector<string> result;
        istringstream iss(curr);
        for (string s; iss >> s;) result.push_back(s);
        if (result.size() == 3) {
            variables0[result[0]] = result[2];
            variables1[result[0]] = result[2];
        } else {
            string x = variables0[result[2]];
            string y = variables0[result[4]];
            curr = myBinary(x,y,result[3],m);
            variables0[result[0]] = curr;
            for (int i=0;i<m;++i){
                if (curr[i]=='1') sums0[i]++;
            }
            x = variables1[result[2]];
            y = variables1[result[4]];
            curr = myBinary(x,y,result[3],m);
            variables1[result[0]] = curr;
            for (int i=0;i<m;++i){
                if (curr[i]=='1') sums1[i]++;
            }
        }
    }
    for (int i=0;i<m;++i) {
        if (sums0[i]==sums1[i]) cout << "0";
        else if (sums0[i] < sums1[i]) cout << "0";
        else cout << "1";
    }
    cout << "\n";
    for (int i=0;i<m;++i) {
        if (sums0[i]==sums1[i]) cout << "0";
        else if (sums0[i] < sums1[i]) cout << "1";
        else cout << "0";
    }
    cout << "\n";
    return 0;
}