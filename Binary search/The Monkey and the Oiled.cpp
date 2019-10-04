#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int len = 1e5 + 9;
ll n, a[len];
bool valid(ll x){
    for(int i = 1; i <= n; i++){
        if(a[i] - a[i - 1] == x ){
            x--;
        }else if(a[i] - a[i - 1] > x) {
            return false;
        }
    }
    if(x < 0){
        return false;
    }else {
        return true;
    }
}
ll binSer(){
    ll be = 0, ed = 1000000000000009, mid, res = -1;
    while(be <= ed){
        mid = (be + ed)/2;
        if(valid(mid)){
            res = mid;
            ed = mid - 1;
        }else {
            be = mid + 1;
        }
    }
    return res;
}
int main(){
    int t;
    scanf("%d", &t);
    for(int cases = 1; cases <= t; cases++){
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
        }
        printf("Case %d: %lld\n", cases, binSer());
    }
}
