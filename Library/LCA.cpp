#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
// fools and Roads codeforces
int nodes, x, y;
const int MAX = 2e5 + 9;
vector<vector<pair<int,int> > > g(MAX, vector<pair<int,int> >());
int eulerNodes[MAX];
int eulerLevel[MAX];
int first[MAX];
int last[MAX];
int cur = 0;
int balance[MAX];
int res[MAX];
void init(){
    cur = 0;
    for(int i = 0; i < MAX; i++){
        g[i] = vector<pair<int,int> >();
        eulerLevel[i] = 0;
        eulerNodes[i] = 0;
        first[i] = 1e9;
        last[i] = -1;
        balance[i] = 0;
    }
}
void dfs(int u, int par, int lev){
    eulerLevel[cur] = lev;
    eulerNodes[cur] = u;
    first[u] = min(first[u], cur);
    last[u] = max(last[u], cur);
    cur++;
    for(auto v : g[u]){
        if(v.first == par)continue;
        dfs(v.first, u, lev + 1);
        eulerLevel[cur] = lev;
        eulerNodes[cur] = u;
        first[u] = min(first[u], cur);
        last[u] = max(last[u], cur);
        cur++;
    }
}
int LG[MAX];
int arr[MAX];
int sTable[MAX][20];
int n = MAX;

void build() {
  LG[0] = -1;
  for (int i = 0; i < n; i++) {
    LG[i + 1] = LG[i] + !(i & (i + 1));
    sTable[i][0] = i;
  }
  for (int j = 1; (1 << j) <= n; j++)
    for (int i = 0; i + (1 << j) <= n; i++) {
      int a = sTable[i][j - 1];
      int b = sTable[i + (1 << (j - 1))][j - 1];
      sTable[i][j] = (eulerLevel[a] < eulerLevel[b] ? a : b);
    }
}

int findMinIdx(int s, int e) {
      int len = e - s + 1;
      int lg = LG[len];
      int a = sTable[s][lg];
      int b = sTable[e - (1 << lg) + 1][lg];
      return (eulerLevel[a] < eulerLevel[b] ? a : b);
}
int getLCA(int u, int v){
    int idx = findMinIdx(min(first[u], first[v]), max(last[u], last[v]));
    return eulerNodes[idx];
}
int solve(int u, int par){
    int re = 0;
    for(auto v : g[u]){
        if(v.first == par)continue;
        int test = 0;
        test = solve(v.first, u);
        re += test;
        res[v.second] += test;
    }
    re += balance[u];
    return re;
}
int main(){

    init();
    scanf("%d", &nodes);
    for(int i = 0; i < nodes - 1; i++){
        cin >> x >> y;
        g[x].push_back(mp(y, i));
        g[y].push_back(mp(x, i));
    }
    dfs(1, -1, 1);
    build();
    int k;
    scanf("%d", &k);
    while(k--){
        scanf("%d%d", &x, &y);
        int lca = getLCA(x, y);
        balance[x] += 1;
        balance[y] += 1;
        balance[lca] -= 2;

    }
    solve(1, -1);
    for(int i = 0; i < nodes - 1; i++){
        printf("%d ", res[i]);
    }
}



