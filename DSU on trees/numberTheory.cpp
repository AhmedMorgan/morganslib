#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
int GCD(int a, int b){
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}
void prin(int m){
    if(m & 1){
        for(int i = 2; i < m; i += 2){
            if(GCD(m, i) != 1){
                printf("the gcd of %d and %d is %d so there is no PPT with m = %d and n = %d\n", m, i, GCD(m, i), m, i);
            }else {
                printf("the PPT with m = %d and n = %d is (%d, %d, %d)\n", m, i, (m * m - i * i), 2 * m * i, (m * m + i * i));
            }
        }
    }else {
        for(int i = 1; i < m; i += 2){
            if(GCD(m, i) != 1){
                printf("the gcd of %d and %d is %d so there is no PPT with m = %d and n = %d\n", m, i, GCD(m, i), m, i);
            }else {
                printf("the PPT with m = %d and n = %d is (%d, %d, %d)\n", m, i, (m * m - i * i), 2 * m * i, (m * m + i * i));
            }
        }
    }
}
int main(){
    freopen("output", "w", stdout);
    cout << "Enter m :";
    int m;
    cin >> m;
    cout << endl;
    cout << "m = " << m << endl;
    cout << endl;
    prin(m);
}
