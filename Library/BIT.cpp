#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
const int len = 1e5 + 5;
int a[len], n, q, BIT[len];
int GET(int idx){
    int sum = 0;
    while(idx){
        sum += BIT[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void SET(int idx, int val){
    while(idx < len){
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}
int RES(int st, int ed){
    return GET(ed) - GET(st - 1);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        SET(i, a[i]);
    }
    scanf("%d", &q);
    while(q--){
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", RES(x, y));
    }
}
