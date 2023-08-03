#include <iostream>
#include <vector>
#pragma GCC optimize ("O3")
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int N,Q;
    cin>>N>>Q;
vector<int>v(N);
vector<int>v2(N);
vector<int>count(N);
int ans=0;
    for(int i=0;i<N;i++){
        cin>>v[i];
        --v[i];
        v2[v[i]]=i;
    }
    while(Q--){
        int n;
        cin>>n;
        --n;
        int temp=v[v2[n]-1];
        ++count[temp];
        if((count[temp]>count[ans]) || (count[temp]==count[ans] && temp<ans))
            ans=temp;
        swap(v2[n],v2[temp]);
        swap(v[v2[n]],v[v2[temp]]);
        cout<<ans+1<<'\n';
    }

    return 0;
}