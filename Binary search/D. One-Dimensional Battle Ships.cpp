#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
const int len = 2e5 + 9;
int n, k, aa, m, x, a[len];
bool Here[len];
bool valid(int mid){
    for(int i = 0; i < len; i++)Here[i] = false;
    for(int i = 0; i <= mid; i++){
        Here[a[i]] = true;
    }
    int cou = 0;
    int now = 0;
    for(int i = 1; i <= n; i++){
        if(!Here[i]){
            now++;
            if(now == aa){
                now = 0;
                cou++;
                i++;
            }
        }else {
            now = 0;
        }
    }
    if(now == aa)cou++;
    if(cou < k){
        return true;
    }else {
        return false;
    }
}
int binSer(){
    int be = 0, ed = m - 1, mid, res = -2;
    while(be <= ed){
        mid = (be + ed)/2;
        if(valid(mid)){
            res = mid;
            ed = mid - 1;
        }else{
            be = mid + 1;
        }
    }
    return res + 1;
}
int main() {
    scanf("%d %d %d %d", &n, &k, &aa, &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &a[i]);
    }
    printf("%d", binSer());
}

