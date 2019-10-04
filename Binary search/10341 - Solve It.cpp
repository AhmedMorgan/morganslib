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
double p, q, r, s, t, u;
bool valid(double mid){
    double balance = p * exp(-1 * mid) + q * sin(mid) + r * cos(mid) + s * tan(mid) + t * mid * mid + u;

    if(balance >= 0) return true;
    else return false;
}

double binSer(){
    if((p + r + u < 0 && p * exp(-1) + q * sin(1) + r * cos(1) + s * tan(1) + t + u < 0 )||(p + r + u > 0 && p * exp(-1) + q * sin(1) + r * cos(1) + s * tan(1) + t + u > 0)){
        return -1;
    }
    double zero = p + r + u;
    double one = p * exp(-1) + q * sin(1) + r * cos(1) + s * tan(1) + t + u;
    if(zero < 0){
        double be = 0, ed = 1, mid , res = 0;
        for(int i = 0; i < 200; i++){
            mid = (be + ed) / 2;
            if(valid(mid)){
                ed = mid;
                res = mid;
            }else{
                be = mid;
            }
        }
        return res;
    }else{
        double be = 0, ed = 1, mid , res = 0;
        for(int i = 0; i < 200; i++){
            mid = (be + ed) / 2;
            if(valid(mid)){
                be = mid;
                res = mid;
            }else{
                ed = mid;
            }
        }
        return res;
    }
}
int main() {
    while(cin >> p >> q >> r >> s >> t >> u){
        double res = binSer();
        if(res == -1){
            printf("No solution\n");
        }else {
            printf("%1.4f\n", res);
        }
    }
}
