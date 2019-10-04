#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
#define oo 1000000000
using namespace std;
int n;
double x, y, res = 0, ind = 0;
int main(){
    while(true){
        cin >> n;
        if(n == 0)break;
        res = 0;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            if(min(x, y) / 2 > res || min(min(x, y), max(x, y) / 4) > res){
                res = max(min(x, y) / 2, min(min(x, y), max(x, y) / 4));
                ind = i + 1;
            }
        }
        cout << ind << endl;
    }
}


