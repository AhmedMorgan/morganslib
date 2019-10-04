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
int n, m, x1, x2, yy, y2;
string s;
char a[100][100];
int res[100][100];
void dijkstra(){
    priority_queue<pair<int, pair<int,int> > > q;
    q.push(mp(0, mp(x1, yy)));
    while(!q.empty()){
        int seg = q.top().first * -1;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        for(int i = x + 1; i <= n + 1; i++){
            if(a[y][i] == 'X'){
                res[y][i] = min(seg + 1, res[y][i]);
                break;
            }else{
                if(seg + 1 < res[y][i]){
                    res[y][i] = seg + 1;
                    q.push(mp((seg + 1) * -1, mp(i, y)));
                }
            }
        }
        for(int i = x - 1; i >= 0; i--){
            if(a[y][i] == 'X'){
                res[y][i] = min(seg + 1, res[y][i]);
                break;
            }else{
                if(seg + 1 < res[y][i]){
                    res[y][i] = seg + 1;
                    q.push(mp((seg + 1) * -1, mp(i, y)));
                }
            }
        }
        for(int i = y - 1; i >= 0; i--){
            if(a[i][x] == 'X'){
                res[i][x] = min(seg + 1, res[i][x]);
                break;
            }else{
                if(seg + 1 < res[i][x]){
                    res[i][x] = seg + 1;
                    q.push(mp((seg + 1) * -1, mp(x, i)));
                }
            }
        }
        for(int i = y + 1; i <= m + 1; i++){
            if(a[i][x] == 'X'){
                res[i][x] = min(seg + 1, res[i][x]);
                break;
            }else{
                if(seg + 1 < res[i][x]){
                    res[i][x] = seg + 1;
                    q.push(mp((seg + 1) * -1, mp(x, i)));
                }
            }
        }

    }
}
int main(){
   // freopen("in.txt", "r", stdin);
    bool is = false;
    for(int z = 1; ; z++){
        cin >> n >> m;
        if(n == 0)break;
        getline(cin, s);
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                a[i][j] = '.';
            }
        }
        for(int i = 0; i < m; i++){
            getline(cin, s);
            for(int j = 0; j < n; j++){
                a[i + 1][j + 1] = s[j];
            }
        }

        printf("Board #%d:\n", z);
        for(int u = 1; ; u++){
            cin >> x1 >> yy >> x2 >> y2;
             if(x1 == 0){
                break;
            }
            for(int i = 0; i < 100; i++){
                for(int j = 0; j < 100; j++){
                    res[i][j] = oo;
                }
            }
            res[yy][x1] = 0;
            dijkstra();
            if(res[y2][x2] != oo){
                printf("Pair %d: %d segments.\n", u, res[y2][x2]);
            }else{
                printf("Pair %d: impossible.\n", u);
            }
        }
        printf("\n");
    }

}
