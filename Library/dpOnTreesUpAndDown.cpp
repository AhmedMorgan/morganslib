#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
#define MO 998244353

//typedef complex<double> point;
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) 	((b) - (a))
#define polar(r,t) 	((r) * exp(point(0, (t))))
#define angle(v) 	(atan2((v).Y, (v).X))
#define length(v) 	((double)hypot((v).Y, (v).X))
#define lengthSqr(v) 	(dot(v, v))
#define dot(a,b) 	((conj(a) * (b)).real())
#define cross(a,b) 	((conj(a) * (b)).imag())
#define rotate(v,t) 	(polar(v, t))
#define rotateabout(v,t,a)  (rotate(vec(a, v), t) + (a))
#define reflect(p,m) 	((conj((p) / (m))) * (m))
#define normalize(p) 	((p) / length(p))
#define same(a,b) 	(lengthSqr(vec(a, b)) < EPS)
#define mid(a,b)	(((a) + (b)) / point(2, 0))
using namespace std;
const int MAX = 2e5 + 9;
vector<pair<int,int> > g[MAX];
struct node{
    int one, two;
    ll cone = -1e11, ctwo = -1e11 ;
    void insert_(int node, int cost){
        if(cost > ctwo){
            ctwo = cost;
            two = node;
            if(ctwo > cone){
                swap(ctwo, cone);
                swap(one, two);
            }
        }
    }
    ll get_(int node){
        if(node == one)return ctwo;
        else return cone;
    }
};
node dp[MAX];
int id[MAX];
int getId(int x){
    if(id[x] == x)return x;
    return id[x] = getId(id[x]);
}
int merg(int x, int y){
    int one = getId(x);
    int two = getId(y);
    id[one] = two;
}
bool isConnected(int x, int y){
    return getId(x) == getId(y);
}
int t, n, m, x, y, c;
pair<int,pair<int,int> > edges[MAX];
void krusecal(){
    for(int i = 0; i < MAX; i++){
        id[i] = i;
    }
    sort(edges, edges + m);
    for(int i = 0; i < m; i++){
        if(!isConnected(edges[i].S.F, edges[i].S.S)){
            g[edges[i].S.F].pb(mp(edges[i].S.S, edges[i].F));
            g[edges[i].S.S].pb(mp(edges[i].S.F, edges[i].F));
            merg(edges[i].S.F, edges[i].S.S);
        }
    }
}
void dfs1(int u, int p){
    dp[u].insert_(0, 0);
    for(auto v : g[u]){
        int vv = v.F;
        if(vv == p)continue;
        int cc = v.S;
        dfs1(vv, u);
        dp[u].insert_(vv, dp[vv].cone + cc);
    }
}
void dfs2(int u, int p){
    for(auto v : g[u]){
        int vv = v.F;
        if(vv == p)continue;
        int cc = v.S;
        dp[vv].insert_(u, dp[u].get_(vv) + cc);
        dfs2(vv, u);
    }
}
void init(){
    for(int i = 0; i < MAX; i++){
        g[i].clear();
        dp[i].cone = -1e11;
        dp[i].ctwo = -1e11;
    }
}
int main(){
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &edges[i].S.F, &edges[i].S.S, &edges[i].F);
        }
        krusecal();
        cout << "yes" << endl;
        dfs1(1, -1);
        cout << "yes" << endl;
        dfs2(1, -1);
        ll ma = 1e11;
        ll res = 1;
        for(int i = 1; i <= n; i++){
            if(ma > dp[i].cone){
                ma = dp[i].cone;
                res = i;
            }
        }
        printf("%lld %lld\n", res, ma);

    }

}
