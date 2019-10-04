#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int valid(ll x, ll i){
    ll test = i * i * i - x * x * x;
    if(test == n)return 0;
    else if(test < n)return 1;
    else return -1;
}
ll binSer(ll i){
    ll be = 1, ed = 100000, mid, res = -1;
    while(be <= ed){
        mid = (be + ed)/2;
        ll test = valid(mid, i);
        if(test == 1){
            ed = mid - 1;
        }else if(test == 0){
            res = mid;
            return mid;
        }else {
            be = mid + 1;
        }
    }
    return res;
}
int main(){
    while(true){
        scanf("%lld", &n);
        if(n == 0)break;
        bool notdone = true;
        for(ll i = 1; i <= n; i++){
            ll res = binSer(i);
            if(res != -1){
                printf("%lld %lld\n", i, res);
                notdone = false;
                break;
            }
        }
        if(notdone){
            printf("No solution\n");
        }
    }
}
