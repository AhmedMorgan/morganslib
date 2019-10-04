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
int n, m, v, k;
vector<int> *vec[len];
int cnt[len];
int lev[len];
int sz[len];
int r[len];
bool root[len];
vector<vector<int> >  g(len, vector<int> ());
vector<vector<pair<int,int> > >  need(len, vector<pair<int,int> >());
vector<vector<pair<int,int> > >  need1(len, vector<pair<int,int> >());
int res[len];
priority_queue< pair<int,pair<int,int> > > q;
void dfsForLevel(int node, int p, int level){
    lev[node] = level;
    for(int i = 0; i < g[node].size(); i++){
        if(g[node][i] != p){
            dfsForLevel(g[node][i], node, level + 1);
        }
    }
    while(q.size()){
        if(q.top().first == lev[node]){
            need[node].push_back(mp(q.top().second.first, q.top().second.second));
            q.pop();
        }else{
            break;
        }
    }
    for(int i = 0; i < need1[node].size(); i++){

        q.push(mp(lev[node] - need1[node][i].first,mp(need1[node][i].first,need1[node][i].second)));
       // cout << node << endl;
    }
}
int dfs1(int v, int par){
    sz[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        if(g[v][i] != par){
            sz[v] += dfs1(g[v][i], v);
        }
    }
    return sz[v];
}
void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
           mx = sz[u], bigChild = u;
    for(auto u : g[v])
       if(u != p && u != bigChild)
           dfs(u, v, 0);
    if(bigChild != -1)
        dfs(bigChild, v, 1), vec[v] = vec[bigChild];
    else
        vec[v] = new vector<int> ();
    vec[v]->push_back(v);
    cnt[ lev[v] ]++;
    for(auto u : g[v])
       if(u != p && u != bigChild)
           for(auto x : *vec[u]){
               cnt[ lev[x] ]++;
               vec[v] -> push_back(x);
           }
    //now (*cnt[v])[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    // note that in this step *vec[v] contains all of the subtree of vertex v.
    for(int i = 0; i < need[v].size(); i++){
        int f = need[v][i].first;
        int sec = need[v][i].second;
        if(f + lev[v] < len)
        res[sec] = cnt[f + lev[v]] - 1;

    }
    if(keep == 0)
        for(auto u : *vec[v])
            cnt[ lev[u] ]--;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        cin >> r[i];
        if(r[i] == 0){
            root[i] = true;
        }else {
            g[i].push_back(r[i]);
            g[r[i]].push_back(i);
        }
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &v, &k);
        need1[v].push_back(mp(k, i));
       // cout << need1[v].size() << endl;
    }
    for(int i = 0; i < len; i++){
        if(root[i]){
               // cout << i << endl;
            dfsForLevel(i, -1, 0);
            dfs1(i, -1);
        }
    }
    int cou = 1;
    for(int i = 1; i <= n; i++){
        if(root[i]){
            dfs(i,-1,0);
        }
    }
    for(int i = 0; i < m; i++){
        printf("%d ", res[i]);
    }
}


