#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int len = 1e5 + 9;
ll n, k, a[len];
bool valid(ll mid){
    ll sum = 0;
    int kk = k, aa = n - 1;
    while(aa >= 0){
        if(aa + 1 == kk){
            while(aa >= 0){
                if(a[aa] > mid)return false;
                aa--;
                kk--;
            }
        }else if(sum + a[aa] <= mid){
            if(sum == 0) kk--;
            sum += a[aa];
            aa--;
        }else if(a[aa] > mid){
             return false;
        }else {
            sum = 0;
        }
    }
    if(kk == 0 && aa == -1){
        return true;
    }else{
         return false;
    }
}
ll binSer(){
    ll be = 0, ed = 10000000000000000, mid , res = -1;
    while(be <= ed){
        mid = (be + ed)/2;
        if(valid(mid)){
            res = mid;
            ed = mid - 1;
        }else {
            be = mid + 1;
        }
    }
    return res;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld", &n, &k);
        for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]);
        }
        ll res = binSer();
        ll sum = 0;
        int kk = k, aa = n - 1;
        vector<vector<int> > num;
        vector<int> test;
        while(aa >= 0){
            if(aa + 1 == kk){
                while(aa >= 0){
                    if(test.size() > 0)num.push_back(test);
                    test.clear();
                    test.push_back(a[aa]);
                    aa--;
                }
            }else if(sum + a[aa] <= res){
                if(sum == 0) kk--;
                sum += a[aa];
                test.push_back(a[aa]);
                aa--;
            }else {
                num.push_back(test);
                test.clear();
                sum = 0;
            }
        }
        if(test.size() > 0)num.push_back(test);
        for(int i = num.size() - 1; i >= 0; i--){
            for(int j = num[i].size() - 1; j >= 0; j--){
                if(j == 0){
                    printf("%d", num[i][j]);
                    }else printf("%d ", num[i][j]);
            }
            if(i == 0){
                printf("\n");
            }else{
                printf(" / ");
            }
        }
    }
}

