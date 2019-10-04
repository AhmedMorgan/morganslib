#define<bits/stdc++.h>
using namespace std;
const int len = 1e5 + 9;
vector<int> g[len];
vector<int> eulerCircuit;
void euler(int u){
    for(auto v : g[u]){
        if(set.count(mp(u, v))){
            set.erase(mp(u, v));
            set.erase(mp(v, y));
            euler(v);
        }
    }
    eulerCircuit.push_back(u);
}
int main(){

}
