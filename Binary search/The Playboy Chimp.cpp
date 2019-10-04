#include<bits/stdc++.h>
using namespace std;
const int len = 50009;
int n, x, q, ser, low, upper;
int a[len];
int binU(int x){
    int be = 0, ed = n - 1, mid, res = -1;
    while(be <= ed){
        mid = (be + ed)/2;
        if(a[mid] > x){
            res = a[mid];
            ed = mid - 1;
        }else {
            be = mid + 1;
        }
    }
    return res;
}
int binL(int x){
    int be = 0, ed = n - 1, mid, res = -1;
    while(be <= ed){
        mid = (be + ed)/2;
        if(a[mid] < x){
            res = a[mid];
            be = mid + 1;
        }else {
            ed = mid - 1;
        }
    }
    return res;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d", &x);
        low = binL(x);
        upper = binU(x);
        if(low == -1){
            printf("X");
        }else {
            printf("%d", low);
        }
        if(upper == -1){
            printf(" X");
        }else {
            printf(" %d\n", upper);
        }
    }
}
