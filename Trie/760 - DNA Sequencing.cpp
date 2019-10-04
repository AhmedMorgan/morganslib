#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
const int MAX = 3e3 + 9;
char s[2][MAX];
char res[MAX];

int len[3];
struct Trie{
    vector<map<char, int> > t;
    int next;
    Trie(){
        t.clear();
        t.push_back(map<char, int>() );
        next = 1;
    }
    void Tri(){
        t.clear();
        t.push_back(map<char, int>() );
        next = 1;
    }
    void addNode(){
        next++;
        t.push_back(map<char, int>() );
    }
    void insert_(int idx, int ind){
        int v = 0, i = idx;
        while(i < len[ind]){
            if(!t[v].count(s[ind][i])){
                t[v][s[ind][i]] = next;
                v = next;
                addNode();
            }else {
                v = t[v][s[ind][i]];
            }
            i++;
        }
    }
    int find_(int idx, int ind){
        int v = 0, i = idx, cou = 0;
        while(i < len[ind]){
            if(!t[v].count(s[ind][i])){
                return cou;
            }else {
                cou++;
                v = t[v][s[ind][i]];
            }
            i++;
        }
        return cou;
    }
};
Trie first;
Trie second;
void printRes(int ind, int vone, int vtwo){
    if(ind == len[2]){
        for(int i = 0; i < len[2]; i++){
            printf("%c", res[i]);
        }
        printf("\n");
    }
    for(char i = 'a'; i <= 'z'; i++){
        if(first.t[vone].count(i) && second.t[vtwo].count(i)){
            res[ind] = i;
            printRes(ind + 1, first.t[vone][i], second.t[vtwo][i]);
        }
    }
}

int main(){
    bool is = false;
    while(cin >> s[0]){
        first.Tri();
        second.Tri();
        cin >> s[1];
        string m;
        getline(cin, m);
        getline(cin, m);
        if(is){
            printf("\n");
        }
        is = true;

        len[0] = strlen(s[0]);
        len[1] = strlen(s[1]);
        for(int i = 0; i < len[0]; i++){
            first.insert_(i, 0);
        }
        for(int i = 0; i < len[1]; i++){
            second.insert_(i, 1);
        }
        len[2] = 0;
        for(int i = 0; i < len[1]; i++){
            len[2] = max(len[2], first.find_(i, 1));
        }
        if(len[2] == 0){
            printf("No common sequence.\n");
        }else {
            printRes(0, 0, 0);
        }
        memset(s, 0, sizeof s);
    }

}

