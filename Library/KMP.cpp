#include <bits/stdc++.h>
#define lll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
const int len = 209;
int dp[len][len];
char test[len];
int f[len];
int n, slen;
char s[len];
int balance = 0;
void KMP(){
    f[0] = 0;
    for(int i = 1, j = 0; i< slen; i++){
        while(j && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) ++j;
        f[i] = j;
    }
}
int solve(int idx, int bala){
    if(bala < 0)return 0;
    if(idx == n){
      //  if(bala == 0){
            printf("%s\n", test);
            printf("%s\n\n", s);
      //  }
        bool with = false;
        for(int i = 0, j = 0; i < n; i++){
            while(j && s[j] != test[i]) j = f[j - 1];
            if(test[i] == s[j])j++;
            if(j == slen){with = true; break;}
        }
        if(bala == 0 && with)return 1;
        return 0;
    }

    if(~dp[idx][bala])return dp[idx][bala];
    int res = 0;
    test[idx] = '(';
    res += solve(idx + 1, bala + 1);
    res %= MOD;
    test[idx] = ')';
    res += solve(idx + 1, bala - 1);
    res %= MOD;
    dp[idx][bala] = res;
    return res;
}
int main(){
    scanf("%d", &n);
    n *= 2;
    scanf("%s", s);
    slen = strlen(s);
    KMP();
    for(int i = 0; i < slen; i++)printf("%d ", f[i]);
    printf("\n");

    memset(dp, -1, sizeof dp);
    printf("%d", solve(0, 0));

}

