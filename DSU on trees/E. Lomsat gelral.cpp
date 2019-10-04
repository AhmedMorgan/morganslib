#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
const int len = 1e5 + 9;
int col[len];
int cnt[len];
int sz[len];
int res[len];
ll finres[len];
int mxnum[len];
vector<vector<int> > g(len, vector<int>());
int n, x, y;
int dfs1(int v, int par){
    sz[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        if(g[v][i] != par){
            sz[v] += dfs1(g[v][i], v);
        }
    }
    return sz[v];
}
vector<int> *vec[len];
void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    int cou = 0, color = -1;
    ll sum = 0;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
           mx = sz[u], bigChild = u;
    for(auto u : g[v])
       if(u != p && u != bigChild){
            dfs(u, v, 0);
       }
    if(bigChild != -1){
        dfs(bigChild, v, 1), vec[v] = vec[bigChild];
        sum += finres[bigChild];
        cou = mxnum[bigChild];
    }else
        vec[v] = new vector<int> ();
        vec[v]->push_back(v);
    cnt[ col[v] ]++;
    if(cnt[col[v]] > cou){
        cou = cnt[col[v]];
        sum = col[v];
    }else if(cnt[col[v]] == cou){
        sum += col[v];
    }
    for(auto u : g[v])
       if(u != p && u != bigChild)
           for(auto x : *vec[u]){
               cnt[ col[x] ]++;
               vec[v] -> push_back(x);
               if(cnt[col[x]] > cou){
                    cou = cnt[col[x]];
                    sum = col[x];
                }else if(cnt[col[x]] == cou){
                    sum += col[x];
                }
           }
    mxnum[v] = cou;
    res[v] = color;
    if(keep == 0)
        for(auto u : *vec[v])
            cnt[ col[u] ]--;
    finres[v] = sum;

}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &col[i + 1]);
    }
    for(int i = 0; i < n - 1; i++){
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(1,0);
    dfs(1, 0, 1);
    for(int i = 1; i <= n; i++){
        printf("%lld ", finres[i]);
    }
}
