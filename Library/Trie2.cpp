#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
struct Trie{
    vector<vector<int> > T;
    vector<bool> Last;
    int next;
    Trie(){
        T.clear();
        Last.clear();
        T.push_back(vector<int>(26,-1));
        Last.push_back(0);
        next = 1;
    }
    void addNode(){
        T.push_back(vector<int>(26,-1));
        Last.push_back(0);
    }
    void insert_(string s){
        int i = 0, v = 0;
        while(i < s.size()){
            if(T[v][s[i] - 'a'] == -1){
                addNode();
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


