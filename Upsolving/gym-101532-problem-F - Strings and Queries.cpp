#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
int T, n, q;
const int len = 1e4 + 9;
char s[len][50];
int slen[len];
int last = (1 << 8);
struct node{
    int val = -1;
    int idx;
    template <class T> const T& max (const T& a, const T& b) {
  return (a.val<b.val)?b:a;     // or: return comp(a,b)?b:a; for version (2)
}
};
struct segTree{

    node tre[(1 << 9)];
    void inser(int val, int l, int now = 1, int be = 1, int ed = last){
        if(be == ed){
            tre[now].val = val;
            tre[now].idx = be;
            return ;
        }
        int mid = (be + ed) / 2;
        if(mid <= l) inser(val, l, now * 2, be, mid);
        else inser(val, l, now * 2 + 1, mid + 1, ed);
        tre[now].val = max(tre[now * 2].val, tre[now * 2 + 1].val);;
    }
    node get(int l, int r, int now = 1, int be = 1, int ed = last){
        if(be == ed)return tre[now];
        int mid = (be + ed) / 2;
        node res;

        if(l <= mid) res = max(res, get(l, r, now * 2, be, mid));
        if(r > mid) res = max(res, get(l, r, now * 2 + 1, mid + 1, ed));
        return res;
    }

};
int palidromes(int idx){
    int res = 0;
    int now = 0, j;
    for(int i = 0; i < slen[idx]; i++){
        now = 1;
        j = 1;
        while(true){
            if(i - j < 0 || i + j >= slen[idx])break;
            if(s[idx][i - j] != s[idx][i + j])break;
            j++;
            now++;
        }
        res += now;
    }
    for(int i = 0; i < slen[idx] - 1; i++){
        if(s[idx][i] != s[idx][i + 1])continue;
        now = 1;
        j = 1;
        while(true){
            if(i - j < 0 || i + j + 1 >= slen[idx])break;
            if(s[idx][i - j] != s[idx][i + j + 1])break;
            j++;
            now++;
        }
        res += now;
    }
    return res;
}
int main(){
    scanf("%d", &T);
    while(T--){
        segTree tr;
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i++){
            scanf("%s", s[i]);
            slen[i] = strlen(s[i]);
            tr.inser(palidromes(i), i);
        }
        for(int i = 0; i < n; i)
    }
}
