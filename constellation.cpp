#include <bits/stdc++.h>
#define MAXN 2e5
#define pii pair<int,int>
//#pragma GCC optmize ("O3")
using namespace std;
#define ll long long

vector<vector<int>>x(MAXN);
vector<vector<int>>y(MAXN);

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int n;
    cin>>n;
vector<pii>v(n);
ll ans=0;
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
        x[v[i].first].push_back(v[i].second);
        y[v[i].second].push_back(v[i].first);
    }
    for(int i=0;i<n;i++){
        if(x[v[i].first].size()-1>0 && y[v[i].second].size()-1>0)
            ans+=(x[v[i].first].size()-1)*(y[v[i].second].size()-1);
    }
    cout<<ans;

    return 0;
}