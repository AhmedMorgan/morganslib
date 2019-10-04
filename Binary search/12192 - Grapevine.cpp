#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
const int len = 509;
int a[len][len], n, m, l, r, q;
bool valid2(int in, int x, int mid){
    if(a[in][mid] >= x)return  true;
    return false;
}
bool binarySearch(int in, int x, int y, int length){
    int be = 0, ed = m - 1, mid, res = -1;
    while(be <= ed){
        mid = (be + ed)/2;
        if(valid2(in, x, mid)){
            res = mid;
            ed = mid - 1;
        }else {
            be = mid + 1;
        }
    }
    if(res == -1) return false;
    if(in + length - 1 < n && res + length - 1 < m){
        if(a[in + length - 1][res + length - 1] <= y)return true;
    }
    return false;
}
bool valid(int x, int y, int length){
    for(int i = 0; i < n; i++){
       if(binarySearch(i, x, y, length)){
            return true;
       }
    }
    return false;
}
int binSer(int x, int y){
    int be = 1, ed = min(n, m), mid, res = 0;
    while(be <= ed){
        mid = (be + ed)/2;
        if(valid(x, y, mid)){
            res = mid;
            be = mid + 1;
        }else {
            ed = mid - 1;
        }
    }
    return res;
}
int main() {
    while(true){
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0)break;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &a[i][j]);
            }
        }
        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            scanf("%d %d", &l, &r);
            printf("%d\n", binSer(l, r));
        }
        printf("-\n");

    }
}
