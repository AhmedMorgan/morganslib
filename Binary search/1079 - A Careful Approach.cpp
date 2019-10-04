
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
const int len = 10;
pair<int,int> a[len];
bool valid(double mid){
    double start = a[0].first;
    bool is = false;
    for(int i = 1; i < n; i++){
        if(start + mid >= a[i].first && start + mid <= a[i].second){
            start += mid;
            is = true;
        }else if(start + mid < a[i].first){
            start = a[i].first;
        }else return false;
    }
    return (true&&is);
}
double binSer(){
    double be = 1000000, ed = a[n - 1].second, mid, res;
    for(int i = 1; i < n; i++){
        be = min(be, (double) (a[i].first - a[i - 1].first));
    }
    for(int i = 0; i < n; i++){
        ed = max(ed, (double) (a[i].second));
    }
    for(int i = 0; i < 200; i++){
        mid = (be + ed) / 2;
        if(valid(mid)){
            res = mid;
            be = mid;
        }else {
            ed = mid;
        }
    }
    return res;
}
int main(){
    int cou = 1;
    while(true){
        scanf("%d", &n);
        if(n == 0)break;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &a[i].first, &a[i].second);
        }
        sort(a, a + n);
        double res = binSer();
        printf("Case %d: %d:%d", cou, (int)(res), (int)(ceil( (res - int(res)) * 60.0 )));
        if(res == (int)(res)){
            printf("0\n");
        }else printf("\n");
        cou++;
    }
}

