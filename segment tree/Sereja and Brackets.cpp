#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
int last = (1 << 10);
string s;
struct segmentTree{
    struct node{
        int ma = 0, open = 0, close = 0;
    };
    node tree[(1 << 10 ) * 2];
    node get_(int l, int r, int now = 1, int be = 1, int ed = last){
        if(be == ed){
            return tree[now];
        }
        if(be >= l && ed <= r){
            return tree[now];
        }
        int mid = (be + ed) / 2;
        node le;
        if(l <= mid) le = get_(l, r, now * 2, be, mid);
        node ri;
        if(r > mid) ri = get_(l, r, now * 2 + 1, mid + 1, ed);
        node res;
        res.ma = le.ma + ri.ma;
        res.ma += min(le.open, ri.close);
        res.close = le.close + ri.close - min(le.open, ri.close);
        res.open = le.open + ri.open - min(le.open, ri.close);
        return res;
    }
    void build(){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                tree[i + last].open = 1;
            }else{
                tree[i + last].close = 1;
            }
        }
        for(int i = last - 1; i > 0; i--){
            tree[i].ma = tree[i * 2].ma + tree[i * 2 + 1].ma + min(tree[i * 2].open, tree[i * 2 + 1].close);
            tree[i].close = tree[i * 2].close + tree[i * 2 + 1].close - min(tree[i * 2].open, tree[i * 2 + 1].close);
            tree[i].open = tree[i * 2].open + tree[i * 2 + 1].open - min(tree[i * 2].open, tree[i * 2 + 1].close);
        }
    }

};
int main(){
    cin >> s;
    int x;
    scanf("%d", &x);
    int a, b;
    segmentTree tre;
    tre.build();
    for(int i = 0; i < x; i++){
        scanf("%d%d", &a, &b);
        printf("%d\n", tre.get_(a, b).ma * 2);
    }
}


