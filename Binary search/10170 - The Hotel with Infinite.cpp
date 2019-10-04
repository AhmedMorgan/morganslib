#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
ll s, k;
bool valid(ll mid){
    ll one = (mid) * (mid + 1) /2;
    ll two =(s - 1) * (s) / 2;
    if(one - two >= k) return true;
    return false;
}
ll binSer(){
    ll be = s, ed = 1e8, mid, res = -1;
    while(be <= ed){
        mid =(be + ed)/2;
        if(valid(mid)){
            res = mid;
            ed = mid - 1;
        }else{
            be = mid + 1;
        }
    }
    return res;
}
int main() {
    while(cin >> s >> k){
        printf("%lld\n", binSer());
    }
}


