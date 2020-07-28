#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>

using namespace std;
typedef long long int li;

void solve(li n, li k);

int main(){
    //ifstream input;
    //input.open("test.txt",ios::in);
    int t;
    li n,k;
    cin >> t;
    while (t--){
        cin >> n >> k;
        solve(n,k);
    }
    return 0;
}
li sum(li x){
    return x*(x+1)/2;
}
void solve(li n, li k){  //5 2
    int left = 1; //2
    int right = n; //2
    int mid; //najvecji x, da je sum(x)<=k   -- najmanjsi x, da je sum(x)>k
    while (left <= right){ 
        mid = (left+right)/2; 
        if(sum(mid) >= k && sum(mid-1) < k) break;
        else if (sum(mid) > k) right = mid-1;
        else left = mid+1;
    }
    string rez(n,'a');
    rez[n-1-mid] = 'b';
    rez[n-1-mid+sum(mid)-k+1] = 'b';
    cout << rez << "\n";
}