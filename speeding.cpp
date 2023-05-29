#include <iostream>
#include <vector>
#include <algorithm>
#pragma GCC optimize ("O3")
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int n;
    cin>>n;
vector<int>A(n);
vector<int>B(n);
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<n;i++)
        cin>>B[i];
    sort(begin(A),end(A));
    sort(begin(B),end(B));
ll ans=1;
    for(int i=0;i<n;i++){
        int pos=upper_bound(begin(B),end(B),A[i])-begin(B);
        ans=(ans*(pos-i))%MOD;
    }
    cout<<ans;

    return 0;
}