#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;
using ll=long long;

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
    ll N,K;
    cin>>N>>K;

    ll sum=0;  
    vector<ll>P(N);

    for(int i=0;i<N;i++){
        cin>>P[i];
        sum+=P[i];
    }
    
    ll required_sum=K*N;
    int ctr=0;

    if(required_sum==sum){
        cout<<"0\n";
    }else if(sum<required_sum){
        cout<<"1\n";
    }else{
        sort(begin(P),end(P));
    	for(int i=N-1;i>=0;i--){
		ll temp=min((sum-required_sum),P[i]-1);
    		sum-=temp;
    		if(temp==0)
    		    break;
    		ctr++;
    	}
    	cout<<ctr<<'\n';
    }

    return 0;
}
