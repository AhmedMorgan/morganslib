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
        next++;
    }
    void insert_(string s){
        int i = 0, v = 0;
        while(i < s.size()){
            if(!T[v].count(s[i])){
                T[v][s[i]] = next;
                v = next;
                addNode();
            }else {
                v = T[v][s[i]];
            }
            i++;
        }
        Last[v] = true;
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
    Trie t;
    t.insert_("ahmed");
    cout << t.find_("ahmed") << endl;
    cout << t.find_("ahme") << endl;
    cout << t.find_("ahmedd") << endl;
    t.insert_("ahmedd");
    cout << t.find_("ahmedd") << endl;

}



