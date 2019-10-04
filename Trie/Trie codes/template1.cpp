#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
const int MAX = 10009;
struct Trie{
    int T[MAX][26];
    bool Last[MAX];
    int next;
    Trie(){
        memset(T,-1,sizeof(T));
        next = 1;
    }
    void insert_(string s){
        int i = 0, v = 0;
        while(i < s.size()){
            if(T[v][s[i] - 'a'] == -1){
                T[v][s[i] - 'a'] = next;
                v = next;
                next++;
            }else {
                v = T[v][s[i] - 'a'];
            }
            i++;
        }
        Last[v] = true;
    }
    bool find_(string s){
        int i = 0, v = 0;
        while(i < s.size()){
            if(T[v][s[i] - 'a'] == -1){
                return false;
            }else {

                v = T[v][s[i] - 'a'];
            }
            i++;
        }
        return Last[v];
    }
};
int main() {
    Trie t;
    t.insert_("ahmed");
    cout << t.find_("ahmed") << endl;
    cout << t.find_("ahme") << endl;
    cout << t.find_("ahmedd") << endl;
    t.insert_("ahmedd");
    cout << t.find_("ahmedd") << endl;

}

