#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
#define oo 1000000
using namespace std;
const int len = 1e5 + 9;
vector<pair<int,int> > g[len];
bool ch[len];
pair<int,int> res[len];
int n, x, y, t, h, m;
void init(){
    for(int i = 0; i < len; i++){
        g[i].clear();
        ch[i] = false;
        res[i] = mp(oo, oo);
    }
}
void dijkstra(){
    priority_queue<pair<pair<int,int> ,int> > q;
    q.push(mp(mp(0, 600), 1));
    // ( ( numOf city, ( days, minuts) ), node)
    while(!q.empty()){
        int numOfcitys = q.top().first.first * -1;
        int minutes = q.top().first.second;
        int u = q.top().second;
        //cout << numOfcitys << " " << days << " " << minutes << " " << u << endl;
        q.pop();
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i].first;
            int co = g[u][i].second;
            if(minutes < co)continue;
            res[v].first = min(res[v].first, numOfcitys);
            if(600 - (minutes - co) < res[v].second){
                res[v].second = 600 - (minutes - co);
                q.push(mp(mp(numOfcitys * -1, minutes - co), v));
            }
            if(ch[v]){
                q.push(mp(mp((numOfcitys + 1) * -1, 600), v));
                ch[v] = false;
            }
        }
    }
}
int main(){
    while(true){
        scanf("%d", &n);
        if(n == 0)break;
        init();
        scanf("%d", &h);
        for(int i = 0; i < h; i++){
            scanf("%d", &x);
            ch[x] = true;
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &x, &y, &t);
            g[x].push_back(mp(y, t));
            g[y].push_back(mp(x, t));
        }
        dijkstra();
        if(res[n].first == oo){
            printf("-1\n");
        }else {
            printf("%d\n", res[n].first);
        }
    }
}
