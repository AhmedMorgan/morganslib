
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
const int len = 2e6 + 5;
string str;
stack<char> s;
int slen;
int main(){
    int t;
    scanf("%d", &t);
    for(int u = 1; u <= t; u++){
        while(!s.empty()) s.pop();
        cin >> str;
        char x,y,z;
        if(str[0] == '0') s.push('f');
        else {
            for(int i=0;i<str.size() - 1;i++)
            {
                if(str[i] == '1'){
                    s.push('1');
                }else {
                    if(str[i] == )
                }

            }
        }
        if(s.empty()){
            printf("Case %d: yes\n", u);
        }else {
            printf("Case %d: no\n", u);

        }
    }
    return 0;
}
