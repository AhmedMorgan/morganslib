#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
const int MAX = 2000;
char st[MAX];
char z[30];
int len, k;
struct Trie{
    vector<map<char,int> > T;
    vector<bool> Last;
    int next;
    Trie(){
        T.clear();
        Last.clear();
        T.push_back(map<char,int>());
        Last.push_back(0);
        next = 1;
    }
    void addNode(){
        T.push_back(map<char,int>());
        Last.push_back(0);
    }
    int insert_(int idx){
        int i = idx, v = 0, cou = 0;
        int tillNow = 0;
        while(i < len){
            if(!T[v].count(st[i])){
                addNode();
                T[v][st[i]] = next;
                v = next;
                if(z[st[i] - 'a'] == '0'){
                    tillNow++;
                }
                if(!Last[v] && tillNow <= k)cou++;
                Last[v] = true;
                next++;

            }else {
                v = T[v][st[i]];
                if(z[st[i] - 'a'] == '0'){
                    tillNow++;
                }
            }
            i++;
        }
        return cou;
    }
    bool find_(string s){
        int i = 0, v = 0;
        while(i < s.size()){
            if(!T[v].count(s[i])){
                return false;
            }else {
                v = T[v][s[i]];
            }
            i++;
        }
        return Last[v];
    }
};
int main() {
    scanf("%s",st);
    len = strlen(st);
    scanf("%s",z);
    scanf("%d", &k);
    Trie t;
    int res = 0;
    for(int i = 0; i < len; i++){
        res += t.insert_(i);
    }
    printf("%d", res);
}
