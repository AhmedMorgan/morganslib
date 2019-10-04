#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
const int MAX = 2e3 + 9;
char s[MAX];
char be[MAX];
char ed[MAX];
int len, lbe, led, ma;
bool hasBegin[MAX], hasEnd[MAX];
void fillHasBegin(){
    for(int i = 0; i < len; i++){
        bool done = true;
        for(int j = 0; j < lbe; j++){
            if(i + j >= len){
                done = false;
                break;
            }else {
                if(s[i + j] != be[j]){
                    done = false;
                    break;
                }
            }
        }
        hasBegin[i] = done;
    }
}
void fillHasEnd(){
    for(int i = 0; i < len; i++){
        bool done = true;
        for(int j = 0; j < led; j++){
            if(i + j >= len){
                done = false;
                break;
            }else {
                if(s[i + j] != ed[j]){
                    done = false;
                    break;
                }
            }
        }
        if(i + led - 1 < len){
            hasEnd[i + led - 1] = done;
        }
    }
}
struct Trie{
    vector<map<char,int> > t;
    int next;
    vector<bool> last;
    Trie(){
        t.clear();
        last.clear();
        t.push_back(map<char,int>());
        last.push_back(0);
        next = 1;
    }
    void addNode(){
        t.push_back(map<char,int>());
        last.push_back(0);
        next++;
    }
    int insert_(int idx){
        int res = 0, v = 0, i = idx;
        while(i < len){
            if(!t[v].count(s[i])){
                if(hasEnd[i] && i - idx + 1 >= ma){
                    res++;
                }

                t[v][s[i]] = next;
                v = next;
                addNode();
            }else {
                v = t[v][s[i]];
            }
            i++;
        }
        return res;
    }
};
int main(){
    scanf("%s", s);
    len = strlen(s);
    scanf("%s", be);
    lbe = strlen(be);
    scanf("%s", ed);
    led = strlen(ed);
    ma = max(lbe, led);
    Trie t;
    fillHasBegin();
    fillHasEnd();
    int res = 0;
    for(int i = 0; i < len; i++){
        if(hasBegin[i]){
            res += t.insert_(i);
        }
    }
    printf("%d", res);

}
