#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;
const int len = 1e5 + 9;
int a[len], b[len];
bool valid(ll mid){
    int aa = 0, bb = 0;
    while(bb < m){
        while(aa < n){
            if(abs(a[aa] - b[bb]) <= mid){
                aa++;
            }else{
                break;
            }
        }
        bb++;
    }
    if(aa == n && bb == m){
        return true;
    }else {
        return false;
    }
}
int binSer(){
    ll be = 0, ed = 2e9 + 3, mid, res = -1;
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
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &b[i]);
    }
    printf("%d\n", binSer());
}

