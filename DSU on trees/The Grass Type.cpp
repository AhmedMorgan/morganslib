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
int n, x, y;
int a[len];
int sz[len];
ll res = 0;
map<int,int> cnt;
vector<int> *vec[len];
vector<vector<int> > g(len, vector<int>());
int dfsz(int v, int p){
    sz[v] = 1;
    for(auto u : g[v]){
        if(u != p){
            sz[v] += dfsz(u, v);
        }
    }

    return sz[v];
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
    for(auto u : g[v]){
        if(u != p && u != big){
            for(auto x : *vec[u]){
                vec[v]->push_back(x);
                if(a[v] % a[x] == 0){
                    if(cnt.count(a[v] / a[x])){
                        res += cnt[a[v] / a[x]];
                    }
                }
            }
            for(auto x : *vec[u]){
                cnt[a[x]]++;
            }
        }
    }
    res += cnt[1];
    vec[v]->push_back(v);
    cnt[a[v]]++;
    if(!keep){
        for(auto u : *vec[v]){
            cnt[a[u]]--;
        }
    }

}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++){
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    dfsz(1, -1);

    dfs(1, -1, 1);
    printf("%lld", res);
}
