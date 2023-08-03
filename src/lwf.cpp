#include <bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int N,a=1,b=1,temp;
    cin>>N;
vector<int>fibo;
string ans;
    fibo.push_back(1);
    fibo.push_back(INT_MAX);
    while(a<=N)
    {
        temp=a;
        a=a+b;
        b=temp;
        fibo.push_back(a);
    }
    int i=fibo.size()-2;
    while(N>0)
    {
        if(fibo[i]<=N){
            ans+='1';
            N-=fibo[i];
        }
        else
            ans+='0';
        i--;
    }
    while(i>=0){
        ans+='0';
        i--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}