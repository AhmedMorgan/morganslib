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
const int len = 5e1 + 5;
char a[len][len];
int res[len][len][len];
int n, m, sx, sy, ex, ey;
string s;
int slen;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
char test[] = {'D', 'R', 'L', 'U'};
void dijkstra(){
    priority_queue<pair<pair<int,int>, pair<int,int> > > q;
    q.push(mp(mp(0,0), mp(sx, sy)));
    res[sx][sy][0] = 0;
    while(!q.empty()){
        int ind = q.top().first.second * -1;
        int co = q.top().first.first * -1;
        int nx = q.top().second.first;
        int ny = q.top().second.second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int tx = nx + dx[i];
            int ty = ny + dy[i];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m || a[tx][ty] == '#'){
                continue;
            }else {
                if(res[tx][ty][ind] > co + 1){
                    res[tx][ty][ind] = co + 1;
                    q.push(mp(mp((co + 1) * -1, ind * -1), mp(tx, ty)));
                }
            }
        }
        if(ind < slen){
            int tx = nx, ty = ny;
            for(int i = 0; i < 4; i++){
                if(test[i] == s[ind]){
                    tx += dx[i];
                    ty += dy[i];
                    break;
                }
            }
            if(tx < 0 || tx >= n || ty < 0 || ty >= m || a[tx][ty] == '#'){
                if(res[nx][ny][ind + 1] > co){
                    q.push(mp(mp(co * -1, (ind + 1) * -1), mp(nx, ny)));
                    res[nx][ny][ind + 1] = co;
                }
            }else
                if(res[tx][ty][ind + 1] > co){
                    q.push(mp(mp(co * -1, (ind + 1) * -1), mp(tx, ty)));
                    res[tx][ty][ind + 1] = co;
                }
        }

    }
}
int main(){

    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            for(int k = 0; k < len; k++){
                res[i][j][k] = oo;
            }
        }
    }
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'R'){
                sx = i;
                sy = j;
            }else if(a[i][j] == 'E'){
                ex = i;
                ey = j;
            }
        }
    }
    cin >> s;
    slen = s.size();
    dijkstra();
    int mi = oo;
    for(int i = 0; i < len; i++){
        mi = min(mi, res[ex][ey][i]);
    }
    printf("%d", mi);
}
