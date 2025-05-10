#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>

using namespace std;

// https://codeforces.com/contest/1311/problem/B

typedef long long int li;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int t,n,m,temp;
    int currentmin;
    vector<int> as,ps;

    cin >> t;
    next:while (t--){
        cin >> n >> m; // 5 2
        as = vector<int>(n);
        for(int i=0;i<n;i++) cin >> as[i]; //26 39 72 31 68
        ps = vector<int>(m);
        for(int i=0;i<m;i++) cin >> ps[i]; //3 2

        for (int i=0; i<n; i++){
            currentmin = min_element(as.begin()+i,as.end())-as.begin();
            if (currentmin>i){
                for (int j=i;j<currentmin;j++){
                    if(find(ps.begin(),ps.end(),j+1) == ps.end()) {
                        puts("NO");
                        goto next;
                    }
                }
                as[currentmin] = as[i];
                temp = as[currentmin];
                as[i] = temp;
            }
        }
        puts("YES");
    }

    return 0;
}