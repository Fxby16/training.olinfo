#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

int N;
    cin>>N;
vector<int>v(N);
int somma=0; 
int ans=0;  
    for(int i=0;i<N;i++){
        cin>>v[i];
        somma+=v[i];
    }
    sort(v.begin(),v.end());
    int k=0;
    while(!(somma>0))
    {
        somma+=(v[k++]*-2);
        ans++;
        if(k>=N)
            break;
    }
    cout<<ans;

    return 0;
}