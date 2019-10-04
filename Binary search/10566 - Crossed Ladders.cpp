#include<bits/stdc++.h>
#define ll long long
using namespace std;
double x, y, c;
bool valid(double mid){

}
double binSer(){
    double be = 0, ed = 1e9, mid, res = -1;
    for(int i = 0; i < 200; i++){
        mid = (be + ed) /2;
        if(valid(mid)){
            res = mid;
            be = mid;
        }else {
            ed = mid;
        }
    }
    return res;
}
int main(){
    while(cin >> x >> y >> c){
        printf("%1.6f\n", binSer());
    }
}

