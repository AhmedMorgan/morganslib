#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, k, t, x, y;
const int len = 4e4 + 9;
vector<int> a[len];
int cumulative[len];
bool valid(int b, int c, int mid){
    if(a[b][mid] <= c)return true;
    else return false;
}
string binSer(int b, int c){
    int sum = (b - 1) * m;
    sum -= cumulative[b - 1];
    int be = 0, ed = (int)a[b].size() - 1, mid, res = -1;
    while(be <= ed){
        mid = (be + ed)/2;
        if(valid(b, c, mid)){
            be = mid + 1;
            res = mid;
        }else {
            ed = mid - 1;
        }
    }
    if(res != -1 && a[b][res] == c)return "Waste";
    sum += c - (res + 1);
    if(sum % 3 == 0)return "Grapes";
    else if(sum % 3 == 1) return "Carrots";
    else return "Kiwis";
}
int main(){
    scanf("%d %d %d %d", &n, &m, &k, &t);
    for(int i = 0; i < k; i++){
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
    }
    for(int i = 0; i < len; i++){
        sort(a[i].begin(), a[i].end());
    }
    for(int i = 1; i < len; i++){
        cumulative[i] = cumulative[i - 1] + a[i].size();
    }
    for(int i = 0; i < t; i++){
        scanf("%d %d", &x, &y);
        string res = binSer(x, y);
        cout << res << endl;
    }

}
