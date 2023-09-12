#include <bits/stdc++.h>
using namespace std;

using ll=long long;

bool CheckFinish(bool *digits){
    for(int i=0;i<10;i++)
        if(!digits[i])
            return false;
    return true;
}

void CheckDigits(ll n,bool *digits){
    while(n>0){
        digits[n%10]=true;
        n/=10;
    }
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int N;
    cin>>N;

vector<ll>numbers(N);
vector<int>ans(N,0);
    for(auto &i:numbers)
        cin>>i;
    
    for(int i=0;i<N;i++){
        ll k=numbers[i];
        ll base=k;
        bool digits[10]={false};
        while(true){
            if(CheckFinish(digits))
                break;
            CheckDigits(k,digits);
            ans[i]++;
            k+=base;
        }
    }

    for(auto &i:ans)
        cout<<i<<'\n';

    return 0;
}