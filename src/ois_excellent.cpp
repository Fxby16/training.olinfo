#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
	
	int N;
	cin>>N;
	
	int sum=N;
	int ctr=0;

	while(sum%3!=0){
		if(ctr==N)
			break;
		sum+=4;
		ctr++;
	}

	if(ctr==N && sum%3!=0){
		cout<<-1;
		return 0;
	}

	for(int i=0;i<ctr;i++){
		cout<<5;
	}
	for(;ctr<N;ctr++){
		cout<<1;
	}

	return 0;
}
