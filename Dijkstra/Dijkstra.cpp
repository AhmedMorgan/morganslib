#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
#define oo 1000000000
using namespace std;
const int len = 1e5 + 9;
int n, m;
ll x, y, w;
ll res[len];
int to[len];
vector<vector<pair<ll,ll> > > g(len, vector<pair<ll,ll> > ());
priority_queue<pair<ll,ll> > q;
int main(){
    for(int i = 0; i < len; i++){
        res[i] = 1e13;
        to[i] = i;
    }
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%lld%lld%lld", &x, &y, &w);
        g[x].push_back(mp(y, w));
        g[y].push_back(mp(x, w));
    }
    q.push(mp(0, 1));
    while(!q.empty()){
        ll v = q.top().second;
        ll c = q.top().first;
        c *= -1;
        q.pop();
        for(int i = 0; i < g[v].size(); i++){
            if(g[v][i].second + c < res[g[v][i].first]){
                res[g[v][i].first] = g[v][i].second + c;
                q.push(mp((g[v][i].second + c) * -1, g[v][i].first));
                to[g[v][i].first] = v;
            }
        }
    }
    if(res[n] == 1e13){
        printf("-1\n");
        return 0;
    }
    //printf("%lld\n", res[n]);
    vector<int> re;
    re.push_back(n);
    while(true){
        re.push_back(to[re[re.size() - 1]]);
        if(re[re.size() - 1] == 1)break;
    }
    for(int i = re.size() - 1; i >= 0; i--){
        printf("%d ", re[i]);
    }

}
