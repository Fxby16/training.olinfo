#include <bits/stdc++.h>
using namespace std;

int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int N,M;
cin>>N>>M;
vector<int>num(N);
vector<int>pos(N);
int n1,n2;
    for(int i=0;i<N;i++){
        num[i]=i;
        pos[i]=i;
    }
    
    for(int i=0;i<M;i++)
    {
        cin>>n1>>n2;
        swap(num[pos[n1]],num[pos[n2]]);
        swap(pos[n1],pos[n2]);
    }
    cout<<num[0];  

    return 0;
}
