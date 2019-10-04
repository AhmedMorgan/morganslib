#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int len = 1e2 + 2;
int sz;
char s[len];

bool valid(int x){
    int k = 0;
    for(int i = 0; i < sz; i += x){
        for(int j = i; j < i + x; j++){
            if(s[j] != s[k])return 0;
            else {
                k++;
            }
        }
        k = 0;
    }
    return true;
}

int main(){
    int n;
    scanf("%d", &n);
    getline(cin, s);
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        sz = strlen(s);
        int res = 0;
        for(int j = 1; j <= sz; j++){
            if(sz % j == 0){
                if(valid(j)){
                    res = j;
                    break;
                }
            }
        }
        printf("%d\n", res);
    }

}
