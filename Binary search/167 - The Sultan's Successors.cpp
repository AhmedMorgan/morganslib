#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19

using namespace std;
const int len = 1e3 + 9;
int arr[len];
int n, m, x;
int valid(int mid, int x){
    return arr[mid] - x;
}
int bin_ser(int x){
    int low = 0, high = n - 1, mid , res = -1;
    while(low <= high){
        mid = (low + high)/2;
        int test = valid(mid, x);
        if(test == 0){ // check if arr[mid] = x or not
            res = mid;
            return res;
        }else if(test > 0){
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return res; // did not find x and return -1
}
int main() {
    scanf("%d", &n); // assume that n <= len
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &x);
        int res = bin_ser(x);
        if(res == -1){
            printf("Not found\n");
        }else {
            printf("%d is in position : %d\n", x, res);
        }
    }
}
