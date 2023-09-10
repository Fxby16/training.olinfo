#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define MOD 666013

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int K,X;
    cin>>K>>X;

vector<ll>pows(X);
    pows[0]=1; //10^0

    for(int i=1;i<X;i++)
        pows[i]=(pows[i-1]*10)%MOD; //get powers of 10 mod MOD

    ll first_pal=(pows[X-1]+1)%MOD; //get first palindrome
    
    ll sum=0;
    for(int k=0;k<K;k++){
        int pos_offset=0; //offset from the middle of the number
        sum=(sum+first_pal)%MOD; //add the first palindrome
        for(int j=k;j>0;j/=10){
            int to_change=j%10; //get the digit to add
            sum=(sum+(to_change*pows[X/2-pos_offset-1])+(to_change*pows[X/2+pos_offset]))%MOD; 
            pos_offset++; //increment the offset from the middle
        }
    }

    cout<<sum<<'\n';

    return 0;
}