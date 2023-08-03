#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
Esempio:

Input:
6
3 2 2 6 2 3
--------------------------------------------------------------------------------------------------------
3 2 4 8 6 9 0       nel primo vettore salvo la somma minima senza l'elemento i-1 + l'elemento i
0 3 2 4 8 6 0       nel secondo vettore salvo la somma minima fino a i-2 per poterla riutilizzare dopo
--------------------------------------------------------------------------------------------------------
Output:
6

*/

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<int> dp1(n+1);
    vector<int> dp2(n+1);
    dp1[0]=v[0];
    dp2[0]=0;
    for(int i=1;i<n;i++) {
        dp1[i]=v[i]+min(dp1[i-1],dp2[i-1]);
        dp2[i]=dp1[i-1];
    }

    cout<<min(dp1[n-1],dp2[n-1])<<"\n";

    return 0;
}