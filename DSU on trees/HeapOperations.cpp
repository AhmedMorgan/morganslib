#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
int n;
priority_queue<int> q;
const int inf = 1e9 + 9;
int main() {
    cin >> n;
    string s;
    int x = 0;
    vector<pair<string, int> > res;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == "insert" || s == "getMin"){
            cin >> x;
        }
        if(s == "insert"){
            q.push(x * -1);
            res.push_back(mp(s, x));
        }else if( s == "getMin"){
            while(!q.empty() && q.top() > x * -1){
                q.pop();
                res.push_back(mp("removeMin", -1 * inf));
            }

             if(!q.empty() && q.top() == x * -1) {
                res.push_back(mp("getMin", x));
            }else {
                res.push_back(mp("insert", x));
                q.push(x * -1);
                res.push_back(mp("getMin", x));
            }
        }else {
            if(q.empty()){
                res.push_back(mp("insert", x));
                res.push_back(mp("removeMin", -1 * inf));
            }else {
                  res.push_back(mp("removeMin", -1 * inf));
                  q.pop();
            }
        }

    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i].first;
        if(res[i].second != -1 * inf){
            cout << " " << res[i].second << endl;
        }else {
            cout << endl;
        }
    }
}

