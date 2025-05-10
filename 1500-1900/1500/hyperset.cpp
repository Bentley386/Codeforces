#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include<unordered_set>

using namespace std;

// https://codeforces.com/contest/1287/problem/B

typedef long long  ll;

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int n,k;
    cin >> n >> k;
    int num=0;
    int ind;
    vector<string> cards(n);
    for (int i=0;i<n;i++) cin >> cards[i];
    if (n<3) {
        cout << 0 << endl;
        return 0;
    }
    string tofind;
    sort(cards.begin(),cards.end());
    for (int i=0;i<n;i++ ){
        for (int j=i+1;j<n;j++){
            tofind="";
            for(int m=0;m<k;m++){
                if (cards[i][m] == cards[j][m]){
                    tofind += cards[i][m];
                } else{
                    if (cards[i][m]!= 'S' && cards[j][m] != 'S') tofind += 'S';
                    else if (cards[i][m] != 'E' && cards[j][m]!= 'E') tofind+= 'E';
                    else tofind+= 'T';
                }
            }
            ind = lower_bound(cards.begin(),cards.end(),tofind)-cards.begin();
            if (ind < n && ind>j &&  cards[ind] == tofind) {
                num++;
            }
        }
    }
    cout << num << endl;
    return 0;
}