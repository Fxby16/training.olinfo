#include <bits/stdc++.h>
using namespace std;

int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
long double R,C,K;
long long ans;
    cin>>R>>C>>K;
    ans=((long long)ceil(R/K))*((long long)ceil(C/K));
    cout<<ans;

    return 0;
}