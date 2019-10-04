#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
const int len = 5e4 + 9;
int n, k, x, y;
vector<int> *vec[len];
int cnt[len * 2];
int cnt1[len * 2];
int lev[len];
int siz[len];
ll res = 0;
vector<vector<int> > g(len, vector<int>());
void dfsForLevel(int v, int p, int level){
    lev[v] = level;
    for(auto u: g[v]){
        if(u != p)
        dfsForLevel(u, v, level + 1);
    }

}
int dfssz(int v, int p){
    int sum = 1;
    for(auto u : g[v]){
        if(u != p)
        sum += dfssz(u, v);
    }
    siz[v] = sum;
    return sum;
}
void dfs(int v, int p, bool keep){
    int sz = -1, mx = -1;
    for(auto u : g[v]){
        if(u != p && siz[u] > sz){
            sz = siz[u];
            mx = u;
        }
    }
    for(auto u : g[v]){
        if(u != p && u != mx){
            dfs(u, v, 0);
        }
    }
    if(mx != -1) dfs(mx, v, 1), vec[v] = vec[mx];
    else vec[v] = new vector<int>();
    vec[v]->push_back(v);
    cnt[ lev[v] ]++;

    for(auto u : g[v]){
        if(u == mx || u == p)continue;
        for(auto x : *vec[u]){
            cnt1[ lev[x] ]++;
            vec[v]->push_back(x);
        }
        for(int i = 1; i <= k; i++){
            res += cnt[ lev[v] + i ] * cnt1[ lev[v] + k - i ];
        }
        for(auto x : *vec[u]){
            cnt1[ lev[x] ]--;
            cnt[lev[x]]++;
        }
    }


    res += cnt[lev[v] + k];

    if(!keep){
         for(auto u : *vec[v]){
            cnt[ lev[u] ]--;

         }
    }

}
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfsForLevel(1, -1, 0);
    dfssz(1, -1);
    dfs(1, -1, 1);
    printf("%lld", res);
}
