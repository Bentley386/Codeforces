#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>

using namespace std;

// https://codeforces.com/contest/965/problem/B

typedef long long  ll;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    struct   {
        pair<int,int> coords=make_pair(1,1);
        int number=0;
    } sol;

    int l,n,x,y,num;
    cin >> n >> l;
    vector<string> field(n);
    for (int i=0;i<n;i++) cin >> field[i];

    for (int i=0;i<n;i++){
        for (int j=0; j<n; j++){
            if (field[i][j]=='#') continue;
            if (l==1) {
                sol.coords = make_pair(i+1,j+1);
                continue;
            }
            x=1;
            y=1;
            for  (int k=j-1; k>=std::max(0,j-l+1);k--) {
                if(k<0 || field[i][k] == '#') break;
                x++;
            }
            for (int k=j+1;k<std::min(n,j+l);k++){
                if(k==n || field[i][k] == '#') break;
                x++;
            }
            for  (int k=i-1; k>=std::max(0,i-l+1);k--) {
                if(k<0 || field[k][j] == '#') break;
                y++;
            }
            for (int k=i+1;k<std::min(n,i+l);k++){
                if(k==n || field[k][j] == '#') break;
                y++;
            }
            num = std::max(x-l+1,0) + std::max(y-l+1,0);
            if (num>=sol.number) {
                sol.number = num;
                sol.coords = make_pair(i+1,j+1);
            }
        }
    }
    cout << sol.coords.first << " " << sol.coords.second << "\n";
    return 0;
}