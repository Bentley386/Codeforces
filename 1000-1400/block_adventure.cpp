#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>

using namespace std;

// https://codeforces.com/contest/1200/problem/B

typedef long long int li;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    li t,n,m,k,hcurr,hnext;
    bool check;
    cin >> t;
    next:while (t--){
        check=true;
        cin >> n >> m >> k;
        cin >> hcurr;

        for (int i=1;i<n;i++){
            cin >> hnext;
            if (hcurr >= hnext-k) {
                m += min(hcurr-hnext+k,hcurr);
                hcurr = hnext;
                continue;
            } 
            m -= hnext-k-hcurr;
            hcurr = hnext;
            if (m<0) {
                check = false;
            }
        }
        if (check) puts("YES");
        else puts("NO");
    }
    return 0;
}