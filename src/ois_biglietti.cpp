#include <bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
int N,M,A,B;
    cin>>N>>M>>A>>B;
int ans1,ans2,ans3;
ans1=N*A;
    if(N%M==0)
        ans2=N/M;
    else 
        ans2=N/M+1;
    ans2*=B;
    ans3=(N%M)*A+(N/M)*B;
    cout<<min(ans1,min(ans2,ans3));

    return 0;
}
