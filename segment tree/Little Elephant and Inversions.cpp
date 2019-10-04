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
const int len = 1e5 + 9;
int n, cou = 1;;
ll k;
int a[len];
set<int> s;
map<int,int> m;
int last = (1 << 17);
ll finalres = 0;
struct segmentTree{
    struct node{
        ll cou = 0;
    };
    node tre[(1 << 18)];
    void update(int ind, int type, int now = 1, int be = 1, int ed = last){
        if(be == ed){
            tre[now].cou += 1 * type;
            return;
        }
        int mid = (be + ed) / 2;
        if(ind <= mid){
            update(ind, type, now * 2, be, mid);
        }else{
            update(ind, type, now * 2 + 1, mid + 1, ed);
        }
        tre[now].cou = tre[now * 2].cou + tre[now * 2 + 1].cou;
    }
    ll query(int l, int r, int now = 1, int be = 1, int ed = last){
        if(l > r) return 0;
        if(be == ed){
            return tre[now].cou;
        }
        if(be >= l && ed <= r){
            return tre[now].cou;
        }
        int mid = (be + ed)/2;
        ll res = 0;
        if(l <= mid){
            res += query(l, r, now * 2, be, mid);
        }
        if(r > mid){
            res += query(l, r, now * 2 + 1, mid + 1, ed);
        }
        return res;
    }
};
int main(){
    scanf("%d%I64d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        s.insert(a[i]);
    }
    for(set<int>::iterator it = s.begin(); it != s.end(); it++){
        m[*it] = cou++;
    }
    segmentTree le;
    segmentTree ri;
    ll cur = 0;
    int inde;
    le.update(m[a[0]], 1);
    for(int i = 1; i < n; i++){
        inde = m[a[i]];
        cur += ri.query(inde + 1, last);
        if(a[i] < a[0])cur++;
        ri.update(inde, 1);
    }
    if(cur <= k){
        finalres = n;
        finalres *= n - 1;
        finalres /= 2;
        printf("%I64d", finalres);
        return 0;
    }
    int be = 0, ed = 1;
    while(ed < n && be < ed){
        if(cur > k){
            inde = m[a[ed]];
            cur -= ri.query(1, inde - 1);
            cur -= le.query(inde + 1, last);
            ri.update(inde, -1);
            ed++;
        }else{
            finalres += ed - be - 1;
            be++;
            inde = m[a[be]];
            le.update(inde, 1);
            cur += le.query(inde + 1, last);
            cur += ri.query(1, inde - 1);
        }
    }
    ll test = (ed - be);
    finalres += (test )* (test - 1)/ 2;
    ll fin = n;
    fin *= n - 1;
    fin /= 2;
    printf("%I64d", fin - finalres);
}

