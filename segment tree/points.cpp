#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
#define oo 1000000009
using namespace std;
const int len = 2e5 + 9;
struct query{
    int x, y;
    int type;
};
char z[10];
query input[len];
pair<int,int> points[len * 2];
set<pair<int,int> > s;
map<pair<int, int>, int> ind;
map<int, set<int> > re;
int n, cou = 1;
int last = (1 << 18);
struct segmentTree{
    struct node{
        int y = -oo, x = oo;
    };
    node tre[(1 << 19)];
    void update(int ty, int p, int now = 1, int be = 1, int ed = last){
        if(be == ed){
            if(ty == 1){
                tre[now].y = points[p].second;
            }else{
                tre[now].y = -oo;
            }
            return;
        }
        int mid = (be + ed) / 2;
        if(mid >= p){
            update(ty, p, now * 2, be, mid);
        }else {
            update(ty, p, now * 2 + 1, mid + 1, ed);
        }
        if(tre[now * 2].y > tre[now * 2 + 1].y){
            tre[now] = tre[now * 2];
        }else {
            tre[now] = tre[now * 2 + 1];
        }
    }
    int get_(int x, int y, int now = 1, int be = 1, int ed = last){
        if(tre[now].y <= y){
            return oo;
        }
        if(points[ed].first <= x){
            return oo;
        }
        if(be == ed){
            return tre[now].x;
        }
        int mid = (be + ed) / 2;
        int res = oo;
        int test = get_(x, y, now * 2, be, mid);
        res = min(res, test);
        if(test == oo)
            res = min(res, get_(x, y, now * 2 + 1, mid + 1, ed));
        return res;
    }
    void build(){
        for(int i = 1; i <= n; i++){
            tre[i + last - 1].x = points[i].first;
        }
        for(int i = last - 1; i > 0; i--){
            if(tre[i * 2].y >= tre[i * 2 + 1].y){
                tre[i] = tre[i * 2];
            }else {
                tre[i] = tre[i * 2 + 1];
            }
        }
    }
};

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int xx , yy;
        scanf("%s", z);
        scanf("%d%d", &xx, &yy);
        input[i].x = xx;
        input[i].y = yy;
        if(z[0] == 'a')input[i].type = 1;
        if(z[0] == 'r')input[i].type = 2;
        if(z[0] == 'f')input[i].type = 3;
        s.insert(mp(input[i].x, input[i].y));
    }
    for(set<pair<int,int> >::iterator it = s.begin(); it != s.end(); it++){
        points[cou] = *it;
        ind[(*it)] = cou++;
    }
    for(int i = cou; i < len * 2; i++){
        points[i].first = oo;
    }
    segmentTree tre;
    tre.build();
    for(int i = 0; i < n; i++){
        if(input[i].type == 1){
            tre.update(1, ind[mp(input[i].x, input[i].y)]);
          /*  cout << "--------" << endl;
            for(int j = 1; j < last * 2; j++){
                cout << tre.tre[j].x << " " << tre.tre[j].y << endl;
            }
            cout << "--------" << endl;
           */
            re[input[i].x].insert(input[i].y);
        }else if(input[i].type == 2){
            tre.update(0, ind[mp(input[i].x, input[i].y)]);

           /* cout << "--------" << endl;
            for(int j = 1; j < last * 2; j++){
                cout << tre.tre[j].x << " " << tre.tre[j].y << endl;
            }
            cout << "--------" << endl;*/
            re[input[i].x].erase(input[i].y);
        }else {
            int x = tre.get_(input[i].x, input[i].y);
            if(x == oo){
                cout << -1 << endl;
            }else {
                printf("%d %d\n", x, *re[x].upper_bound(input[i].y));
            }
        }
    }
}



