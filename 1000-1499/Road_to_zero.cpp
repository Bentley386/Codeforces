#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long int li;

li solve(li x, li y, li a, li b);

int main(){
    li t,x,y,a,b;
    cin >> t;
    while (t--){
        cin >> x >> y >> a >> b;
        cout << solve(x,y,a,b) << endl;
    }

    return 0;
}

li solve(li x, li y, li a, li b){
    if (2*a <= b) return a*(x+y);
    if (x<y) return b*x + a*(y-x);
    return b*y + a*(x-y); 
}
