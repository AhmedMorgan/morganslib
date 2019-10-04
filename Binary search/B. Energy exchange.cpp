#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
int n;
const int len = 1e4 + 9;
double a[len], k;
bool valid(double mid){
    double balance = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < mid){
            balance -= (mid - a[i]);
        }else {
            balance += (a[i] - mid) - ((a[i] - mid) * k)/100.0;
        }
    }
    if(balance >= 0) return true;
    else return false;
}

double binSer(){
    double be = 0, ed = 1000, mid , res = -1;
    for(int i = 0; i < 200; i++){
        mid = (be + ed)/2;
        if(valid(mid)){
            res = mid;
            be = mid;
        }else {
            ed = mid;
        }
    }
    return res;
}
int main() {
    scanf("%d %lf", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%lf", &a[i]);
    }
    printf("%1.9f", binSer());
}
