#include <bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio("false");
cin.tie(0);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
int n;
    cin>>n;
vector<int>minn;
vector<int>ans(n);
int N=n;
char ch;
    for(int i=0;i<n;i++){
        cin>>ch;
        if(ch=='>')
            ans[i]=N--;
        else
            minn.push_back(i);
    }
    if(ch=='<')
        ans[n-1]=N;
    N=1;
    for(int i=0;i<minn.size();i++){
        ans[minn[i]]=N++;
    }
    if(ch=='>')
        ans[n-1]=N;
    for(auto it:ans)
        cout<<it<<' ';

    return 0;
}