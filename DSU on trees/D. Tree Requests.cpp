#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
const int len = (5e5 + 9)*2;
int n, x, y, m;
char s[len];
int sz[len];
int lev[len];
int cnt[len][30];
vector<int> *vec[len];
vector<vector<int> > g(len, vector<int>());
vector<vector<pair<int,int> > > need(len, vector<pair<int,int> > ());
string res[len];
int dfsz(int v, int p){
    sz[v] = 1;
    for(auto u : g[v]){
        if(u != p){
            sz[v] += dfsz(u, v);
        }
    }

    return sz[v];
}
void dfsForLevel(int v, int p, int level){
    lev[v] = level;
    for(auto u : g[v]){
        if(u != p){
            dfsForLevel(u, v, level + 1);
        }
    }
}
void dfs(int v, int p, bool keep){
    int num = -1, big = -1;
    for(auto u : g[v]){
        if(u != p){
            if(sz[u] > num){
                num = sz[u];
                big = u;
            }
        }
    }
    for(auto u : g[v]){
        if(u != p && u != big){
            dfs(u, v, 0);
        }
    }
    if(big != -1){
        dfs(big, v, 1), vec[v] = vec[big];
    }else {
        vec[v] = new vector<int>();
    }
    vec[v]->push_back(v);
    cnt[lev[v]][s[v - 1] - 'a']++;
    for(auto u : g[v]){
        if(u != p && u != big){
            for(auto x : *vec[u]){
                vec[v]->push_back(x);
                cnt[lev[x]][s[x - 1] - 'a']++;
            }
        }
    }
    for(auto x : need[v]){
        int fir = x.first;
        int sec = x.second;
        int test = 0;
        bool yes = 0;
        for(int i = 0; i < 26; i++){
               test += (cnt[ fir][i]) % 2;

        }
        if(test > 1){
            res[sec] = "No";
        }else {
            res[sec] = "Yes";
        }
    }
    if(!keep){
        for(auto u : *vec[v]){
            cnt[lev[u]][s[u - 1] - 'a']--;
        }
    }

}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 2; i <= n; i++){
        scanf("%d", &x);
        g[i].push_back(x);
        g[x].push_back(i);
    }
    scanf("%s", s);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &x, &y);
        need[x].push_back(mp(y, i));
    }
    dfsz(1, -1);
    dfsForLevel(1, -1, 1);
    dfs(1, -1, 1);

    for(int i = 0; i < m; i++){
        cout << res[i] << endl;
    }
}

