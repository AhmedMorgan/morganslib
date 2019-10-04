#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define MOD2 1000000009
#define bas 29
#define bas2 19
using namespace std;
int n;
bool c = false;
vector<vector<pair<double,double>> > s;
pair<double,double> InnerProduct(vector<pair<double,double>> a, vector<pair<double,double> > b){
    pair<double,double> res = mp(0, 0);
    for(int i = 0; i < a.size(); i++){
        res.first += a[i].first * b[i].first + a[i].second * b[i].second;
        res.second -= a[i].first * b[i].second - b[i].first * a[i].second;
    }
    return res;
}
vector<pair<double,double>> ScalerWithVector(double scaler, vector<pair<double,double> > a){
    for(int i = 0; i < a.size(); i++){
        a[i].first *= scaler;
        a[i].second *= scaler;
    }
    return a;
}
double norm(vector<pair<double,double>> v){
    return sqrt(InnerProduct(v, v).first);
}
vector<pair<double,double>> minu(vector<pair<double,double>> a, vector<pair<double,double>> b){
    for(int i = 0; i < a.size(); i++){
        a[i].first -= b[i].first;
        a[i].second -= b[i].second;
    }
    return a;
}
vector<pair<double, double> > multiplyWithComplex(pair<double, double> val, vector<pair<double, double> > a){
    pair<double, double> test;
    for(int i = 0; i < a.size(); i++){
        test = a[i];
        a[i].first = test.first * val.first - test.second * val.second;
        a[i].second = test.first * val.second + test.second * val.first;
    }
    return a;
}
vector<vector<pair<double,double>> > getOrthonormalBasis(vector<vector<pair<double,double> > > a){
    vector<vector<pair<double,double>> > res;
    res.push_back(ScalerWithVector(1/norm(a[0]), a[0]));
    for(int i = 1; i < n; i++){
        vector<pair<double,double>> test = a[i];
        for(int j = 0; j < res.size(); j++){
            test = minu(test, multiplyWithComplex(InnerProduct(a[i], res[j]), res[j]));
        }
        res.push_back(ScalerWithVector(1 / norm(test) ,test));
    }
    return res;
}
string comp;
int main(){
    cout << "please enter the number of vectors in your basis : ";
    cin >> n;
    cout << "if your vectors in Complex type \"yes\" : else type \"no\" : ";

    cin >> comp;
    if(comp == "yes"){
        c = true;
    }
    s.resize(n, vector<pair<double,double>>(n));
    cout << "please enter the " << n << " vector for example if you have 2 vectors (1,1) and (0,0) you should enter them like \n1 1 \n0 0\n";
    cout << "in case of complex enter the vectors like that for example if you have 2 vectors (1+1i, 0+0i) and (2+0i, 3+1i) enter\n1 1 0 0\n2 0 3 1\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> s[i][j].first;
            if(c) cin >> s[i][j].second;
        }
    }
    vector<vector<pair<double,double>> > OrthogonalBasis = getOrthonormalBasis(s);
    for(int i = 0; i < n; i++){
        cout << "the vector number " << i + 1 << " is : (";
        for(int j = 0; j < n; j++){
            cout << OrthogonalBasis[i][j].first << " ";
            if(c) cout << OrthogonalBasis[i][j].second << "i";
            if(j != n - 1)cout << " , ";
        }
        cout << ")";
        cout << endl;
    }
}
