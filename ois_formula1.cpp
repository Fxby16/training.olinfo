#include <iostream>
#include <vector>
#include <algorithm>
#pragma GCC optimize ("O3")
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define MAXN 2000

int A[MAXN],B[MAXN],C[MAXN];

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
int n;
    cin>>n;
vector<pll>v(n);
    for(int i=0;i<n;i++)
        cin>>A[i]>>B[i]>>C[i];
int q;
    cin>>q;
    while(q--){
        ll k,t;
        cin>>k>>t;
        for(int i=0;i<n;i++)
            v[i]={-(A[i]*t*t+B[i]*t+C[i]),i+1};
        nth_element(v.begin(),v.begin()+k-1,v.end());
        cout<<v[k-1].second<<'\n';
    }

    return 0;
}
