#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;

int last = (1 << 13);
struct segmentTree{
    struct node{
        int value = 0;
        int lazy = -1;
    };
    node tree[1 << 14];


    int insert_(int val, int l, int r, int now = 1, int st = 1, int ed = last){
        if(st == ed){
            tree[now].value = val;
            return val;
        }
        if(st >= l && ed <= r){
            tree[now].lazy = val;
            tree[now].value = val * (ed - st + 1);
            return tree[now].value;
        }
        int mid = (st + ed) / 2;
        if(tree[now].lazy != - 1){
            tree[now * 2].value = (mid - st + 1) * tree[now].lazy;
            tree[now * 2].lazy = tree[now].lazy;
            tree[now * 2 + 1].value = (ed - mid) * tree[now].lazy;
            tree[now * 2 + 1].lazy = tree[now].lazy;
            tree[now].lazy = -1;
        }
        int res = 0;
        if(l <= mid){
            insert_(val, l, r, 2 * now, st, mid);
        }
        if(r > mid){
            insert_(val, l, r, 2 * now + 1, mid + 1, ed);
        }
        tree[now].value = tree[now * 2].value + tree[now * 2 + 1].value;
        return tree[now].value;

    }

    int get_(int l, int r, int now = 1, int st = 1, int ed = last){
        if(st == ed){
            return tree[now].value;
        }
        if(st >= l && ed <= r){
            return tree[now].value;
        }
        int mid = (st + ed) / 2;
        if(tree[now].lazy != -1){
            tree[now * 2].value = (mid - st + 1) * tree[now].lazy;
            tree[now * 2].lazy = tree[now].lazy;
            tree[now * 2 + 1].value = (ed - mid) * tree[now].lazy;
            tree[now * 2 + 1].lazy = tree[now].lazy;
            tree[now].lazy = -1;
        }
        int res = 0;
        if(l <= mid){
            res += get_(l, r, 2 * now, st, mid);
        }
        if(r > mid){
            res += get_(l, r, 2 * now + 1, mid + 1, ed);
        }
        return res;
    }
};
int main(){
    cout << last << endl;
    segmentTree s;
    s.insert_(5, 1, 18);
    cout << "ahlkj" << endl;
    cout << s.get_(17, 18) << endl;
}

/*
    with vectors


    void merge_(int now , int l, int r){
        int one = 0, two = 0;
        while(one < tree[l].v.size() && two < tree[r].v.size()){
            if(tree[l].v[one] <= tree[r].v[two]){
                tree[now].v.push_back(tree[l].v[one]);
                one++;
            }else{
                tree[now].v.push_back(tree[r].v[two]);
                two++;
            }
        }
        while(one < tree[l].v.size()){
            tree[now].v.push_back(tree[l].v[one]);
            one++;
        }
        while(two < tree[r].v.size()){
            tree[now].v.push_back(tree[r].v[two]);
            two++;
        }
    }
    void build(){
        for(int i = last - 1; i > 0; i--){
            merge_(i, 2 * i, 2 * i + 1);
        }
    }

*/
